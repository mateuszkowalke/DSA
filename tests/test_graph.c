#include <criterion/criterion.h>

#include "../src/graph.h"

decl_graph_type(int);

Test(min_heap, should_create_new_graph_without_errors) {
  int_al_t al = new_int_al();
}

Test(min_heap, should_create_new_graph_with_default_adjacency_list_capacity_of_64) {
  int_al_t al = new_int_al();
  cr_expect(al.cap == 64);
}

Test(min_heap, should_add_new_vertex_to_graph) {
  int_al_t al = new_int_al();
  add_int_vertex_al(&al, 5);
  cr_expect(int_al_node_t_at(al, 0).data == 5);
}

Test(min_heap, should_add_many_new_vertices_to_graph) {
  int_al_t al = new_int_al();
  add_int_vertex_al(&al, 5);
  add_int_vertex_al(&al, 4);
  add_int_vertex_al(&al, 3);
  cr_expect(int_al_node_t_at(al, 0).data == 5);
  cr_expect(int_al_node_t_at(al, 1).data == 4);
  cr_expect(int_al_node_t_at(al, 2).data == 3);
}

Test(min_heap, should_add_more_new_vertices_than_initial_capacity_to_graph) {
  int_al_t al = new_int_al();
  for (size_t i = 0; i < 100; i++) {
      add_int_vertex_al(&al, i);
  }
  for (size_t i = 0; i < 100; i++) {
      cr_expect(int_al_node_t_at(al, i).data == i);
  }
}
