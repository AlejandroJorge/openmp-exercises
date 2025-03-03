#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1024

int main(int argc, char *argv[]) {

  double pi = 0.0;
  double factor = 1.0;

  long thread_count = strtol(argv[1], NULL, 10);

  double start_time = omp_get_wtime();

#pragma omp parallel for reduction(+ : pi)                                     \
    num_threads(thread_count) private(factor)
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      factor = 1.0;
    else
      factor = -1.0;
    pi += factor / (2 * i + 1);
  }

  double time = omp_get_wtime() - start_time;

  pi *= 4;
  printf("Result: %lf\n", pi);
  printf("Time: %lf\n", time);

  return 0;
}
