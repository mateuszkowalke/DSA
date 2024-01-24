#include <criterion/criterion.h>

#include "../src/heap.h"

decl_min_heap_type(int);

Test(min_heap, should_properly_push_data_on_min_heap) {
  int_min_heap_t h = new_int_min_heap();
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 2);
  cr_expect(h.arr[0] == 2);
}

Test(min_heap, should_properly_push_lots_of_data_on_min_heap) {
  int_min_heap_t h = new_int_min_heap();
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 8);
  push_int_min_heap(&h, 3);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 5);
  push_int_min_heap(&h, 9);
  push_int_min_heap(&h, 7);
  push_int_min_heap(&h, 6);
  push_int_min_heap(&h, 6);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 2);
  cr_expect(h.arr[0] == 2);
}

Test(min_heap, should_properly_pop_data_from_min_heap) {
  int_min_heap_t h = new_int_min_heap();
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 2);
  cr_expect(pop_int_min_heap(&h) == 2);
  cr_expect(pop_int_min_heap(&h) == 4);
}

Test(min_heap, should_properly_pop_all_data_from_min_heap) {
  int_min_heap_t h = new_int_min_heap();
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 2);
  cr_expect(pop_int_min_heap(&h) == 2);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(h.len == 0);
}

Test(min_heap, should_properly_pop_lots_of_data_from_min_heap) {
  int_min_heap_t h = new_int_min_heap();
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 8);
  push_int_min_heap(&h, 3);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 5);
  push_int_min_heap(&h, 9);
  push_int_min_heap(&h, 7);
  push_int_min_heap(&h, 6);
  push_int_min_heap(&h, 6);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 2);
  cr_expect(pop_int_min_heap(&h) == 2);
  cr_expect(pop_int_min_heap(&h) == 3);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(pop_int_min_heap(&h) == 4);
  cr_expect(pop_int_min_heap(&h) == 5);
  cr_expect(pop_int_min_heap(&h) == 6);
  cr_expect(pop_int_min_heap(&h) == 6);
}
