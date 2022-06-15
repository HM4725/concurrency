#include <stdlib.h>
#include <pthread.h>
#include "count.h"

#define THRESHOLD 5

struct __counter_t {
  word_t global;
  pthread_mutex_t glock;
  word_t *local;
  pthread_mutex_t *llock;
  word_t threshold;
  word_t nthrd;
};

counter_t* init(void* arg){
  counter_t* c;
  word_t nthrd = (word_t)arg;
  c = malloc(sizeof(struct __counter_t));
  c->global = 0;
  pthread_mutex_init(&c->glock, NULL);
  c->nthrd = nthrd;
  c->local = malloc(sizeof(word_t)*nthrd);
  c->llock = malloc(sizeof(pthread_mutex_t)*nthrd);
  for(word_t i = 0; i < nthrd; i++){
    c->local[i] = 0;
    pthread_mutex_init(&c->llock[i], NULL);
  }
  c->threshold = THRESHOLD;
  return c;
}

void increment(counter_t *c, void* arg){
  word_t id = (word_t)arg;
  pthread_mutex_lock(&c->llock[id]);
  c->local[id] += 1;
  if(c->local[id] >= c->threshold){
    pthread_mutex_lock(&c->glock);
    c->global += c->local[id];
    pthread_mutex_unlock(&c->glock);
    c->local[id] = 0;
  }
  pthread_mutex_unlock(&c->llock[id]);
}

void decrement(counter_t *c, void* arg){
  word_t id = (word_t)arg;
  pthread_mutex_lock(&c->llock[id]);
  c->local[id] -= 1;
  if(-(c->local[id]) >= c->threshold){
    pthread_mutex_lock(&c->glock);
    c->global -= c->local[id];
    pthread_mutex_unlock(&c->glock);
    c->local[id] = 0;
  }
  pthread_mutex_unlock(&c->llock[id]);
}

word_t get(counter_t *c){
  word_t value;
  pthread_mutex_lock(&c->glock);
  value = c->global;
  pthread_mutex_unlock(&c->glock);
  return value;
}

void destroy(counter_t *c){
  for(word_t i = 0; i < c->nthrd; i++){
    pthread_mutex_destroy(&c->llock[i]);
  }
  free(c->llock);
  free(c->local);
  pthread_mutex_destroy(&c->glock);
  free(c);
}
