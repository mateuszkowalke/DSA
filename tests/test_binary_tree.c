#include <criterion/criterion.h>

#include "../src/binary_tree.h"

Test(binary_tree, should_traverse_pre_order) {
    Binary_tree *root = malloc(sizeof(Binary_tree));
    traverse_pre_order(root);
}
