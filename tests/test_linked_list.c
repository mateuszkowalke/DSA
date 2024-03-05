#include <criterion/criterion.h>

#include "../src/linked_list.h"

Test(linked_list, should_properly_append_new_data) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  int res = append_ll(ll, (void *)&data1);
  cr_expect(res != -1);
  cr_expect(ll->size == 1);
  cr_expect(*(int *)ll->head->data == 1);
  res = append_ll(ll, (void *)&data2);
  cr_expect(res != -1);
  cr_expect(ll->size == 2);
  cr_expect(*(int *)ll->head->data == 1);
  cr_expect(*(int *)ll->head->next->data == 2);
}

Test(linked_list, should_properly_prepend_new_data) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  int res = prepend_ll(ll, (void *)&data1);
  cr_expect(res != -1);
  cr_expect(ll->size == 1);
  cr_expect(*(int *)ll->head->data == 1);
  res = prepend_ll(ll, (void *)&data2);
  cr_expect(res != -1);
  cr_expect(ll->size == 2);
  cr_expect(*(int *)ll->head->data == 2);
}

Test(linked_list, should_properly_insert_new_data) {
  Linked_list *ll = new_ll();
  int data = 90;
  int res = append_ll(ll, (void *)&data);
  cr_expect(res != -1);
  res = append_ll(ll, (void *)&data);
  cr_expect(res != -1);
  res = append_ll(ll, (void *)&data);
  cr_expect(res != -1);
  res = append_ll(ll, (void *)&data);
  cr_expect(res != -1);
  res = append_ll(ll, (void *)&data);
  cr_expect(res != -1);
  cr_expect(ll->size == 5);
  int data2 = 10;
  res = insert_at_ll(ll, (void *)&data2, 2);
  cr_expect(res != -1);
  cr_expect(ll->size == 6);
  cr_expect(*(int *)ll->head->next->next->data == data2);
}

Test(linked_list, should_properly_remove_node_at_the_beginning_by_value) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  append_ll(ll, (void *)&data2);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  Node_ll *node = malloc(sizeof(Node_ll));
  node->data = (void *)&data2;
  int res = remove_ll(ll, node);
  cr_expect(res != -1);
  cr_expect(ll->size == 4);
  cr_expect(*(int *)ll->head->data == data1);
}

Test(linked_list, should_properly_remove_node_at_the_end_by_value) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data2);
  Node_ll *node = malloc(sizeof(Node_ll));
  node->data = (void *)&data2;
  int res = remove_ll(ll, node);
  cr_expect(res != -1);
  cr_expect(ll->size == 4);
  cr_expect(*(int *)ll->tail->data == data1);
}

Test(linked_list, should_properly_remove_node_in_the_middle_by_value) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data2);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  Node_ll *node = malloc(sizeof(Node_ll));
  node->data = (void *)&data2;
  int res = remove_ll(ll, node);
  cr_expect(res != -1);
  cr_expect(ll->size == 4);
  cr_expect(*(int *)ll->head->next->data == data1);
  cr_expect(*(int *)ll->head->next->next->data == data1);
}

Test(linked_list, should_properly_remove_node_at_the_beginning_by_index) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  append_ll(ll, (void *)&data2);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  Node_ll *node = malloc(sizeof(Node_ll));
  node->data = (void *)&data2;
  int res = remove_at_ll(ll, 0);
  cr_expect(res != -1);
  cr_expect(ll->size == 4);
  cr_expect(*(int *)ll->head->data == data1);
}

Test(linked_list, should_properly_remove_node_at_the_end_by_index) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data2);
  Node_ll *node = malloc(sizeof(Node_ll));
  node->data = (void *)&data2;
  int res = remove_at_ll(ll, 4);
  cr_expect(res != -1);
  cr_expect(ll->size == 4);
  cr_expect(*(int *)ll->tail->data == data1);
}

Test(linked_list, should_properly_remove_node_in_the_middle_by_index) {
  Linked_list *ll = new_ll();
  int data1 = 1;
  int data2 = 2;
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data2);
  append_ll(ll, (void *)&data1);
  append_ll(ll, (void *)&data1);
  Node_ll *node = malloc(sizeof(Node_ll));
  node->data = (void *)&data2;
  int res = remove_at_ll(ll, 2);
  cr_expect(res != -1);
  cr_expect(ll->size == 4);
  cr_expect(*(int *)ll->head->next->data == data1);
  cr_expect(*(int *)ll->head->next->next->data == data1);
}

decl_singly_linked_list_type(int);

Test(singly_linked_list, should_create_new_singly_linked_list) {
  int_sll_t sll = new_int_sll();
  cr_expect(sll.size == 0);
  cr_expect(sll.head == NULL);
  cr_expect(sll.tail == NULL);
}

Test(singly_linked_list, should_properly_insert_new_data) {
  int_sll_t sll = new_int_sll();
  int_insert_at_sll(&sll, 0, 0);
  int_insert_at_sll(&sll, 1, 1);
  int_insert_at_sll(&sll, 2, 2);
  int_insert_at_sll(&sll, 3, 3);
  cr_expect(sll.size == 4);
  cr_expect(sll.head->data == 0);
  cr_expect(sll.tail->data == 3);
}

Test(singly_linked_list, should_properly_append_new_data) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 1);
  cr_expect(sll.size == 1);
  cr_expect(sll.head->data == 1);
  int_append_sll(&sll, 2);
  cr_expect(sll.size == 2);
  cr_expect(sll.head->data == 1);
  cr_expect(sll.head->next->data == 2);
}

Test(singly_linked_list, should_properly_prepend_new_data) {
  int_sll_t sll = new_int_sll();
  int_prepend_sll(&sll, 1);
  cr_expect(sll.size == 1);
  cr_expect(sll.head->data == 1);
  int_prepend_sll(&sll, 2);
  cr_expect(sll.size == 2);
  cr_expect(sll.head->data == 2);
  cr_expect(sll.head->next->data == 1);
}

