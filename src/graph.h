#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "dyn_arr.h"

#ifndef GRAPH
#define GRAPH

bool same_size_t(const size_t el1, const size_t el2) { return el1 == el2; };

// types and functions should use 'al_' (adjacency list) or 'g_' (graph) prefix here

typedef struct {
    // next represents an index of the target vertex in the adjacency list
    size_t next;
    // weight represents the edge weight
    uint weight;
} al_edge_t;

typedef struct { \
    size_t idx; \
    uint *dist; \
} vertex_dist_t; \
int cmp_vertex_dist_t(const vertex_dist_t *v1, const vertex_dist_t *v2) {
    if (*v1->dist < *v2->dist) {
        return -1;
    } else if (*v1->dist > *v2->dist) {
        return 1;
    } else {
        return 1;
    }
}

decl_dyn_arr_type(vertex_dist_t);
decl_min_heap_type(vertex_dist_t);
// graph needs dyn_arr to be declared for types al_edge_t and size_t
// and stack and queue to be declared for size_t type
// nodes are identified by their index in the adjacency list
// same function returns 1 when vertex values are equal and 0 when not
// dfs returns start_ids as its first path element
// bfs does not return start_ids as its first path element
#define decl_graph_type(T) \
    typedef struct { \
        size_t idx; \
        T data; \
        al_edge_t_dyn_arr_t edges; \
        bool deleted; \
    } T##_al_vertex_t; \
    decl_dyn_arr_type(T##_al_vertex_t); \
    typedef T##_al_vertex_t_dyn_arr_t T##_al_t; \
    T##_al_t new_##T##_al() { \
        return (T##_al_t)new_##T##_al_vertex_t_dyn_arr(64); \
    } \
    size_t add_##T##_vertex_al(T##_al_t *al, T data) { \
        al_edge_t_dyn_arr_t edges = (al_edge_t_dyn_arr_t)new_al_edge_t_dyn_arr(4); \
        T##_al_vertex_t v = (T##_al_vertex_t){.idx = al->len, .data = data, .edges = edges, .deleted = false}; \
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
        while (size_t_dequeue(&q, curr_idx_p)) { \
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
        while (prevs[*curr_idx_p] != -1) { \
            push_size_t(&path, *curr_idx_p); \
            *curr_idx_p = prevs[*curr_idx_p]; \
        } \
        free(prevs); \
        for (size_t i = 0; i < path.len / 2; i++) { \
            size_t tmp = path.arr[i]; \
            path.arr[i] = path.arr[path.len - 1 - i]; \
            path.arr[path.len - 1 -i] = tmp; \
        } \
        return path; \
    } \
    size_t_dyn_arr_t dfs_##T##_al(T##_al_t al, size_t start_idx, T target, bool (*same) (const T el1, const T el2)) { \
        size_t *curr_idx; \
        T##_al_vertex_t curr; \
        size_t_dyn_arr_t seen = new_size_t_dyn_arr(16); \
        size_t_s_t s = new_size_t_stack(); \
        push_size_t_s(&s, start_idx); \
        while((curr_idx = peek_size_t_s(s)) != NULL) { \
            curr = T##_al_vertex_t_at(al, *curr_idx); \
            if (same(target, curr.data)) { \
                push_size_t_s(&s, *curr_idx); \
                return s; \
            } \
            if (!includes_size_t(seen, *curr_idx, same_size_t)) { \
                push_size_t(&seen, *curr_idx); \
            } \
            bool pushed = false; \
            for (size_t i = 0; i < curr.edges.len; i++) { \
                if (!includes_size_t(seen, curr.edges.arr[i].next, same_size_t)) { \
                    push_size_t_s(&s, curr.edges.arr[i].next); \
                    pushed = true; \
                    break; \
                } \
            } \
            if (!pushed) { \
                pop_size_t(&s); \
            } \
        } \
        return s; \
    } \
    size_t_dyn_arr_t dijkstra_##T##_al(T##_al_t al, size_t start_idx, size_t target_idx) { \
        T##_al_vertex_t curr_vertex; \
        vertex_dist_t curr; \
        uint *dists = malloc(sizeof(uint) * al.len); \
        uint *prevs = malloc(sizeof(uint) * al.len); \
        for (size_t i = 0; i < al.len; i++) { \
            dists[i] = UINT_MAX; \
        } \
        dists[start_idx] = 0; \
        vertex_dist_t_min_heap_t h = new_vertex_dist_t_min_heap(); \
        push_vertex_dist_t_min_heap(&h, (vertex_dist_t){.idx = start_idx, .dist = &dists[start_idx]}, cmp_vertex_dist_t); \
        while(pop_vertex_dist_t_min_heap(&h, &curr, cmp_vertex_dist_t)) { \
            curr_vertex = T##_al_vertex_t_at(al, curr.idx); \
            for (size_t i = 0; i < curr_vertex.edges.len; i++) { \
                size_t next = curr_vertex.edges.arr[i].next; \
                size_t next_weight = curr_vertex.edges.arr[i].weight; \
                if (dists[next] > dists[curr_vertex.idx] + next_weight) { \
                    dists[next] = dists[curr_vertex.idx] + next_weight; \
                    prevs[next] = curr_vertex.idx; \
                    push_vertex_dist_t_min_heap(&h, (vertex_dist_t){.idx = next, .dist = &dists[next]}, cmp_vertex_dist_t); \
                } \
            } \
        } \
        size_t_dyn_arr_t path = new_size_t_dyn_arr(8); \
        if (dists[target_idx] == UINT_MAX) { \
            return path; \
        } \
        push_size_t(&path, target_idx); \
        while (target_idx != start_idx) { \
            push_size_t(&path, prevs[target_idx]); \
            target_idx = prevs[target_idx]; \
        } \
        free(dists); \
        free(prevs); \
        for (size_t i = 0; i < path.len / 2; i++) { \
            size_t tmp = path.arr[i]; \
            path.arr[i] = path.arr[path.len - 1 - i]; \
            path.arr[path.len - 1 -i] = tmp; \
        } \
        return path; \
    } \

#endif
