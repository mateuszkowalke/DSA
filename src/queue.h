#include <stdlib.h>

#ifndef QUEUE
#define QUEUE

typedef struct Node_q {
  void *data;
  struct Node_q *next;
} Node_q;

typedef struct Queue {
  struct Node_q *head;
  struct Node_q *tail;
  size_t len;
} Queue;

Queue *new_queue();
int enqueue(Queue *q, void *data);
int dequeue(Queue *q, void **data);
void *peek(Queue *q);

#endif
