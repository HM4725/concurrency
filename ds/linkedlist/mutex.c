#include <stdlib.h>
#include <pthread.h>
#include "linkedlist.h"

// Queue functions
void list_add(int key, long tid){
    node_t *new = malloc(sizeof(node_t));
    new->key = key;
    new->tid = tid;
    new->next = 0;
    pthread_mutex_lock(&L->lock);
    L->tail->next = new;
    L->tail = new;
    pthread_mutex_unlock(&L->lock);
}
node_t* list_del(){
    node_t* head;
    node_t* target;

    head = L->head;
    pthread_mutex_lock(&L->lock);
    if(target = head->next){
        head->next = target->next;
        target->next = NULL;
    }
    pthread_mutex_unlock(&L->lock);

    return target;
}

// Global count functions
int inc_gcnt(){
    int cnt;
    pthread_mutex_lock(&L->lock);
    cnt = ++gcnt;
    pthread_mutex_unlock(&L->lock);
    return cnt;
}

void dec_gcnt(){
    pthread_mutex_lock(&L->lock);
    gcnt--;
    pthread_mutex_unlock(&L->lock);
}
