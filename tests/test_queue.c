#include <criterion/criterion.h>
#include <stdio.h>

#include "../src/queue.h"

Test(queue, should_properly_enqueue_new_data) {
  int data1 = 1;
  int data2 = 2;
  int data3 = 3;
  int data4 = 4;
  Node_q n3 = {&data3, NULL};
  Node_q n2 = {&data2, &n3};
  Node_q n1 = {&data1, &n2};
  Queue q = {&n1, &n3};
  int res = enqueue(&q, &data4);
  cr_expect(*(int *)q.tail->data == data4);
  cr_expect(res != -1);
}

Test(queue, should_return_negative_one_when_dequeuing_if_no_nodes_in_queue) {
  Queue *q = new_queue();
  void *data;
  int res = dequeue(q, data);
  cr_expect(res == -1);
}

Test(queue, should_return_NULL_data_when_dequeuing) {
  Queue *q = new_queue();
  void *data;
  enqueue(q, NULL);
  int res = dequeue(q, &data);
  cr_expect(res != -1);
  cr_expect(data == NULL);
}

Test(queue, should_properly_dequeue_data) {
  int data1 = 1;
  int data2 = 2;
  int data3 = 3;
  int data4 = 4;
  Queue *q = new_queue();
  enqueue(q, &data1);
  enqueue(q, &data2);
  enqueue(q, &data3);
  enqueue(q, &data4);
  void *data;
  int res = dequeue(q, &data);
  cr_expect(res != -1);
  cr_expect(*(int *)data == data1);
  cr_expect(*(int *)q->head->data == data2);
}

Test(queue, should_allow_to_peek_data_from_front) {
  int data1 = 1;
  int data2 = 2;
  int data3 = 3;
  int data4 = 4;
  Node_q n4 = {&data4, NULL};
  Node_q n3 = {&data3, &n4};
  Node_q n2 = {&data2, &n3};
  Node_q n1 = {&data1, &n2};
  Queue q = {&n1, &n4};
  void *res = peek(&q);
  cr_expect(*(int *)res == data1);
  cr_expect(*(int *)q.head->data == data1);
}

Test(queue, should_handle_peek_of_empty_queue) {
  Queue *q = new_queue();
  cr_expect(peek(q) == NULL);
}

Test(queue, should_handle_dequeue_of_empty_queue) {}
