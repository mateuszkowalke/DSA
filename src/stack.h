#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Stack {
  struct Node *top;
} Stack;

void push(Stack *s, int data);
Node *pop(Stack *s);
int peek_stack(Stack *s);
