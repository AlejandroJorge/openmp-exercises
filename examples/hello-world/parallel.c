#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void Hello(void);

int main(int argc, char *argv[]) {

  int tc = strtol(argv[1], NULL, 10);

#pragma omp parallel num_threads(tc)
  Hello();

  return 0;
}

void Hello(void) {
  int my_rank = omp_get_thread_num();
  int tc = omp_get_num_threads();

  printf("Hello from thread %d of %d\n", my_rank, tc);
}
