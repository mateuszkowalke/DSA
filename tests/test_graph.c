#include <criterion/criterion.h>

#include "../src/graph.h"

int same_func(const int el1, const int el2) {
    return el1 == el2;
}

decl_graph_type(int);

Test(graph, should_create_new_graph_without_errors) {
  int_al_t al = new_int_al();
}

Test(graph,
     should_create_new_graph_with_default_adjacency_list_capacity_of_64) {
  int_al_t al = new_int_al();
  cr_expect(al.cap == 64);
}

Test(graph, should_add_new_vertex_to_graph) {
  int_al_t al = new_int_al();
  add_int_vertex_al(&al, 5);
  cr_expect(int_al_vertex_t_at(al, 0).data == 5);
}

Test(graph, should_add_many_new_vertices_to_graph) {
  int_al_t al = new_int_al();
  add_int_vertex_al(&al, 5);
  add_int_vertex_al(&al, 4);
  add_int_vertex_al(&al, 3);
  cr_expect(int_al_vertex_t_at(al, 0).data == 5);
  cr_expect(int_al_vertex_t_at(al, 1).data == 4);
  cr_expect(int_al_vertex_t_at(al, 2).data == 3);
}

Test(graph, should_add_more_new_vertices_than_initial_capacity_to_graph) {
  int_al_t al = new_int_al();
  for (size_t i = 0; i < 100; i++) {
    add_int_vertex_al(&al, i);
  }
  for (size_t i = 0; i < 100; i++) {
    cr_expect(int_al_vertex_t_at(al, i).data == i);
  }
}

Test(graph, should_return_appropriate_index_of_added_vertex) {
  int_al_t al = new_int_al();
  size_t idx;
  for (size_t i = 0; i < 100; i++) {
    idx = add_int_vertex_al(&al, i);
  }
  cr_expect(idx == 99);
}

Test(graph, should_add_edges_to_vertex) {
  int_al_t al = new_int_al();
  size_t v1 = add_int_vertex_al(&al, 1);
  size_t v2 = add_int_vertex_al(&al, 2);
  add_int_edge_al(&al, v1, v2, 10);
  cr_expect(al.arr[0].edges.arr[0].weight == 10);
  cr_expect(al.arr[0].edges.arr[0].next == v2);
}

Test(graph, should_perform_bfs) {
  int_al_t al = new_int_al();
  size_t v1 = add_int_vertex_al(&al, 1);
  size_t v2 = add_int_vertex_al(&al, 2);
  size_t v3 = add_int_vertex_al(&al, 3);
  size_t v4 = add_int_vertex_al(&al, 4);
  add_int_edge_al(&al, v1, v2, 10);
  add_int_edge_al(&al, v1, v3, 10);
  add_int_edge_al(&al, v2, v3, 10);
  add_int_edge_al(&al, v2, v4, 10);
  add_int_edge_al(&al, v3, v4, 10);
  bfs_int_al(al, 0, 4, same_func);
}
