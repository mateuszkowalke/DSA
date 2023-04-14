#include "stack.h"

void push(Stack *s, int data) {
  Node n = {data, s->top};
  s->top = &n;
};

Node *pop(Stack *s) {
  Node *res = s->top;
  if (res != NULL) {
    s->top = res->next;
  }
  return res;
};

int peek_stack(Stack *s) {
  if (s->top == NULL)
    return -1;
  return s->top->data;
};
