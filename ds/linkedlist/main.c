#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "linkedlist.h"

// List initialize
void list_init(){
    L = malloc(sizeof(list_t));
    // Dummy head node
    node_t *head = malloc(sizeof(node_t));
    head->key = 0;
    head->next = NULL;
    L->head = head;
    L->tail = head;
#ifdef MUTEX
    pthread_mutex_init(&L->lock, NULL);
#endif
}

// Thread Kernels
void nop(){ }
void* enqer(void *arg){
    int i = 0;
    int cnt;
    long tid = (long)arg;

    while(i++ < QUOTA){
        asm volatile("call %P0"::"i"(nop)); // delay
        cnt = inc_gcnt(&gcnt);
        list_add(cnt, tid);
    }
    return 0;
}
void* deqer(void *arg){
    node_t *n;
    node_t *head;

    while((n = list_del()) != NULL){
        dec_gcnt(&gcnt);
        free(n);
    }
    return 0;
}

// Globals
int gcnt = 0;
list_t *L = 0;

// Main
int main(){
    pthread_t p_thread[THNUM];
    node_t *itr;
    int status;
    long i;

    list_init();

    // 1. Concurrent Enqueue Routine
    printf("1. enque start\n");
    for(i = 0; i < THNUM; i++)
        pthread_create(&p_thread[i], NULL, enqer, (void *)i);
    for(i = 0; i < THNUM; i++)
        pthread_join(p_thread[i], (void *) &status);
    printf("1. enque end\n");

    printf("  head: [%ld] %d\n", L->head->next->tid, L->head->next->key);
    printf("  tail: [%ld] %d\n", L->tail->tid, L->tail->key);

    for(itr = L->head->next, i = 0; itr != 0; itr = itr->next, i++);
    printf("  total: %ld\n", i);
    printf("  gcnt: %d\n", gcnt);

    // 2. Concurrent Dequeue Routine
    printf("\n2. deque start\n");
    for(i = 0; i < THNUM; i++)
        pthread_create(&p_thread[i], NULL, deqer, (void *)i);
    for(i = 0; i < THNUM; i++)
        pthread_join(p_thread[i], (void *) &status);
    printf("2. deque end\n");

    for(itr = L->head->next, i = 0; itr != 0; itr = itr->next, i++);
    printf("  total: %ld\n", i);
    printf("  gcnt: %d\n", gcnt);
    return 0;
}
