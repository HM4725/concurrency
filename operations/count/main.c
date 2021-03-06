#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "count.h"

#ifndef NTHRD
#define NTHRD (2)
#endif
#define REP (100000000)

counter_t *c;

void* worker(void *arg) {
  word_t quota = REP / NTHRD;
  for(word_t i = 0; i < quota; i++)
    increment(c, arg);
  return 0;
}

int main(void) {
  pthread_t thrd[NTHRD] = {0};
  word_t status;
  word_t expect = REP;
  clock_t start, end;

  c = init((void*)NTHRD);

  start = clock();
  for(word_t i = 0; i < NTHRD; i++)
    pthread_create(&thrd[i], NULL, worker, (void*)i);

  for(word_t i = 0; i < NTHRD; i++){
    pthread_join(thrd[i], (void**)&status);
  }
  end = clock();

  printf("Result : %ld\n", get(c));
  printf("Expect : %ld\n", expect);
  printf("Time   : %lfs\n", (double)(end - start)/CLOCKS_PER_SEC);

  destroy(c);
  return 0;
}
