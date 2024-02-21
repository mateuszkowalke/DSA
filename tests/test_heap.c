#include <criterion/criterion.h>

#include "../src/dyn_arr.h"
#include "../src/heap.h"

decl_dyn_arr_type(int);
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

Test(min_heap, should_return_false_when_popping_empty_heap) {
  int_min_heap_t h = new_int_min_heap();
  int data;
  cr_expect(pop_int_min_heap(&h, &data) == false);
}

Test(min_heap, should_properly_pop_data_from_min_heap) {
  int_min_heap_t h = new_int_min_heap();
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 2);
  int data;
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 2);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
}

Test(min_heap, should_properly_pop_all_data_from_min_heap) {
  int_min_heap_t h = new_int_min_heap();
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 4);
  push_int_min_heap(&h, 2);
  int data;
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 2);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
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
  int data;
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 2);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 3);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 4);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 5);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 6);
  cr_expect(pop_int_min_heap(&h, &data) == true);
  cr_expect(data == 6);
}
