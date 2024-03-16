#include <criterion/criterion.h>

#include "../src/linked_list.h"

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

Test(singly_linked_list,
     should_properly_remove_node_at_the_beginning_by_value) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 2);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int res = int_remove_sll(&sll, 2);
  cr_expect(res != -1);
  cr_expect(sll.size == 4);
  cr_expect(sll.head->data == 1);
}

Test(singly_linked_list, should_properly_remove_node_at_the_end_by_value) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 2);
  int res = int_remove_sll(&sll, 2);
  cr_expect(res != -1);
  cr_expect(sll.size == 4);
  cr_expect(sll.tail->data == 1);
}

Test(singly_linked_list, should_properly_remove_node_in_the_middle_by_value) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 2);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int res = int_remove_sll(&sll, 2);
  cr_expect(res != -1);
  cr_expect(sll.size == 4);
  cr_expect(sll.head->next->next->data == 1);
  cr_expect(sll.head->next->next->next->data == 1);
}

Test(singly_linked_list,
     should_properly_remove_node_at_the_beginning_by_index) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 2);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int res = int_remove_at_sll(&sll, 0);
  cr_expect(res != -1);
  cr_expect(sll.size == 4);
  cr_expect(sll.head->data == 1);
}

Test(singly_linked_list, should_properly_remove_node_at_the_end_by_index) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 2);
  int res = int_remove_at_sll(&sll, 4);
  cr_expect(res != -1);
  cr_expect(sll.size == 4);
  cr_expect(sll.tail->data == 1);
}

Test(singly_linked_list, should_properly_remove_node_in_the_middle_by_index) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 2);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int res = int_remove_at_sll(&sll, 2);
  cr_expect(res != -1);
  cr_expect(sll.size == 4);
  cr_expect(sll.head->next->next->data == 1);
  cr_expect(sll.head->next->next->next->data == 1);
}

Test(singly_linked_list, should_properly_get_node_by_index) {
  int_sll_t sll = new_int_sll();
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 2);
  int_append_sll(&sll, 1);
  int_append_sll(&sll, 1);
  int res = int_get_at_sll(sll, 2);
  cr_expect(res == 2);
}

decl_doubly_linked_list_type(int);

Test(doubly_linked_list, should_create_new_doubly_linked_list) {
  int_dll_t dll = new_int_dll();
  cr_expect(dll.size == 0);
  cr_expect(dll.head == NULL);
  cr_expect(dll.tail == NULL);
}

Test(doubly_linked_list, should_properly_insert_new_data) {
  int_dll_t dll = new_int_dll();
  int_insert_at_dll(&dll, 0, 0);
  int_insert_at_dll(&dll, 1, 1);
  int_insert_at_dll(&dll, 2, 2);
  int_insert_at_dll(&dll, 3, 3);
  cr_expect(dll.size == 4);
  cr_expect(dll.head->data == 0);
  cr_expect(dll.tail->data == 3);
}

Test(doubly_linked_list, should_properly_append_new_data) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  cr_expect(dll.size == 1);
  cr_expect(dll.head->data == 1);
  int_append_dll(&dll, 2);
  cr_expect(dll.size == 2);
  cr_expect(dll.head->data == 1);
  cr_expect(dll.head->next->data == 2);
}

Test(doubly_linked_list, should_properly_prepend_new_data) {
  int_dll_t dll = new_int_dll();
  int_prepend_dll(&dll, 1);
  cr_expect(dll.size == 1);
  cr_expect(dll.head->data == 1);
  int_prepend_dll(&dll, 2);
  cr_expect(dll.size == 2);
  cr_expect(dll.head->data == 2);
  cr_expect(dll.head->next->data == 1);
}

Test(doubly_linked_list,
     should_properly_remove_node_at_the_beginning_by_value) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int res = int_remove_dll(&dll, 2);
  cr_expect(res != -1);
  cr_expect(dll.size == 4);
  cr_expect(dll.head->data == 1);
}

Test(doubly_linked_list, should_properly_remove_node_at_the_end_by_value) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int res = int_remove_dll(&dll, 2);
  cr_expect(res != -1);
  cr_expect(dll.size == 4);
  cr_expect(dll.tail->data == 1);
}

Test(doubly_linked_list, should_properly_remove_node_in_the_middle_by_value) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int res = int_remove_dll(&dll, 2);
  cr_expect(res != -1);
  cr_expect(dll.size == 4);
  cr_expect(dll.head->next->next->data == 1);
  cr_expect(dll.head->next->next->next->data == 1);
}

Test(doubly_linked_list,
     should_properly_remove_node_at_the_beginning_by_index) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int res = int_remove_at_dll(&dll, 0);
  cr_expect(res != -1);
  cr_expect(dll.size == 4);
  cr_expect(dll.head->data == 1);
}

Test(doubly_linked_list, should_properly_remove_node_at_the_end_by_index) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int res = int_remove_at_dll(&dll, 4);
  cr_expect(res != -1);
  cr_expect(dll.size == 4);
  cr_expect(dll.tail->data == 1);
}

Test(doubly_linked_list, should_properly_remove_node_in_the_middle_by_index) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int res = int_remove_at_dll(&dll, 2);
  cr_expect(res != -1);
  cr_expect(dll.size == 4);
  cr_expect(dll.head->next->next->data == 1);
  cr_expect(dll.head->next->next->next->data == 1);
}

Test(doubly_linked_list, should_properly_get_node_by_index) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 1);
  int res = int_get_at_dll(dll, 2);
  cr_expect(res == 2);
}

Test(doubly_linked_list, should_swap_nodes_when_one_is_head) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.head, dll.head->next->next);
  cr_expect(dll.head->data == 3);
  cr_expect(dll.head->next->next->data == 1);
}

Test(doubly_linked_list, should_swap_neighboring_nodes_when_one_is_head) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.head, dll.head->next);
  cr_expect(dll.head->data == 2);
  cr_expect(dll.head->next->data == 1);
}

Test(doubly_linked_list, should_swap_nodes_when_one_is_head_and_args_inverted) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.head->next->next, dll.head);
  cr_expect(dll.head->data == 3);
  cr_expect(dll.head->next->next->data == 1);
}

Test(doubly_linked_list, should_swap_nodes_when_one_is_tail) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.tail, dll.tail->prev->prev);
  cr_expect(dll.tail->data == 3);
  cr_expect(dll.tail->prev->prev->data == 5);
}

Test(doubly_linked_list, should_swap_neighboring_nodes_when_one_is_tail) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.tail, dll.tail->prev);
  cr_expect(dll.tail->data == 4);
  cr_expect(dll.tail->prev->data == 5);
}

Test(doubly_linked_list, should_swap_nodes_when_one_is_head_and_other_tail) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.head, dll.tail);
  cr_expect(dll.head->data == 5);
  cr_expect(dll.tail->data == 1);
}

Test(doubly_linked_list,
     should_swap_nodes_when_one_is_head_and_other_tail_for_2_node_list) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_swap_dll(&dll, dll.head, dll.tail);
  cr_expect(dll.head->data == 2);
  cr_expect(dll.tail->data == 1);
  cr_expect(dll.head->next == dll.tail);
  cr_expect(dll.tail->prev == dll.head);
}

Test(doubly_linked_list,
     should_swap_nodes_when_one_is_head_and_other_tail_when_args_inverted) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.tail, dll.head);
  cr_expect(dll.head->data == 5);
  cr_expect(dll.tail->data == 1);
}

Test(
    doubly_linked_list,
    should_swap_nodes_when_one_is_head_and_other_tail_for_2_node_list_when_args_inverted) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_swap_dll(&dll, dll.tail, dll.head);
  cr_expect(dll.head->data == 2);
  cr_expect(dll.tail->data == 1);
  cr_expect(dll.head->next == dll.tail);
  cr_expect(dll.tail->prev == dll.head);
}

Test(doubly_linked_list,
     should_swap_non_head_and_non_tail_nodes) {
  int_dll_t dll = new_int_dll();
  int_append_dll(&dll, 1);
  int_append_dll(&dll, 2);
  int_append_dll(&dll, 3);
  int_append_dll(&dll, 4);
  int_append_dll(&dll, 5);
  int_swap_dll(&dll, dll.tail->prev, dll.head->next);
  cr_expect(dll.head->next->data == 4);
  cr_expect(dll.tail->prev->data == 2);
}

