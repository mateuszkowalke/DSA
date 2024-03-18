#include "hash_map.h"
#include "linked_list.h"

#ifndef LRU_CACHE
#define LRU_CACHE

// maybe think of some other hash function for initializing underlying hash map

#define decl_lru_cache_type(T) \
    typedef struct { \
        char *key; \
        T val; \
    } T##_lru_dll_t; \
    typedef T##_lru_dll_t *T##_lru_dll_t_ref; \
    decl_doubly_linked_list_type(T##_lru_dll_t_ref); \
    typedef T##_lru_dll_t_ref_node_dll_t *T##_lru_node_ref_t; \
    decl_hash_map_type(T##_lru_node_ref_t); \
    typedef struct { \
        T##_lru_dll_t_ref_dll_t dll; \
        T##_lru_node_ref_t_hash_map_t hm; \
        size_t size; \
    } T##_lru_cache_t; \
    T##_lru_cache_t new_##T##_lru_cache(size_t size) { \
        T##_lru_dll_t_ref_dll_t dll = new_##T##_lru_dll_t_ref_dll(); \
        T##_lru_node_ref_t_hash_map_t hm = new_##T##_lru_node_ref_t_hash_map((size_t)size * 1.5, NULL); \
        return (T##_lru_cache_t){.dll = dll, .hm = hm, .size = size}; \
    } \
    void update_##T##_lru_cache(T##_lru_cache_t *lru_cache, const char *key, T value) { \
        T##_lru_node_ref_t *node= get_##T##_lru_node_ref_t_hash_map(lru_cache->hm, key); \
        if (node == NULL ) { \
            T##_lru_dll_t_ref data = malloc(sizeof(T##_lru_dll_t)); \
            data->val = value; \
            data->key = malloc(sizeof(char) * (strlen(key) + 1)); \
            strcpy(data->key, key); \
            T##_lru_dll_t_ref_prepend_dll(&lru_cache->dll, data); \
            if (lru_cache->size < lru_cache->dll.size) { \
                delete_##T##_lru_node_ref_t_hash_map(&lru_cache->hm, lru_cache->dll.tail->data->key); \
                T##_lru_dll_t_ref_remove_at_dll(&lru_cache->dll, lru_cache->dll.size - 1); \
            } \
        } else { \
            T##_lru_dll_t_ref_swap_dll(&lru_cache->dll, lru_cache->dll.head, *node); \
            lru_cache->dll.head->data->val = value; \
        } \
        put_##T##_lru_node_ref_t_hash_map(&lru_cache->hm, key, lru_cache->dll.head); \
    } \
    T *get_##T##_lru_cache(T##_lru_cache_t lru_cache, const char *key) { \
        T##_lru_node_ref_t *node = get_##T##_lru_node_ref_t_hash_map(lru_cache.hm, key); \
        if (node == NULL) { \
            return NULL; \
        } \
        return &(*node)->data->val; \
    } \

#endif
