#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct Node {
  void *data;
  struct Node *left;
  struct Node *right;
} Node_bt;

typedef Node_bt Binary_tree;

Binary_tree *new_bt();
void traverse_pre_order(Binary_tree *bt);
void traverse_in_order(Binary_tree *bt);
void traverse_post_order(Binary_tree *bt);
