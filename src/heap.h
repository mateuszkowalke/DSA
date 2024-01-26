#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "dyn_arr.h"

#ifndef HEAP
#define HEAP

#define decl_min_heap_type(T) \
    decl_dyn_arr_type(T); \
    typedef T##dyn_arr_t T##_min_heap_t; \
    T##_min_heap_t new_##T##_min_heap() { \
        return (T##_min_heap_t)new_dyn_##T##_arr(64); \
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
    void push_##T##_min_heap(T##_min_heap_t *h, T el) { \
        size_t i = h->len; \
        push_##T(h, el); \
        size_t j = i < 2 ? 0 : (i - 1) / 2; \
        while (T##_at(*h, i) < T##_at(*h, j)) { \
            swap_##T(*h, i, j); \
            i = j; \
            j = i < 2 ? 0 : (i - 1) / 2; \
        } \
    } \
    T pop_##T##_min_heap(T##_min_heap_t *h) { \
        if (h->len == 1) { \
            return pop_##T(h); \
        } \
        T res = T##_at(*h, 0); \
        insert_##T##_at(*h, 0, pop_##T(h)); \
        size_t parent_i = 0; \
        T left, right; \
        while (get_left_child_##T##_min_heap(*h, parent_i, &left) != -1) { \
            if (get_right_child_##T##_min_heap(*h, parent_i, &right) != -1) { \
                if (left < right) { \
                    swap_##T(*h, parent_i, parent_i * 2 + 1); \
                    parent_i = parent_i * 2 + 1; \
                } else { \
                    swap_##T(*h, parent_i, parent_i * 2 + 2); \
                    parent_i = parent_i * 2 + 2; \
                }\
            } else { \
                swap_##T(*h, parent_i, parent_i * 2 + 1); \
                parent_i = parent_i * 2 + 1; \
            } \
        } \
        return res; \
    } \

#endif
