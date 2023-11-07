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
