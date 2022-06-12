#include <stdio.h>
#include <pthread.h>
#include "count.h"

#define NTHRD 1000
#define REP 100000

counter_t *c;

void* worker(void *arg) {
  for(int i = 0; i < REP; i++)
    increment(c);
  return 0;
}

int main(void) {
  pthread_t thrd[NTHRD] = {0};
  long status;
  word_t expect = NTHRD * REP;

  c = init();

  for(int i = 0; i < NTHRD; i++)
    pthread_create(&thrd[i], NULL, worker, (void*)0);

  for(int i = 0; i < NTHRD; i++){
    pthread_join(thrd[i], (void**)&status);
  }

  printf("Expect: %ld\n", expect);
  printf("Result: %ld\n", get(c));
  printf("Correct: %s\n", expect == get(c) ? "yes" : "no");

  destroy(c);
  return 0;
}
