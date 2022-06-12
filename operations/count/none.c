#include <stdlib.h>
#include "count.h"

struct __counter_t {
  word_t value;
};

counter_t* init(){
  counter_t* c;
  c = malloc(sizeof(struct __counter_t));
  c->value = 0;
  return c;
}

void increment(counter_t *c){
  c->value++;
}

void decrement(counter_t *c){
  c->value--;
}

word_t get(counter_t *c){
  return c->value;
}

void destroy(counter_t *c){
  free(c);
}
