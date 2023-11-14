#include <criterion/criterion.h>

#include "../src/binary_tree.h"

Binary_tree *test_tree_1() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  root->data = data1;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data3;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data4;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data5;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data6;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data7;
  root->right->right->left = NULL;
  root->right->right->right = NULL;
  return root;
}

Binary_tree *test_tree_2() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 8;
  root->data = data1;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data3;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data4;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data5;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data6;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data7;
  root->right->right->left = NULL;
  root->right->right->right = NULL;
  return root;
}

Binary_tree *test_tree_3() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  root->data = data1;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data3;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data4;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data5;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data6;
  root->right->left->left = malloc(sizeof(Node_bt));
  root->right->left->left->data = data7;
  root->right->left->left->left = NULL;
  root->right->left->left->right = NULL;
  root->right->left->right = NULL;
  root->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data6;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data5;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data7;
  root->right->right->left = NULL;
  root->right->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_for_delete_data_6_left() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data6;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data5;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_for_delete_data_6_right() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data6;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = NULL;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data7;
  root->right->right->left = NULL;
  root->right->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_insertion_data_5() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data6;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data5;
  root->right->left->left = malloc(sizeof(Node_bt));
  root->right->left->left->data = data5;
  root->right->left->right = NULL;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data7;
  root->right->right->left = NULL;
  root->right->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_deletion_data_7() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data6;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data5;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_deletion_data_6_left() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data5;
  root->right->right = NULL;
  root->right->left = NULL;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_deletion_data_6_right() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data7;
  root->right->right = NULL;
  root->right->left = NULL;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_deletion_data_6() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data5;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = NULL;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data7;
  root->right->right->left = NULL;
  root->right->right->right = NULL;
  return root;
}

Binary_tree *test_search_tree_for_delete_data_8() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  int *data8 = malloc(sizeof(int));
  *data8 = 8;
  int *data9 = malloc(sizeof(int));
  *data9 = 9;
  int *data10 = malloc(sizeof(int));
  *data10 = 10;
  int *data11 = malloc(sizeof(int));
  *data11 = 11;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data8;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data6;
  root->right->left->left = malloc(sizeof(Node_bt));
  root->right->left->left->left = NULL;
  root->right->left->left->right = NULL;
  root->right->left->left->data = data5;
  root->right->left->right = malloc(sizeof(Node_bt));
  root->right->left->right->left = NULL;
  root->right->left->right->right = NULL;
  root->right->left->right->data = data7;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data10;
  root->right->right->left = malloc(sizeof(Node_bt));
  root->right->right->left->left = NULL;
  root->right->right->left->right = NULL;
  root->right->right->left->data = data9;
  root->right->right->right = malloc(sizeof(Node_bt));
  root->right->right->right->left = NULL;
  root->right->right->right->right = NULL;
  root->right->right->right->data = data11;
  return root;
}

Binary_tree *test_search_tree_deletion_data_8() {
  Binary_tree *root = malloc(sizeof(Binary_tree));
  int *data1 = malloc(sizeof(int));
  *data1 = 1;
  int *data2 = malloc(sizeof(int));
  *data2 = 2;
  int *data3 = malloc(sizeof(int));
  *data3 = 3;
  int *data4 = malloc(sizeof(int));
  *data4 = 4;
  int *data5 = malloc(sizeof(int));
  *data5 = 5;
  int *data6 = malloc(sizeof(int));
  *data6 = 6;
  int *data7 = malloc(sizeof(int));
  *data7 = 7;
  int *data9 = malloc(sizeof(int));
  *data9 = 9;
  int *data10 = malloc(sizeof(int));
  *data10 = 10;
  int *data11 = malloc(sizeof(int));
  *data11 = 11;
  root->data = data4;
  root->left = malloc(sizeof(Node_bt));
  root->left->data = data2;
  root->right = malloc(sizeof(Node_bt));
  root->right->data = data7;
  root->left->left = malloc(sizeof(Node_bt));
  root->left->left->data = data1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right = malloc(sizeof(Node_bt));
  root->left->right->data = data3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  root->right->left = malloc(sizeof(Node_bt));
  root->right->left->data = data6;
  root->right->left->left = malloc(sizeof(Node_bt));
  root->right->left->left->left = NULL;
  root->right->left->left->right = NULL;
  root->right->left->left->data = data5;
  root->right->left->right = NULL;
  root->right->right = malloc(sizeof(Node_bt));
  root->right->right->data = data10;
  root->right->right->left = malloc(sizeof(Node_bt));
  root->right->right->left->left = NULL;
  root->right->right->left->right = NULL;
  root->right->right->left->data = data9;
  root->right->right->right = malloc(sizeof(Node_bt));
  root->right->right->right->left = NULL;
  root->right->right->right->right = NULL;
  root->right->right->right->data = data11;
  return root;
}

Test(binary_tree, should_traverse_depth_first) {
  depth_first_traversal(test_tree_1());
}

Test(binary_tree, should_traverse_breadth_first) {
  breadth_first_traversal(test_tree_1());
}

Test(binary_tree, should_compare_two_indentical_trees) {
  cr_expect(int_compare_binary_trees(test_tree_1(), test_tree_1()) == 1);
}

Test(binary_tree, should_compare_two_trees_different_in_values) {
  cr_expect(int_compare_binary_trees(test_tree_1(), test_tree_2()) == 0);
}

Test(binary_tree, should_compare_two_trees_different_in_structure) {
  cr_expect(int_compare_binary_trees(test_tree_1(), test_tree_3()) == 0);
}

Test(binary_search_tree, should_return_one_if_value_present) {
  cr_expect(int_find_in_search_tree(test_search_tree(), 1) == 1);
}

Test(binary_search_tree, should_return_zero_if_value_not_present) {
  cr_expect(int_find_in_search_tree(test_search_tree(), 8) == 0);
}

Test(binary_search_tree, should_insert_properly) {
  Binary_tree *bt = test_search_tree();
  int res = int_insert_in_search_tree(bt, 5);
  cr_expect(res != -1);
  cr_expect(int_compare_binary_trees(bt, test_search_tree_insertion_data_5()) ==
            1);
}

Test(binary_search_tree, should_insert_properly_to_empty_tree) {
  Binary_tree *bt = malloc(sizeof(Binary_tree));
  bt->data = NULL;
  int res = int_insert_in_search_tree(bt, 5);
  cr_expect(res != -1);
  cr_expect(bt != NULL);
  cr_expect(*(int *)bt->data == 5);
}

Test(binary_search_tree, should_return_error_for_null_binary_tree_root) {
  Binary_tree *bt = NULL;
  int res = int_insert_in_search_tree(bt, 5);
  cr_expect(res == -1);
}

Test(binary_search_tree, should_handle_delete_for_null_tree) {
  Binary_tree *bt = NULL;
  int_delete_in_search_tree(bt, 7);
}

Test(binary_search_tree, should_delete_node_with_no_children) {
  Binary_tree *bt = test_search_tree();
  int_delete_in_search_tree(bt, 7);
  cr_expect(int_compare_binary_trees(bt, test_search_tree_deletion_data_7()) ==
            1);
}

Test(binary_search_tree, should_delete_node_with_one_left_child) {
  Binary_tree *bt = test_search_tree_for_delete_data_6_left();
  int_delete_in_search_tree(bt, 6);
  cr_expect(int_compare_binary_trees(bt, test_search_tree_deletion_data_6_left()) ==
            1);
}

Test(binary_search_tree, should_delete_node_with_one_right_child) {
  Binary_tree *bt = test_search_tree_for_delete_data_6_right();
  int_delete_in_search_tree(bt, 6);
  cr_expect(int_compare_binary_trees(bt, test_search_tree_deletion_data_6_right()) ==
            1);
}

Test(binary_search_tree, should_delete_node_with_two_children) {
  Binary_tree *bt = test_search_tree();
  int_delete_in_search_tree(bt, 6);
  cr_expect(int_compare_binary_trees(bt, test_search_tree_deletion_data_6()) ==
            1);
}

Test(binary_search_tree, should_delete_node_with_two_children_2) {
  Binary_tree *bt = test_search_tree_for_delete_data_8();
  int_delete_in_search_tree(bt, 8);
  cr_expect(int_compare_binary_trees(bt, test_search_tree_deletion_data_8()) ==
            1);
}
