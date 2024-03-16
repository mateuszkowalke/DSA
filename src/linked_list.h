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
//
// T##_remove_node_sll removes specified node - it's caller's
// responsibility to be sure, that the node exists

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
        new_node->next = NULL; \
        if (i == 0 && sll->size == 0) { \
            sll->size++; \
            sll->head = new_node; \
            sll->tail = new_node; \
            return; \
        } else if (i == 0) { \
            sll->size++; \
            new_node->next = sll->head; \
            sll->head = new_node; \
            return; \
        } else if (i == sll->size) { \
            sll->size++; \
            sll->tail->next = new_node; \
            sll->tail = new_node; \
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
        new_node->next = NULL; \
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
        new_node->next = NULL; \
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
    T T##_get_at_sll(T##_sll_t sll, size_t i) { \
        T##_node_sll_t *prev = T##_get_prev_at_sll(sll, i); \
        if (prev == NULL) { \
            fprintf(stderr, "Trying to get at out of bounds index [%ld] (get_at_sll)", i); \
            exit(1); \
        } \
        return prev->next->data; \
    } \

#define decl_doubly_linked_list_type(T) \
    typedef struct dll_node { \
        struct dll_node *next; \
        struct dll_node *prev; \
        T data; \
    } T##_node_dll_t; \
    typedef struct { \
        size_t size; \
        T##_node_dll_t *head; \
        T##_node_dll_t *tail; \
    } T##_dll_t; \
    T##_dll_t new_##T##_dll() { \
        return (T##_dll_t){.size = 0, .head = NULL, .tail = NULL}; \
    } \
    T##_node_dll_t *T##_get_node_at_dll(T##_dll_t dll, size_t i) { \
        if (dll.size < i - 1) { \
            return NULL; \
        } \
        T##_node_dll_t *curr = dll.head; \
        for (; curr != NULL && i > 0; i--) { \
            curr = curr->next; \
        } \
        return curr; \
    } \
    void T##_insert_at_dll(T##_dll_t *dll, T data, size_t i) { \
        if (i > dll->size) { \
            fprintf(stderr, "Trying to insert at out of bounds index [%ld] (insert_at_dll)", i); \
            exit(1); \
        } \
        T##_node_dll_t *new_node = malloc(sizeof(T##_node_dll_t)); \
        if (new_node == NULL) { \
            perror("Error allocating new_node doubly linked list node (insert_at_dll)\n"); \
            exit(1); \
        } \
        new_node->data = data; \
        new_node->next = NULL; \
        new_node->prev = NULL; \
        if (i == 0 && dll->size == 0) { \
            dll->size++; \
            dll->head = new_node; \
            dll->tail = new_node; \
            return; \
        } else if (i == 0) { \
            dll->size++; \
            new_node->next = dll->head; \
            dll->head = new_node; \
            dll->head->next->prev = dll->head; \
            return; \
        } else if (i == dll->size) { \
            dll->size++; \
            new_node->prev = dll->tail; \
            dll->tail = new_node; \
            dll->tail->prev->next = dll->tail; \
            return; \
        } \
        T##_node_dll_t *curr = T##_get_node_at_dll(*dll, i); \
        if (curr == NULL) { \
            fprintf(stderr, "Trying to insert at out of bounds index [%ld] (insert_at_dll)", i); \
            exit(1); \
        } \
        dll->size++; \
        if (curr->next->next == NULL) { \
            dll->tail->next = new_node; \
            new_node->prev = dll->tail; \
            dll->tail = new_node; \
        } else { \
            new_node->next = curr; \
            new_node->prev = curr->prev; \
            curr->prev->next = new_node; \
            curr->prev = new_node; \
        } \
    } \
    void T##_append_dll(T##_dll_t *dll, T data) { \
        T##_node_dll_t *new_node = malloc(sizeof(T##_node_dll_t)); \
        if (new_node == NULL) { \
            perror("Error allocating new_node singly linked list node (insert_at_dll)\n"); \
            exit(1); \
        } \
        new_node->data = data; \
        new_node->next = NULL; \
        new_node->prev = NULL; \
        if (dll->size == 0) { \
            dll->head = new_node; \
            dll->tail = new_node; \
        } else { \
            dll->tail->next = new_node; \
            new_node->prev = dll->tail; \
            dll->tail = new_node; \
        } \
        dll->size++; \
    } \
    void T##_prepend_dll(T##_dll_t *dll, T data) { \
        T##_node_dll_t *new_node = malloc(sizeof(T##_node_dll_t)); \
        if (new_node == NULL) { \
            perror("Error allocating new_node singly linked list node (insert_at_dll)\n"); \
            exit(1); \
        } \
        new_node->data = data; \
        new_node->next = NULL; \
        new_node->prev = NULL; \
        if (dll->size == 0) { \
            dll->head = new_node; \
            dll->tail = new_node; \
        } else { \
            new_node->next = dll->head; \
            dll->head->prev = new_node; \
            dll->head = new_node; \
        } \
        dll->size++; \
    } \
    void T##_remove_node_dll(T##_dll_t *dll, T##_node_dll_t *curr) { \
        dll->size--; \
        if (curr == dll->head) { \
            T##_node_dll_t *tmp = dll->head; \
            dll->head = curr->next; \
            free(tmp); \
            return; \
        } \
        if (curr == dll->tail) { \
            dll->tail = curr->prev; \
            free(curr); \
            dll->tail->next = NULL; \
            return; \
        } \
        curr->prev->next = curr->next; \
        curr->next->prev = curr->prev; \
        free(curr); \
        return; \
    } \
    int T##_remove_dll(T##_dll_t *dll, T data) { \
        if (dll->head == NULL) { \
            return -1; \
        } \
        T##_node_dll_t *curr = dll->head; \
        while (curr != NULL) { \
            if (curr->data == data) { \
                T##_remove_node_dll(dll, curr); \
                return 0; \
            } \
            curr = curr->next; \
        } \
        return -1; \
    } \
    int T##_remove_at_dll(T##_dll_t *dll, size_t i) { \
        if (dll->size == 0) { \
            return -1; \
        } \
        if (i == 0) { \
            T##_remove_node_dll(dll, dll->head); \
            return 0; \
        } \
        T##_node_dll_t *curr = T##_get_node_at_dll(*dll, i); \
        if (curr == NULL) { \
            return -1; \
        } \
        T##_remove_node_dll(dll, curr); \
        return 0; \
    } \
    T T##_get_at_dll(T##_dll_t dll, size_t i) { \
        return T##_get_node_at_dll(dll, i)->data; \
    } \
    void T##_swap_dll(T##_dll_t *dll, T##_node_dll_t *n1, T##_node_dll_t *n2) { \
        T##_node_dll_t tmp; \
        if (dll->head == n1) { \
            dll->head = n2; \
        } else if (dll->head == n2) { \
            dll->head = n1; \
        } \
        if (dll->tail == n2) { \
            dll->tail = n1; \
        } else if (dll->tail == n1) { \
            dll->tail = n2; \
        } \
        tmp.next = n2->next == n1 ? n2 : n2->next; \
        tmp.prev = n2->prev == n1 ? n2 : n2->prev; \
        n2->next = n1->next == n2 ? n1 : n1->next; \
        n2->prev = n1->prev == n2 ? n1 : n1->prev; \
        n1->next = tmp.next; \
        n1->prev = tmp.prev; \
        if (n1->next != NULL) { \
            n1->next->prev = n1; \
        } \
        if (n1->prev != NULL) { \
            n1->prev->next = n1; \
        } \
        if (n2->next != NULL) { \
            n2->next->prev = n2; \
        } \
        if (n2->prev != NULL) { \
            n2->prev->next = n2; \
        } \
    } \

#endif
