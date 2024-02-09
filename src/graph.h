#include <stddef.h>
#include <stdio.h>
#include "dyn_arr.h"
#include "queue.h"

#ifndef GRAPH
#define GRAPH

// types and functions should use 'al_' (adjacency list) or 'g_' (graph) prefix here

typedef struct {
    // next represents an index of the target vertex in the adjacency list
    size_t next;
    // weight represents the edge weight
    int weight;
} al_edge_t;

// nodes are identified by their index in the adjacency list
// same function returns 1 when vertex values are equal and 0 when not
#define decl_graph_type(T) \
    decl_dyn_arr_type(al_edge_t); \
    decl_dyn_arr_type(size_t); \
    typedef struct { \
        T data; \
        al_edge_t_dyn_arr_t edges; \
        char deleted; \
    } T##_al_vertex_t; \
    decl_dyn_arr_type(T##_al_vertex_t); \
    decl_queue_type(T##_al_vertex_t); \
    typedef T##_al_vertex_t_dyn_arr_t T##_al_t; \
    T##_al_t new_##T##_al() { \
        return (T##_al_t)new_##T##_al_vertex_t_dyn_arr(64); \
    } \
    size_t add_##T##_vertex_al(T##_al_t *al, T data) { \
        al_edge_t_dyn_arr_t edges = (al_edge_t_dyn_arr_t)new_al_edge_t_dyn_arr(4); \
        T##_al_vertex_t n = (T##_al_vertex_t){.data = data, .edges = edges, .deleted = 0}; \
        push_##T##_al_vertex_t(al, n); \
        return al->len - 1; \
    } \
    void add_##T##_edge_al(T##_al_t *al, size_t v1, size_t v2, int weight) { \
        al_edge_t edge = {.next = v2, .weight = weight}; \
        T##_al_vertex_t vertex = T##_al_vertex_t_at(*al, v1); \
        if (vertex.deleted) { \
            fprintf(stderr, "Trying to attach edge to a non-existent vertex at index: %ld\n", v1); \
            exit(1); \
        } \
        push_al_edge_t(&vertex.edges, edge); \
    } \
    al_edge_t_dyn_arr_t bfs_##T##_al(T##_al_t al, size_t start_idx, T target, int (*same) (const T el1, const T el2)) { \
        printf("here\n"); \
        al_edge_t_dyn_arr_t path = new_al_edge_t_dyn_arr(16); \
        T##_al_vertex_t curr = T##_al_vertex_t_at(al, start_idx); \
        T##_al_vertex_t tmp; \
        T##_al_vertex_t *curr_p = &curr; \
        if (same(target, curr.data)) { \
            return path; \
        } \
        size_t_dyn_arr_t seen = new_size_t_dyn_arr(16); \
        T##_al_vertex_t_q_t q = new_##T##_al_vertex_t_queue(); \
        T##_al_vertex_t_enqueue(&q, curr_p); \
        while(T##_al_vertex_t_dequeue(&q, &curr_p)) { \
            printf("here too\n"); \
            push_size_t(&seen, start_idx); \
            printf("curr_p->edges.len: %ld\n", curr_p->edges.len); \
            for (size_t i = 0; i < curr_p->edges.len; i++) { \
                tmp = T##_al_vertex_t_at(al, al_edge_t_at(curr_p->edges, i).next); \
                printf("%d\n", tmp.data); \
                T##_al_vertex_t_enqueue(&q, &tmp); \
            } \
        } \
        return path; \
    } \

#endif
