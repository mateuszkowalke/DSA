#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#ifndef LINKED_LIST
#define LINKED_LIST

// T##_remove_sll removes node with the same data from linked list
// returns -1 for failure and 0 for success
//
// T##_remove_at_sll removes node from specified index from linked list
// returns -1 for failure and 0 for success

#define decl_singly_linked_list_type(T) \
    typedef struct sll_node { \
        struct sll_node *next; \
        T data; \
    } T##_node_sll_t; \
    typedef struct { \
        size_t size; \
        T##_node_sll_t *head; \
        T##_node_sll_t *tail; \
    } T##_sll_t; \
    T##_sll_t new_##T##_sll() { \
        return (T##_sll_t){.size = 0, .head = NULL, .tail = NULL}; \
    } \
    T##_node_sll_t *T##_get_prev_at_sll(T##_sll_t sll, size_t i) { \
        if (sll.size < i - 1) { \
            return NULL; \
        } \
        T##_node_sll_t *curr = sll.head; \
        T##_node_sll_t *prev = NULL; \
        for (; curr != NULL && i > 0; i--) { \
            prev = curr; \
            curr = curr->next; \
        } \
        return prev; \
    } \
    void T##_insert_at_sll(T##_sll_t *sll, T data, size_t i) { \
        if (i > sll->size) { \
            fprintf(stderr, "Trying to insert at out of bounds index [%ld] (insert_at_sll)", i); \
            exit(1); \
        } \
        T##_node_sll_t *new_node = malloc(sizeof(T##_node_sll_t)); \
        if (new_node == NULL) { \
            perror("Error allocating new_node singly linked list node (insert_at_sll)\n"); \
            exit(1); \
        } \
        new_node->data = data; \
        if (i == 0 && sll->head == NULL && sll->size == 0) { \
            sll->size++; \
            sll->head = new_node; \
            sll->tail = new_node; \
            return; \
        } else if (i == 0) { \
            sll->size++; \
            new_node->next = sll->head; \
            sll->head = new_node; \
            return; \
        } \
        T##_node_sll_t *prev = T##_get_prev_at_sll(*sll, i); \
        if (prev == NULL) { \
            fprintf(stderr, "Trying to insert at out of bounds index [%ld] (insert_at_sll)", i); \
            exit(1); \
        } \
        sll->size++; \
        if (prev->next->next == NULL) { \
            sll->tail->next = new_node; \
            sll->tail = new_node; \
        } else { \
            new_node->next = prev->next->next; \
            prev->next = new_node; \
        } \
    } \
    void T##_append_sll(T##_sll_t *sll, T data) { \
        T##_node_sll_t *new_node = malloc(sizeof(T##_node_sll_t)); \
        if (new_node == NULL) { \
            perror("Error allocating new_node singly linked list node (insert_at_sll)\n"); \
            exit(1); \
        } \
        new_node->data = data; \
        if (sll->size == 0) { \
            sll->head = new_node; \
            sll->tail = new_node; \
        } else { \
            sll->tail->next = new_node; \
            sll->tail = new_node; \
        } \
        sll->size++; \
    } \
    void T##_prepend_sll(T##_sll_t *sll, T data) { \
        T##_node_sll_t *new_node = malloc(sizeof(T##_node_sll_t)); \
        if (new_node == NULL) { \
            perror("Error allocating new_node singly linked list node (insert_at_sll)\n"); \
            exit(1); \
        } \
        new_node->data = data; \
        if (sll->size == 0) { \
            sll->head = new_node; \
            sll->tail = new_node; \
        } else { \
            new_node->next = sll->head; \
            sll->head = new_node; \
        } \
        sll->size++; \
    } \
    void T##_remove_node_sll(T##_sll_t *sll, T##_node_sll_t *curr, T##_node_sll_t *prev) { \
        sll->size--; \
        if (curr == sll->head) { \
            T##_node_sll_t *tmp = sll->head; \
            sll->head = curr->next; \
            free(tmp); \
            return; \
        } \
        if (curr == sll->tail) { \
            free(sll->tail); \
            sll->tail = prev; \
            sll->tail->next = NULL; \
            return; \
        } \
        T##_node_sll_t *tmp = prev->next; \
        prev->next = curr->next; \
        free(tmp); \
        return; \
    } \
    int T##_remove_sll(T##_sll_t *sll, T data) { \
        if (sll->head == NULL) { \
            return -1; \
        } \
        T##_node_sll_t *curr = sll->head; \
        T##_node_sll_t *prev = NULL; \
        while (curr != NULL) { \
            if (curr->data == data) { \
                T##_remove_node_sll(sll, curr, prev); \
                return 0; \
            } \
            prev = curr; \
            curr = curr->next; \
        } \
        return -1; \
    } \
    int T##_remove_at_sll(T##_sll_t *sll, size_t i) { \
        if (sll->size == 0) { \
            return -1; \
        } \
        if (i == 0) { \
            T##_remove_node_sll(sll, sll->head, NULL); \
            return 0; \
        } \
        T##_node_sll_t *prev = T##_get_prev_at_sll(*sll, i); \
        if (prev == NULL) { \
            return -1; \
        } \
        T##_node_sll_t *curr = prev->next; \
        T##_remove_node_sll(sll, curr, prev); \
        return 0; \
    } \
    T T##_get_sll(T##_sll_t sll, size_t i) { \
        T##_node_sll_t *prev = T##_get_prev_at_sll(sll, i); \
        if (prev == NULL) { \
            return NULL; \
        } \
        return prev->next->data; \
    } \

#define decl_doubly_linked_list_type(T) \

#endif
