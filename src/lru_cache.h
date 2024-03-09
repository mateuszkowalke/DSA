#include "hash_map.h"
#include "linked_list.h"

#ifndef LRU_CACHE
#define LRU_CACHE

#define decl_lru_type(T) \
    decl_doubly_linked_list_type(T); \
    decl_hash_map_type(T##_node_dll_t); \

#endif
