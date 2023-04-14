#include "queue.h"

void enqueue(Queue *q, int data) {
  Node n = {data, NULL};
  q->tail->next = &n;
  q->tail = &n;
};

Node *dequeue(Queue *q) {
  if (q->head == NULL)
    return NULL;
  Node *res = q->head;
  q->head = q->head->next;
  return res;
};

int peek(Queue *q) { return q->head->data; };
