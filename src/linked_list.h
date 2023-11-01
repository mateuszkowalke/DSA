#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
  void *data;
  struct Node *next;
} Node_ll;

typedef struct {
  size_t size;
  Node_ll *head;
  Node_ll *tail;
} Linked_list;

Linked_list *new_ll();
int insert_at_ll(Linked_list *ll, void *data, size_t i);
int append_ll(Linked_list *ll, void *data);
int prepend_ll(Linked_list *ll, void *data);
int remove_ll(Linked_list *ll, Node_ll *node);
int remove_at_ll(Linked_list *ll, size_t i);
void *get(Linked_list *ll, size_t i);
