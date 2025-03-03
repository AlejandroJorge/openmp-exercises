#include <omp.h>
#include <stdio.h>
#define N 1024

int main(int argc, char *argv[]) {

  double pi = 0.0;
  double factor = 1.0;

  double start_time = omp_get_wtime();

  for (int i = 0; i < N; i++) {
    pi += factor / (2 * i + 1);
    factor *= -1;
  }

  double time = omp_get_wtime() - start_time;

  pi *= 4;
  printf("Result: %lf\n", pi);
  printf("Time: %lf\n", time);

  return 0;
}
