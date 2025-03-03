#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

double rand_range(double min, double max) {
  int raw = rand();
  double proportion = (double)raw / (double)RAND_MAX;
  return min + proportion * (max - min);
}

int main(int argc, char *argv[]) {

  long long in_circle = 0;
  long long N = 1024 * 1024 * 4;

  double start = omp_get_wtime();

  for (int i = 0; i < N; i++) {
    double x = rand_range(-1, 1);
    double y = rand_range(-1, 1);
    double distance = x * x + y * y;
    if (distance <= 1)
      in_circle++;
  }

  double end = omp_get_wtime();

  double pi = 4 * (double)in_circle / N;

  printf("Result: %lf\n", pi);
  printf("Time: %lf\n", end - start);

  return 0;
}
