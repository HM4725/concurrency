#include <stdlib.h>
#include "linkedlist.h"

// Atomic Instructions
static inline node_t*
test_and_set(node_t **addr, node_t *newval){
    node_t *result;
    asm volatile("lock; xchgq %0, %1" 
      : "+m" (*addr), "=a" (result)
      : "1" (newval)
      : "cc");
    return result;
}
static inline char
compare_and_swap(node_t** addr, node_t *old, node_t *new)
{
    unsigned char result;
    asm volatile ("lock; cmpxchgq %2,%1\n"
      " sete %0\n"
      : "=q" (result), "=m" (*addr)
      : "r" (new), "m" (*addr), "a" (old)
      : "memory");
    return result;
}
static inline int
fetch_and_add(int* variable, int value){
    asm volatile("lock; xaddl %0, %1"
      : "+r" (value), "+m" (*variable) // input + output
      : // No input-only
      : "memory"
    );
    return value;
}

// Queue functions
void list_add(int key, long tid){
    node_t *new = malloc(sizeof(node_t));
    new->key = key;
    new->tid = tid;
    new->next = 0;
    test_and_set(&L->tail, new)->next = new;
}
node_t* list_del(){
    node_t* head;
    node_t* target;
    char result;

    head = L->head;
    while((target = head->next) != NULL){
        if(compare_and_swap(&head->next, target, target->next) > 0)
            break;
    }
    return target;
}

// Global count functions
int inc_gcnt(){
    return fetch_and_add(&gcnt, 1) + 1;
}
void dec_gcnt(){
    fetch_and_add(&gcnt, -1);
}
