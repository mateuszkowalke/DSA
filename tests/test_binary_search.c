#include <criterion/criterion.h>

#include "../src/binary_search.h"

// these tests assume array of unique integers
Test(binary_search, should_return_negative_one_if_array_is_empty) {
  int arr[0] = {};
  cr_expect(binary_search(1, arr, 0) == -1);
}

Test(binary_search, should_return_negative_one_if_element_not_in_array) {
  int len = 10;
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cr_expect(binary_search(20, arr, len) == -1);
}

Test(binary_search, should_return_index_of_element_serched_for) {
  int len = 20;
  int arr[20] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
                 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  cr_expect(binary_search(19, arr, len) == 19);
  cr_expect(binary_search(5, arr, len) == 5);
  cr_expect(binary_search(2, arr, len) == 2);
  cr_expect(binary_search(0, arr, len) == 0);
}
