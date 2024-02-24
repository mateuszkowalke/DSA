#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "dyn_arr.h"

#ifndef HEAP
#define HEAP

/* public functions are:
 - new_##T##_min_heap,
 - push_##T##_min_heap,
 - pop_##T##_min_heap,
 - update_##T##_min_heap, */

// cmp_func has to return -1 for v1 lesser than v2, 0 for equal and 1 for bigger

// heap needs dyn_arr for type T to be declared by caller
#define decl_min_heap_type(T) \
    typedef T##_dyn_arr_t T##_min_heap_t; \
    T##_min_heap_t new_##T##_min_heap() { \
        return (T##_min_heap_t)new_##T##_dyn_arr(64); \
    } \
    int get_left_child_##T##_min_heap(T##_min_heap_t h, size_t parent_i, T *el) { \
        if (parent_i * 2 + 1 >= h.len) { \
            return -1; \
        } \
        *el = T##_at(h, parent_i * 2 + 1); \
        return 0; \
    } \
    int get_right_child_##T##_min_heap(T##_min_heap_t h, size_t parent_i, T *el) { \
        if (parent_i * 2 + 2 >= h.len) { \
            return -1; \
        } \
        *el = T##_at(h, parent_i * 2 + 2); \
        return 0; \
    } \
    void heapify_up_##T##_heap(T##_min_heap_t *h, size_t i, int (*cmp) (const T *v1, const T *v2)) { \
        size_t j = i < 2 ? 0 : (i - 1) / 2; \
        T left = T##_at(*h, i); \
        T right = T##_at(*h, j); \
        while (cmp(&left, &right) == -1) { \
            swap_##T(*h, i, j); \
            i = j; \
            j = i < 2 ? 0 : (i - 1) / 2; \
            left = T##_at(*h, i); \
            right = T##_at(*h, j); \
        } \
    } \
    void heapify_down_##T##_heap(T##_min_heap_t *h, size_t item_idx, int (*cmp) (const T *v1, const T *v2)) { \
        T left, right; \
        while (get_left_child_##T##_min_heap(*h, item_idx, &left) != -1) { \
            if (get_right_child_##T##_min_heap(*h, item_idx, &right) != -1) { \
                if (cmp(&left, &right) == -1) { \
                    swap_##T(*h, item_idx, item_idx * 2 + 1); \
                    item_idx = item_idx * 2 + 1; \
                } else { \
                    swap_##T(*h, item_idx, item_idx * 2 + 2); \
                    item_idx = item_idx * 2 + 2; \
                }\
            } else { \
                swap_##T(*h, item_idx, item_idx * 2 + 1); \
                item_idx = item_idx * 2 + 1; \
            } \
        } \
    } \
    void push_##T##_min_heap(T##_min_heap_t *h, T el, int (*cmp) (const T *v1, const T *v2)) { \
        size_t i = h->len; \
        push_##T(h, el); \
        heapify_up_##T##_heap(h, i, cmp); \
    } \
    bool pop_##T##_min_heap(T##_min_heap_t *h, T* data, int (*cmp) (const T *v1, const T *v2)) { \
        if (h->len == 0) { \
            return false; \
        } \
        T res; \
        if (h->len == 1) { \
            res = pop_##T(h); \
            memcpy(data, &res, sizeof(T)); \
            return true; \
        } \
        res = T##_at(*h, 0); \
        insert_##T##_at(*h, 0, pop_##T(h)); \
        size_t parent_i = 0; \
        heapify_down_##T##_heap(h, parent_i, cmp); \
        memcpy(data, &res, sizeof(T)); \
        return true; \
    } \

#endif
