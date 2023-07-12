#include <criterion/criterion.h>
#include <stdlib.h>

#include "../src/sort.h"

Test(bubble_sort, should_work_with_empty_array) {
  int arr[0] = {};
  cr_expect(bubble_sort(arr, 0) == arr);
}

Test(bubble_sort, should_work_with_inverted_array) {
  int len = 10;
  int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  bubble_sort(arr, len);
  cr_expect(arr[0] == 0);
  cr_expect(arr[5] == 5);
  cr_expect(arr[9] == 9);
}

int test_cmp_func(const void *a, const void *b) {
  if (*(int *)a < *(int *)b)
    return -1;
  if (*(int *)a > *(int *)b)
    return 1;
  return 0;
}

Test(quick_sort, should_work_with_empty_array) {
  void *arr = malloc(0);
  quick_sort(arr, 0, 0, arr);
}

Test(quick_sort, should_work_with_inverted_array) {
  size_t len = 10;
  int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  quick_sort(arr, len, sizeof(int), test_cmp_func);
  cr_expect(arr[0] == 0);
  cr_expect(arr[5] == 5);
  cr_expect(arr[9] == 9);
}
