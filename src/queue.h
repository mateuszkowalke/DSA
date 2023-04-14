#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Queue {
  struct Node *head;
  struct Node *tail;
} Queue;

void enqueue(Queue *q, int data);
Node *dequeue(Queue *q);
int peek(Queue *q);
