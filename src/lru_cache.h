#include "hash_map.h"

#ifndef LRU_CACHE
#define LRU_CACHE

// decided to use open addressing vs separate chaining as it's more cache friendly
// and given we stick to load factor < 0.7 leads and good hashing
// function, the performance should be good (yeah, I know we should profile both...)

typedef size_t (*hash_func_t) (const char *key, size_t map_size);

// taken from K&R 2nd edition, page 144
size_t default_hash_func(const char *key, size_t map_size) {
    uint hash = 0;
    for ( ; *key != 0; key++) {
        hash = *key + 31 * hash;
    }
    return hash % map_size;
}

#define decl_hash_map_type(T) \
    typedef struct { \
        char *key; \
        T val; \
    } T##_hash_map_entry_t; \
    decl_dyn_arr_type(T##_hash_map_entry_t); \
    typedef struct { \
        T##_hash_map_entry_t_dyn_arr_t dyn_arr; \
        hash_func_t hash_func; \
    } T##_hash_map_t; \
    T##_hash_map_t new_##T##_hash_map(size_t size, hash_func_t hash_func) { \
        T##_hash_map_entry_t_dyn_arr_t dyn_arr = new_##T##_hash_map_entry_t_dyn_arr(size); \
        if (hash_func == NULL) { \
            hash_func = default_hash_func; \
        } \
        for (size_t i = 0; i < size; i++) { \
            dyn_arr.arr[i].key = NULL; \
        } \
        return (T##_hash_map_t){.dyn_arr = dyn_arr, .hash_func = hash_func}; \
    } \

#endif
