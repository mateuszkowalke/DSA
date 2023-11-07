#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "queue.h"

typedef struct Node_bt {
  void *data;
  struct Node_bt *left;
  struct Node_bt *right;
} Node_bt;

typedef Node_bt Binary_tree;

Binary_tree *new_bt();
void depth_first_traversal(Binary_tree *bt);
void breadth_first_traversal(Binary_tree *bt);
