#include <stdlib.h>
#include <pthread.h>
#include "count.h"

struct __counter_t {
  word_t value;
  pthread_mutex_t lock;
};

counter_t* init(void *arg){
  counter_t *c;
  c = malloc(sizeof(struct __counter_t));
  c->value = 0;
  pthread_mutex_init(&c->lock, NULL);
  return c;
}

void increment(counter_t *c, void *arg){
  pthread_mutex_lock(&c->lock);
  c->value++;
  pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t *c, void *arg){
  pthread_mutex_lock(&c->lock);
  c->value--;
  pthread_mutex_unlock(&c->lock);
}

word_t get(counter_t *c){
  word_t value;
  pthread_mutex_lock(&c->lock);
  value = c->value;
  pthread_mutex_unlock(&c->lock);
  return value;
}

void destroy(counter_t *c){
  pthread_mutex_destroy(&c->lock);
  free(c);
}
