#include <criterion/criterion.h>

#include "../src/stack.h"
#include "../src/dyn_arr.h"

decl_dyn_arr_type(int);
decl_stack_type(int);

Test(stack, should_properly_enqueue_new_data) {
  int_s_t s = new_int_stack();
  push_int_s(&s, 1);
  push_int_s(&s, 2);
  push_int_s(&s, 3);
  push_int_s(&s, 4);
  cr_expect(*peek_int_s(s) == 4);
  cr_expect(s.arr[0] == 1);
  cr_expect(s.arr[1] == 2);
  cr_expect(s.arr[2] == 3);
  cr_expect(s.arr[3] == 4);
}

Test(stack, should_return_NULL_when_peeking_empty_stack) {
  int_s_t s = new_int_stack();
  cr_expect(peek_int_s(s) == NULL);
}

Test(stack, should_properly_pop_data) {
  int_s_t s = new_int_stack();
  push_int_s(&s, 1);
  push_int_s(&s, 2);
  push_int_s(&s, 3);
  push_int_s(&s, 4);
  int res = pop_int_s(&s);
  cr_expect(res == 4);
  cr_expect(*peek_int_s(s) == 3);
}
