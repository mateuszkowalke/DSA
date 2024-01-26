#include <criterion/criterion.h>

#include "../src/graph.h"

decl_graph_type(int);

Test(min_heap, should_create_new_graph) {
  int_al_t al = new_int_al();
}

Test(min_heap, should_add_new_vertex_to_graph) {
  int_al_t al = new_int_al();
  cr_expect(1 == 1);
}
