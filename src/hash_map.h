#include "dyn_arr.h"

#ifndef HASHMAP
#define HASHMAP

// decided to use open addressing as it's more cache friendly
// and given we stick to load factor < 0.7 leads and good hashing
// function, the performance should be good (yeah, I know we should profile both...)

typedef size_t (*hash_func_t) (char *key, size_t key_len);

size_t default_hash_func(char *key, size_t key_len) {

}

// needs dyn_arr to be declared with type T
#define decl_hash_map_type(T) \
    typedef struct { \
        char *key; \
        T val; \
    } T##_hash_map_entry_t; \
    typedef struct { \
        T##_dyn_arr_t dyn_arr; \
        hash_func_t hash_func; \
    } T##_hash_map_t; \
    T##_hash_map_t new_##T##_hash_map(size_t size, hash_func_t *hash_func) { \
        T##_dyn_arr_t dyn_arr = new_##T##_dyn_arr(size); \
        if (hash_func == NULL) { \
            hash_func = default_hash_func; \
        } \
        return T##_hash_map_t hash_map = (T##_hash_map_t){.dyn_arr = dyn_arr, .hash_func = hash_func}; \
    } \

#endif
