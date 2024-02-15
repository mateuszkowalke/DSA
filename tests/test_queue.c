#include <criterion/criterion.h>

#include "../src/queue.h"

decl_queue_type(int);

int one = 1;
int two = 2;
int three = 3;
int four = 4;
int ten = 10;

Test(queue, should_properly_enqueue_new_data) {
  int_q_t q = new_int_queue();
  int_enqueue(&q, &one);
  int_enqueue(&q, &two);
  int_enqueue(&q, &three);
  cr_expect(q.tail->data == &three);
}

Test(queue, should_return_0_when_trying_to_dequeue_empty_queue) {
  int_q_t q = new_int_queue();
  int *data = malloc(sizeof(int));
  int res = int_dequeue(&q, &data);
  cr_expect(res == 0);
}

Test(queue, should_properly_dequeue_data) {
  int_q_t q = new_int_queue();
  int_enqueue(&q, &one);
  int_enqueue(&q, &two);
  int_enqueue(&q, &three);
  int_enqueue(&q, &four);
  int *data = malloc(sizeof(int));
  int res = int_dequeue(&q, &data);
  cr_expect(res != -1);
  cr_expect(*data == 1);
  cr_expect(q.head->data == &two);
}

Test(queue, should_properly_dequeue_data_with_while_loop_till_empty) {
  int_q_t q = new_int_queue();
  int_enqueue(&q, &one);
  int_enqueue(&q, &two);
  int_enqueue(&q, &three);
  int_enqueue(&q, &four);
  int *data = malloc(sizeof(int));
  while(int_dequeue(&q, &data)) {}
  cr_expect(q.len == 0);
}

Test(queue, should_allow_to_peek_data_from_front) {
  int_q_t q = new_int_queue();
  int_enqueue(&q, &ten);
  int_enqueue(&q, &two);
  int_enqueue(&q, &three);
  int_enqueue(&q, &four);
  int *data = malloc(sizeof(int));
  int res = int_peek(q, &data);
  // 1 indicates the queue is not empty
  cr_expect(res == 1);
  cr_expect(*data == 10);
}

Test(queue, should_handle_peek_of_empty_queue) {
  int_q_t q = new_int_queue();
  int *data = malloc(sizeof(int));
  int res = int_peek(q, &data);
  // 0 indicates the queue is empty
  cr_expect(res == 0);
}

Test(queue, should_handle_dequeue_of_empty_queue) {}
