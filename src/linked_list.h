#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct {
  size_t size;
  Node *head;
  Node *tail;
} Linked_list;

Linked_list *new_ll();
int insert_at_ll(Linked_list *ll, void *data, size_t i);
int append_ll(Linked_list *ll, void *data);
int prepend_ll(Linked_list *ll, void *data);
int remove_ll(Linked_list *ll, Node *node);
int remove_at_ll(Linked_list *ll, size_t i);
void *get(Linked_list *ll, size_t i);
