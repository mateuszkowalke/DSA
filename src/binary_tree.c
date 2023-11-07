#include "binary_tree.h"
#include <stdio.h>

void depth_first_traversal(Binary_tree *bt) {
  printf("%d ", *(int *)bt->data);
  if (bt->left != NULL) {
    depth_first_traversal(bt->left);
  }
  if (bt->right != NULL) {
    depth_first_traversal(bt->right);
  }
  printf("\n");
}

void breadth_first_traversal(Binary_tree *bt) {
  int res;
  Queue *q = new_queue();
  if ((res = enqueue(q, bt)) == -1) {
    printf("error");
  }
  void *n;
  while (dequeue(q, &n) != -1) {
    printf("%d ", *(int *)((Node_bt *)n)->data);
    if (((Node_bt *)n)->left != NULL) {
      // TODO error
      enqueue(q, ((Node_bt *)n)->left);
    }
    if (((Node_bt *)n)->right != NULL) {
      // TODO error
      enqueue(q, ((Node_bt *)n)->right);
    }
  }
  printf("\n");
}

int int_compare_binary_trees(Binary_tree *bt1, Binary_tree *bt2) {
  if (*(int *)bt1->data != *(int *)bt2->data) {
    return 0;
  }
  int res = 1;
  if (bt1->left != NULL) {
    if (bt2->left == NULL) {
      return 0;
    }
    res = int_compare_binary_trees(bt1->left, bt2->left);
  }
  if (res == 0) {
    return res;
  }
  if (bt1->right != NULL) {
    if (bt2->right == NULL) {
      return 0;
    }
    res = int_compare_binary_trees(bt1->right, bt2->right);
  }
  return res;
}
