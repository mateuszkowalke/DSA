#include "binary_tree.h"

void traverse_pre_order(Binary_tree *bt) {
  printf("%s\n", (char *)bt->data);
  if (bt->left != NULL) {
    traverse_pre_order(bt->left);
  }
  if (bt->right != NULL) {
    traverse_pre_order(bt->right);
  }
}
void traverse_in_order(Binary_tree *bt);
void traverse_post_order(Binary_tree *bt);
