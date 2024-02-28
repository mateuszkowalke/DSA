#include "dyn_arr.h"

#ifndef HASHMAP
#define HASHMAP

// decided to use open addressing as it's more cache friendly
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
    void put_##T##_hash_map(T##_hash_map_t *hm, const char *key, T item) { \
        size_t idx = hm->hash_func(key, hm->dyn_arr.cap); \
        char *key_cpy = malloc(sizeof(char) * (strlen(key) + 1)); \
        strcpy(key_cpy, key); \
        size_t offset = 1; \
        while (hm->dyn_arr.arr[idx + offset - 1].key != NULL) { \
            offset *= 2; \
        } \
        hm->dyn_arr.arr[idx] = (T##_hash_map_entry_t){.key = key_cpy, .val = item}; \
    } \
    T *get_##T##_hash_map(T##_hash_map_t hm, const char *key) { \
        size_t idx = hm.hash_func(key, hm.dyn_arr.cap); \
        size_t offset = 1; \
        T##_hash_map_entry_t e; \
        while ((e = hm.dyn_arr.arr[idx + offset - 1]).key != NULL && strcmp(e.key, key) != 0) { \
            offset *= 2; \
        } \
        if (hm.dyn_arr.arr[idx].key == NULL) { \
            return NULL; \
        } \
        return e.key == NULL ? NULL : &e.val; \
    } \
    void delete_##T##_hash_map(T##_hash_map_t *hm, const char *key) { \
        size_t idx = hm->hash_func(key, hm->dyn_arr.cap); \
        hm->dyn_arr.arr[idx].key = NULL; \
        return; \
    } \

#endif
