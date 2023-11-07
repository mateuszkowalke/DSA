#include "binary_tree.h"

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
    Queue *q = malloc(sizeof(Queue));
    enqueue(q, bt);
    /* Node_bt *n; */
    /* while((n = dequeue(q)) != NULL) { */
    /*  */
    /* } */
}
