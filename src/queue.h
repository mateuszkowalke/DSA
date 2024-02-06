#include <stdlib.h>
#include <stdio.h>

#ifndef QUEUE
#define QUEUE

// this implementation uses linked list as underlying data structure
//
// 'dequeue' returns 0 when queue is empty
// 1 for success (useful in while loops)
// similar logic applies to 'peek'
#define decl_queue_type(T) \
    typedef struct node_##T##_q_t { \
        T *data; \
        struct node_##T##_q_t *next; \
    } node_##T##_q_t; \
    typedef struct T##_queue { \
        struct node_##T##_q_t *head; \
        struct node_##T##_q_t *tail; \
        size_t len; \
    } T##_q_t; \
    T##_q_t new_##T##_queue() { \
        T##_q_t *q = malloc(sizeof(T##_q_t)); \
        if (q == NULL) { \
            perror("Error allocatiing queue(new_##T##_queue)"); \
            exit(1); \
        } \
        q->head = q->tail = NULL; \
        q->len = 0; \
        return *q; \
    } \
    void T##_enqueue(T##_q_t *q, T *data) { \
        node_##T##_q_t *n; \
        if ((n = malloc(sizeof(node_##T##_q_t))) == NULL) { \
            perror("Error allocatiing queue node(enqueue)"); \
            exit(1); \
        } \
        n->data = data; \
        n->next = NULL; \
        if (q->head == NULL) { \
            q->head = q->tail = n; \
        } else { \
            q->tail->next = n; \
            q->tail = n; \
        } \
        q->len++; \
    } \
    int T##_dequeue(T##_q_t *q, T **data) { \
        if (q->head == NULL) { \
            return 0; \
        } \
        node_##T##_q_t *n = q->head; \
        q->head = q->head->next; \
        q->len--; \
        *data = n->data; \
        free(n); \
        return 1; \
    } \
    int T##_peek(T##_q_t q, T **data) { \
        if (q.head == NULL) { \
            return 0; \
        } \
        *data = q.head->data; \
        return 1; \
    } \

#endif
