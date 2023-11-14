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

// 1 for identical, 0 for not
int int_compare_binary_trees(Binary_tree *bt1, Binary_tree *bt2) {
  if (bt1 == NULL && bt2 == NULL) {
    return 1;
  }
  if (bt1 == NULL || bt2 == NULL) {
    return 0;
  }
  if (*(int *)bt1->data != *(int *)bt2->data) {
    return 0;
  }
  return int_compare_binary_trees(bt1->left, bt2->left) &&
         int_compare_binary_trees(bt1->right, bt2->right);
}

int int_find_in_search_tree(Binary_tree *bt, int v) {
  if (bt == NULL) {
    return 0;
  }
  int curr = *(int *)bt->data;
  if (curr == v) {
    return 1;
  }
  if (curr < v) {
    return int_find_in_search_tree(bt->right, v);
  }
  return int_find_in_search_tree(bt->left, v);
}

// returns -1 for failure
int int_insert_in_search_tree(Binary_tree *bt, int v) {
  if (bt == NULL) {
    return -1;
  }
  // empty tree
  if (bt->data == NULL) {
    if ((bt->data = malloc(sizeof(int))) == NULL) {
      return -1;
    }
    // this is based on assumption, that node with no data
    // cannot have children - setting pointer to NULL for good measure
    bt->left = NULL;
    bt->right = NULL;
    *(int *)bt->data = v;
    return 0;
  }
  int curr = *(int *)bt->data;
  if (curr < v) {
    if (bt->right == NULL) {
      if ((bt->right = malloc(sizeof(Binary_tree))) == NULL) {
        return -1;
      }
      if ((bt->right->data = malloc(sizeof(int))) == NULL) {
        return -1;
      }
      bt->right->left = NULL;
      bt->right->right = NULL;
      *(int *)bt->right->data = v;
      return 0;
    }
    return int_insert_in_search_tree(bt->right, v);
  }
  if (bt->left == NULL) {
    if ((bt->left = malloc(sizeof(Binary_tree))) == NULL) {
      return -1;
    }
    if ((bt->left->data = malloc(sizeof(int))) == NULL) {
      return -1;
    }
    bt->left->left = NULL;
    bt->left->right = NULL;
    *(int *)bt->left->data = v;
    return 0;
  }
  return int_insert_in_search_tree(bt->left, v);
}

int int_check_child(Binary_tree *parent, Binary_tree *to_remove, int isleft,
                    int v) {
  if (to_remove == NULL) {
    return 0;
  }
  int curr = *(int *)to_remove->data;
  if (curr == v) {
    if (to_remove->left == NULL && to_remove->right == NULL) {
      if (isleft) {
        free(parent->left);
        parent->left = NULL;
      } else {
        free(parent->right);
        parent->right = NULL;
      }
      return 1;
    }
    // TODO
    // more tests
    // refactor
    // balancing
    if (to_remove->left != NULL && to_remove->right != NULL) {
      if (to_remove->left->left == NULL && to_remove->left->right == NULL) {
        to_remove->left->right = to_remove->right;
        if (isleft) {
          parent->left = to_remove->left;
        } else {
          parent->right = to_remove->left;
        }
        free(to_remove);
        return 1;
      }
      Binary_tree *biggest_on_left = to_remove->left;
      Binary_tree *biggest_on_left_parent = to_remove;
      while (biggest_on_left->right != NULL) {
        biggest_on_left_parent = biggest_on_left;
        biggest_on_left = biggest_on_left->right;
      }
      if (biggest_on_left->left != NULL) {
        biggest_on_left_parent->right = biggest_on_left->left;
      } else {
        biggest_on_left_parent->right = NULL;
      }
      biggest_on_left->left =
          to_remove->left == biggest_on_left->left ? NULL : to_remove->left;
      biggest_on_left->right = to_remove->right;
      if (isleft) {
        parent->left = biggest_on_left;
      } else {
        parent->right = biggest_on_left;
      }
      free(to_remove);
      return 1;
    }
    if (to_remove->left != NULL) {
      Binary_tree *tmp = to_remove;
      if (isleft) {
        parent->left = to_remove->left;
      } else {
        parent->right = to_remove->left;
      }
      free(tmp);
      return 1;
    }
    if (to_remove->right != NULL) {
      Binary_tree *tmp = to_remove;
      if (isleft) {
        parent->left = to_remove->right;
      } else {
        parent->right = to_remove->right;
      }
      free(tmp);
      return 1;
    }
  }
  return 0;
}

void int_delete_in_search_tree(Binary_tree *bt, int v) {
  if (bt == NULL) {
    return;
  }
  // TODO
  // looking for root
  if (int_check_child(bt, bt->left, 1, v) ||
      int_check_child(bt, bt->right, 0, v)) {
    return;
  }
  int curr = *(int *)bt->data;
  if (curr < v) {
    int_delete_in_search_tree(bt->right, v);
  } else if (curr > v) {
    int_delete_in_search_tree(bt->left, v);
  }
}
