#include <criterion/criterion.h>

#include "../src/dyn_arr.h"

bool same_func(const int el1, const int el2) { return el1 == el2; }

decl_dyn_arr_type(int);

Test(dyn_arr, should_push_data_to_dyn_arr) {
  int_dyn_arr_t dyn_arr = new_int_dyn_arr(16);
  push_int(&dyn_arr, 1);
  push_int(&dyn_arr, 2);
  cr_expect(dyn_arr.len == 2);
  cr_expect(dyn_arr.arr[0] == 1);
  cr_expect(dyn_arr.arr[1] == 2);
}


Test(dyn_arr, should_check_if_element_is_present_in_arr) {
  int_dyn_arr_t dyn_arr = new_int_dyn_arr(16);
  push_int(&dyn_arr, 1);
  push_int(&dyn_arr, 2);
  push_int(&dyn_arr, 3);
  push_int(&dyn_arr, 2);
  cr_expect(includes_int(dyn_arr, 3, same_func) == true);
  cr_expect(includes_int(dyn_arr, 5, same_func) == false);
}
