#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1024
#define MIN -1000.0
#define MAX 1000.0

// Some function
double f(double x) { return 1; }

int main(int argc, char *argv[]) {

  long n_threads = strtol(argv[1], NULL, 10);

  double start = omp_get_wtime();

  double area = 0.0;

  double partition_len = (MAX - MIN) / N;

#pragma omp parallel for reduction(+ : area) num_threads(n_threads)
  for (int i = 0; i < N; i++) {
    double left = MIN + i * partition_len;
    double right = left + partition_len;
    double h = (f(left) + f(right)) / 2.0;

    area += h;
  }

  area *= partition_len;

  double end = omp_get_wtime();

  double time = end - start;

  printf("From %lf to %lf the area is %lf\n", MIN, MAX, area);
  printf("Time: %lf\n", time);

  return 0;
}
