#include <criterion/criterion.h>
#include <stdio.h>

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
