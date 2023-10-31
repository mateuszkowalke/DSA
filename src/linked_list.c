#include "linked_list.h"

Linked_list *new_ll() {
  Linked_list *ll = malloc(sizeof(Linked_list));
  ll->head = ll->tail = NULL;
  ll->size = 0;
  return ll;
}

// returns prev node for the one specified by index
// in case index == 0 it returns node with NULL data
// in case of getting out of linked list bounds returns NULL
// this works on assumption, that valid node always has non-NULL data!!!!!!
Node *get_prev_at(Linked_list *ll, size_t i) {
  if (ll->size <= i || ll->size == 0) {
    return NULL;
  }
  if (i == 0) {
      Node *prev = malloc(sizeof(Node));
      prev->data = NULL;
      prev->next = ll->head;
      return prev;
  }
  Node *curr = ll->head;
  Node *prev = NULL;
  for (; curr != NULL && i > 0; i--) {
    prev = curr;
    curr = curr->next;
  }
  return prev;
}

// attaches new node at specified index
// allows only to attach at existing indices
// prepends the new node to the one currently at specified index
// TODO
// parameterize to allow postpending
// returns -1 for failure and 0 for success
int insert_at_ll(Linked_list *ll, void *data, size_t i) {
  // this makes sure we won't try to insert beyond linked list's
  // bounds, so NULL checks in the for loop are redundant
  if (i >= ll->size) {
    return -1;
  }
  Node *new = malloc(sizeof(Node));
  if (new == NULL) {
    return -1;
  }
  new->data = data;
  Node *prev = get_prev_at(ll, i);
  if (prev == NULL) {
      return -1;
  } 
  ll->size++;
  if (prev->data == NULL) {
      new->next = ll->head;
      ll->head = new;
  } else if (prev->next->next == NULL) {
      ll->tail->next = new;
      ll->tail = new;
  } else {
      new->next = prev->next->next;
      prev->next = new;
  }
  return 0;
}

// attaches new node at the end of linked list
// returns -1 for failure and 0 for success
int append_ll(Linked_list *ll, void *data) {
  Node *new = malloc(sizeof(Node));
  if (new == NULL) {
    return -1;
  }
  new->data = data;
  new->next = NULL;
  if (ll->head == NULL) {
    ll->head = ll->tail = new;
  } else {
    ll->tail->next = new;
    ll->tail = new;
  }
  ll->size++;
  return 0;
}

// prepends new node to the beginning of linked list
// returns -1 for failure and 0 for success
int prepend_ll(Linked_list *ll, void *data) {
  Node *new = malloc(sizeof(Node));
  if (new == NULL) {
    return -1;
  }
  new->data = data;
  if (ll->head == NULL) {
    new->next = NULL;
    ll->head = ll->tail = new;
  } else {
    new->next = ll->head;
    ll->head = new;
  }
  ll->size++;
  return 0;
}

// removes node with the same data from linked list
// returns -1 for failure and 0 for success
int remove_ll(Linked_list *ll, Node *node) {
  if (ll->head == NULL) {
    return -1;
  }
  Node *curr = ll->head;
  Node *prev = NULL;
  while (curr != NULL) {
    if (curr->data == node->data) {
      if (prev != NULL) {
        prev->next = curr->next;
      } else {
        ll->head = curr->next;
      }
      if (curr->next == NULL) {
        ll->tail = prev;
      }
      ll->size--;
      return 0;
    }
    prev = curr;
    curr = curr->next;
  }
  return -1;
}

// removes node from specified index from linked list
// returns -1 for failure and 0 for success
int remove_at_ll(Linked_list *ll, size_t i) {
  Node *prev = get_prev_at(ll, i);
  if (prev == NULL) {
      return -1;
  }
  Node *curr = prev->next;
  
  ll->size--;
  if (curr == ll->head) {
    ll->head = curr->next;
    return 0;
  }
  if (curr == ll->tail) {
    ll->tail = prev;
    ll->tail->next = NULL;
    return 0;
  }
  prev->next = curr->next;
  return 0;
}

// gets node's data from specified index from linked list
// returns NULL for error
void *get(Linked_list *ll, size_t i) {
  Node *prev = get_prev_at(ll, i);
  if (prev == NULL) {
      return NULL;
  }
  return prev->next->data;
}
