#include <criterion/criterion.h>

#include "../src/stack.h"

Test(stack, should_properly_enqueue_new_data) {
  Node n3 = {3, NULL};
  Node n2 = {2, &n3};
  Node n1 = {1, &n2};
  Stack s = {&n1};
  push(&s, 4);
  cr_expect(s.top->data == 4);
}

Test(stack, should_return_NULL_if_no_nodes_in_stack) {
  Stack s = {NULL};
  Node * res = pop(&s);
  cr_expect(res == NULL);
}

Test(stack, should_properly_pop_data) {
  Node n4 = {4, NULL};
  Node n3 = {3, &n4};
  Node n2 = {2, &n3};
  Node n1 = {1, &n2};
  Stack s = {&n1};
  Node* res = pop(&s);
  cr_expect(res->data == 1);
  cr_expect(s.top->data == 2);
}

Test(stack, should_allow_to_peek_data_from_top) {
  Node n4 = {4, NULL};
  Node n3 = {3, &n4};
  Node n2 = {2, &n3};
  Node n1 = {1, &n2};
  Stack s = {&n1};
  int res = peek_stack(&s);
  cr_expect(res == 1);
  cr_expect(s.top->data == 1);
}

Test(stack, should_return_negative_one_if_trying_to_peek_empty_stack) {
  Stack s = {NULL};
  int res = peek_stack(&s);
  cr_expect(res == -1);
}
