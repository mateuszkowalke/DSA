#include <criterion/criterion.h>

#include "../src/queue.h"

Test(queue, should_properly_enqueue_new_data) {
  Node n3 = {3, NULL};
  Node n2 = {2, &n3};
  Node n1 = {1, &n2};
  Queue q = {&n1, &n3};
  enqueue(&q, 4);
  cr_expect(q.tail->data == 4);
}

Test(queue, should_return_NULL_if_no_nodes_in_queue) {
  Queue q = {NULL, NULL};
  Node * res = dequeue(&q);
  cr_expect(res == NULL);
}

Test(queue, should_properly_dequeue_data) {
  Node n4 = {4, NULL};
  Node n3 = {3, &n4};
  Node n2 = {2, &n3};
  Node n1 = {1, &n2};
  Queue q = {&n1, &n4};
  Node* res = dequeue(&q);
  cr_expect(res->data == 1);
  cr_expect(q.head->data == 2);
}

Test(queue, should_allow_to_peek_data_from_front) {
  Node n4 = {4, NULL};
  Node n3 = {3, &n4};
  Node n2 = {2, &n3};
  Node n1 = {1, &n2};
  Queue q = {&n1, &n4};
  int res = peek(&q);
  cr_expect(res == 1);
  cr_expect(q.head->data == 1);
}
