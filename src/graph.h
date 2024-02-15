#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "dyn_arr.h"
#include "queue.h"

#ifndef GRAPH
#define GRAPH

bool same_size_t(const size_t el1, const size_t el2) { return el1 == el2; };

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
        bool deleted; \
    } T##_al_vertex_t; \
    decl_dyn_arr_type(T##_al_vertex_t); \
    decl_queue_type(size_t); \
    typedef T##_al_vertex_t_dyn_arr_t T##_al_t; \
    T##_al_t new_##T##_al() { \
        return (T##_al_t)new_##T##_al_vertex_t_dyn_arr(64); \
    } \
    size_t add_##T##_vertex_al(T##_al_t *al, T data) { \
        al_edge_t_dyn_arr_t edges = (al_edge_t_dyn_arr_t)new_al_edge_t_dyn_arr(4); \
        T##_al_vertex_t v = (T##_al_vertex_t){.data = data, .edges = edges, .deleted = false}; \
        push_##T##_al_vertex_t(al, v); \
        return al->len - 1; \
    } \
    void add_##T##_edge_al(T##_al_t *al, size_t v1, size_t v2, int weight) { \
        al_edge_t edge = {.next = v2, .weight = weight}; \
        T##_al_vertex_t vertex = T##_al_vertex_t_at(*al, v1); \
        if (vertex.deleted) { \
            fprintf(stderr, "Trying to attach edge to a deleted vertex at index: %ld\n", v1); \
            exit(1); \
        } \
        push_al_edge_t(&vertex.edges, edge); \
        insert_##T##_al_vertex_t_at(*al, v1, vertex); \
    } \
    size_t_dyn_arr_t bfs_##T##_al(T##_al_t al, size_t start_idx, T target, bool (*same) (const T el1, const T el2)) { \
        size_t_dyn_arr_t path = new_size_t_dyn_arr(16); \
        T##_al_vertex_t curr = T##_al_vertex_t_at(al, start_idx); \
        T##_al_vertex_t tmp; \
        T##_al_vertex_t *curr_p = &curr; \
        size_t *curr_idx_p = &start_idx; \
        if (same(target, curr.data)) { \
            return path; \
        } \
        size_t_dyn_arr_t seen = new_size_t_dyn_arr(16); \
        size_t *prevs = malloc(sizeof(size_t) * al.len); \
        if (prevs == NULL) { \
            perror("Error allocating prevs array(graph bfs)"); \
            exit(1); \
        } \
        for (size_t i = 0; i < al.len; i++) { \
            prevs[i] = -1; \
        } \
        push_size_t(&seen, start_idx); \
        size_t_q_t q = new_size_t_queue(); \
        size_t_enqueue(&q, &start_idx); \
        while (size_t_dequeue(&q, &curr_idx_p)) { \
            *curr_p = T##_al_vertex_t_at(al, *curr_idx_p); \
            if (same(target, curr_p->data)) { \
                break; \
            } \
            for (size_t i = 0; i < curr_p->edges.len; i++) { \
                al_edge_t e = al_edge_t_at(curr_p->edges, i); \
                if (includes_size_t(seen, e.next, same_size_t) == false) { \
                    prevs[e.next] = *curr_idx_p; \
                    push_size_t(&seen, e.next); \
                    size_t_enqueue(&q, &e.next); \
                } \
            } \
        } \
        for (size_t i = 0; i < al.len; i++) { \
            printf("prevs[%d]: %ld\n", i, prevs[i]); \
        } \
        while (prevs[*curr_idx_p] != -1) { \
            push_size_t(&path, *curr_idx_p); \
            *curr_idx_p = prevs[*curr_idx_p]; \
        } \
        free(prevs); \
        return path; \
    } \

#endif
