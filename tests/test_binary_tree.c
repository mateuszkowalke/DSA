#include <criterion/criterion.h>

#include "../src/binary_tree.h"

Test(binary_tree, should_traverse_depth_first) {
    Binary_tree *root = malloc(sizeof(Binary_tree));
    char *data1 = "U";
    root->data = data1;
    root->left = NULL;
    root->right = NULL;
    depth_first_traversal(root);
}
