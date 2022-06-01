#include <stdlib.h>
#include "linkedlist.h"

// Queue functions
void list_add(int key, long tid){
    node_t *new = malloc(sizeof(node_t));
    new->key = key;
    new->tid = tid;
    new->next = 0;
    L->tail->next = new;
    L->tail = new;
}
node_t* list_del(){
    node_t* head;
    node_t* target;

    head = L->head;
    if(target = head->next){
        head->next = target->next;
        target->next = NULL;
    }

    return target;
}

// Global count functions
int inc_gcnt(){
    return ++gcnt;
}
void dec_gcnt(){
    --gcnt;
}
