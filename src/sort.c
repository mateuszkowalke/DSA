#include "sort.h"

int *bubble_sort(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return arr;
}

void swap(void *a, void *b, size_t el_size) {
  void *tmp = malloc(el_size);
  memcpy(tmp, a, el_size);
  memcpy(a, b, el_size);
  memcpy(b, tmp, el_size);
  free(tmp);
}

void quick_sort(void *arr, int size, int el_size,
                int (*cmp_func)(const void *a, const void *b)) {
  // base case
  if (size < 2) {
    return;
  }

  // simple case
  if (size == 2) {
    if (cmp_func(arr, arr + el_size) > 0)
      swap(arr, arr + el_size, el_size);
  }

  // recursive case
  // using last arr element as pivot, so no need to swap elements
  int pivot_i = size - 1;
  int last_i = -1;
  int next_i = 0;
  while (next_i < pivot_i) {
    if (cmp_func(arr + next_i * el_size, arr + pivot_i * el_size) < 0) {
      last_i++;
      swap(arr + next_i * el_size, arr + last_i * el_size, el_size);
    }
    next_i++;
  }
  last_i++;
  swap(arr + last_i * el_size, arr + pivot_i * el_size, el_size);
  quick_sort(arr, last_i, el_size, cmp_func);
  quick_sort(arr + (last_i + 1) * el_size, size - (last_i + 1), el_size, cmp_func);
}
