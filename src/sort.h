#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int *bubble_sort(int *arr, int len);
void quick_sort(void *arr, int size, int el_size,
                int (*cmp_func)(const void *a, const void *b));
