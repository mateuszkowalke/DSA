#include "binary_tree.h"
#include <stdio.h>

void depth_first_traversal(Binary_tree *bt) {
  printf("%s\n", (char *)bt->data);
  if (bt->left != NULL) {
    depth_first_traversal(bt->left);
  }
  if (bt->right != NULL) {
    depth_first_traversal(bt->right);
  }
}

void breadth_first_traversal(Binary_tree *bt) {
    int res;
    Queue *q = new_queue();
    if ((res = enqueue(q, bt)) == -1) {
        printf("error");
    }
    void *n;
    while(dequeue(q, &n) != -1) {
        printf("%s\n", (char *)((Node_bt *)n)->data);
        if (((Node_bt *)n)->left != NULL) {
            // TODO error
            enqueue(q, ((Node_bt *)n)->left);
        }
        if (((Node_bt *)n)->right != NULL) {
            // TODO error
            enqueue(q, ((Node_bt *)n)->right);
        }
    }
}
