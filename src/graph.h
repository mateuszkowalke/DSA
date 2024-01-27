#include <stddef.h>
#include "dyn_arr.h"

#ifndef GRAPH
#define GRAPH

// types and functions should use 'al_' (adjacency list) or 'g_' (graph) prefix here

typedef struct {
    // next represents an index of the target vertex in the adjacency list
    size_t next;
    // weight represents the edge weight
    int weight;
} al_edge_t;

#define decl_graph_type(T) \
    decl_dyn_arr_type(al_edge_t); \
    typedef struct { \
        T data; \
        al_edge_t_dyn_arr_t edges; \
    } T##_al_node_t; \
    decl_dyn_arr_type(T##_al_node_t); \
    typedef T##_al_node_t_dyn_arr_t T##_al_t; \
    T##_al_t new_##T##_al() { \
        return (T##_al_t)new_##T##_al_node_t_dyn_arr(64); \
    } \
    void add_##T##_vertex_al(T##_al_t *al, T data) { \
        al_edge_t_dyn_arr_t edges = (al_edge_t_dyn_arr_t)new_al_edge_t_dyn_arr(4); \
        push_##T##_al_node_t(al, (T##_al_node_t){.data = data, .edges = edges}); \
    } \

#endif
