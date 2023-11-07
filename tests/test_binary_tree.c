#include <criterion/criterion.h>

#include "../src/binary_tree.h"

Test(binary_tree, should_traverse_depth_first) {
    Binary_tree *root = malloc(sizeof(Binary_tree));
    char *data1 = "U";
    char *data2 = "P";
    char *data3 = "D";
    char *data4 = "A";
    char *data5 = "T";
    char *data6 = "E";
    char *data7 = "!";
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
    depth_first_traversal(root);
}

Test(binary_tree, should_traverse_breadth_first) {
    Binary_tree *root = malloc(sizeof(Binary_tree));
    char *data1 = "1";
    char *data2 = "2";
    char *data3 = "3";
    char *data4 = "4";
    char *data5 = "5";
    char *data6 = "6";
    char *data7 = "7";
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
    breadth_first_traversal(root);
}
