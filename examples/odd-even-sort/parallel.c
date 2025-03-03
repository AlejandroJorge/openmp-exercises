#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1024 * 20

void swap(int *a, int *b) {
  int tmp = *a;
  a = b;
  *b = tmp;
}

int is_sorted(int *arr) {
  for (int i = 1; i < N; i++)
    if (arr[i - 1] > arr[i])
      return 0;
  return 1;
}

int main(int argc, char *argv[]) {

  int arr[N];
  for (int i = 0; i < N; i++)
    arr[i] = rand();

  long thread_count = strtol(argv[1], NULL, 10);

  double start = omp_get_wtime();
#pragma omp parallel num_threads(thread_count) default(none) shared(arr)
  for (int phase = 0; phase < N; phase++) {
    if (phase % 2 == 0) {
#pragma omp for
      for (int i = 1; i < N; i += 2)
        if (arr[i - 1] > arr[i])
          swap(&arr[i - 1], &arr[i]);
    } else {
#pragma omp for
      for (int i = 1; i < N - 1; i += 2)
        if (arr[i] > arr[i + 1])
          swap(&arr[i], &arr[i + 1]);
    }
  }
  double end = omp_get_wtime();

  int res = is_sorted(arr);
  double time = end - start;

  printf("Result: %d\n", res);
  printf("Time: %lf\n", time);

  return 0;
}
