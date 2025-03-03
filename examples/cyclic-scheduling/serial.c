#include <math.h>
#include <omp.h>
#include <stdio.h>
#define N 1024 * 8

// Function which computation costs grows with it's input numeric value
double f(int i) {
  int start = i * (i + 1) / 2;
  int finish = start + i;
  double return_val = 0.0;

  for (int j = start; j <= finish; j++) {
    return_val += sin(j);
  }
  return return_val;
}

int main(int argc, char *argv[]) {

  double sum = 0.0;

  double start = omp_get_wtime();

  for (int i = 0; i < N; i++) {
    sum += f(i);
  }

  double time = omp_get_wtime() - start;

  printf("Res: %lf\n", sum);
  printf("Time: %lf\n", time);

  return 0;
}
