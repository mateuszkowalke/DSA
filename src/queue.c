#include "queue.h"
#include <stdio.h>

Queue *new_queue() {
  Queue *q = malloc(sizeof(Queue));
  q->head = q->tail = NULL;
  q->len = 0;
  return q;
}

// returns -1 for failure
// non-negative for success
int enqueue(Queue *q, void *data) {
  Node_q *n;
  if ((n = malloc(sizeof(Node_q))) == NULL) {
    return -1;
  }
  n->data = data;
  n->next = NULL;
  if (q->head == NULL) {
    q->head = q->tail = n;
  } else {
    q->tail->next = n;
    q->tail = n;
  }
  q->len++;
  return 0;
};

// returns -1 when queue is empty
// non-negative for success
int dequeue(Queue *q, void **data) {
  if (q->head == NULL) {
    return -1;
  }
  Node_q *n = q->head;
  q->head = q->head->next;
  q->len--;
  *data = n->data;
  free(n);
  return 0;
};

void *peek(Queue *q) {
  if (q->head == NULL) {
    return NULL;
  }
  return q->head->data;
};
