#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "count.h"

#define NTHRD (1000)
#define REP (100000)

counter_t *c;

void* worker(void *arg) {
  for(word_t i = 0; i < REP; i++)
    increment(c, arg);
  return 0;
}

int main(void) {
  pthread_t thrd[NTHRD] = {0};
  word_t status;
  word_t expect = NTHRD * REP;
  clock_t start, end;

  c = init((void*)NTHRD);

  start = clock();
  for(word_t i = 0; i < NTHRD; i++)
    pthread_create(&thrd[i], NULL, worker, (void*)i);

  for(word_t i = 0; i < NTHRD; i++){
    pthread_join(thrd[i], (void**)&status);
  }
  end = clock();

  printf("Expect : %ld\n", expect);
  printf("Result : %ld\n", get(c));
  printf("Correct: %s\n", expect == get(c) ? "yes" : "no");
  printf("Time   : %lfs\n", (double)(end - start)/CLOCKS_PER_SEC);

  destroy(c);
  return 0;
}
