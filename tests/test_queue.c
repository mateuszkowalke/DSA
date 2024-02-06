#include <criterion/criterion.h>

#include "../src/queue.h"

decl_queue_type(int);

Test(queue, should_properly_enqueue_new_data) {
  int_q_t q = new_int_queue();
  int_enqueue(&q, 1);
  int_enqueue(&q, 2);
  int_enqueue(&q, 3);
  cr_expect(q.tail->data == 3);
}

Test(queue, should_return_0_when_trying_to_dequeue_empty_queue) {
  int_q_t q = new_int_queue();
  int *data = malloc(sizeof(int));
  int res = int_dequeue(&q, data);
  cr_expect(res == 0);
}

Test(queue, should_properly_dequeue_data) {
  int_q_t q = new_int_queue();
  int_enqueue(&q, 1);
  int_enqueue(&q, 2);
  int_enqueue(&q, 3);
  int_enqueue(&q, 4);
  int *data = malloc(sizeof(int));
  int res = int_dequeue(&q, data);
  cr_expect(res != -1);
  cr_expect(*data == 1);
  cr_expect(q.head->data == 2);
}

Test(queue, should_allow_to_peek_data_from_front) {
  int_q_t q = new_int_queue();
  int_enqueue(&q, 10);
  int_enqueue(&q, 2);
  int_enqueue(&q, 3);
  int_enqueue(&q, 4);
  int *data = malloc(sizeof(int));
  int res = int_peek(q, data);
  // 1 indicates the queue is not empty
  cr_expect(res == 1);
  cr_expect(*data == 10);
}

Test(queue, should_handle_peek_of_empty_queue) {
  int_q_t q = new_int_queue();
  int *data = malloc(sizeof(int));
  int res = int_peek(q, data);
  // 0 indicates the queue is empty
  cr_expect(res == 0);
}

Test(queue, should_handle_dequeue_of_empty_queue) {}
