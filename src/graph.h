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
        al_edge_t_dyn_arr_t dyn_arr; \
    } T##_al_node_t; \
    decl_dyn_arr_type(T##_al_node_t); \
    typedef T##_al_node_t_dyn_arr_t T##_al_t; \
    T##_al_t new_##T##_al() { \
        return (T##_al_t)new_dyn_##T##_al_node_t_arr(64); \
    } \

#endif
