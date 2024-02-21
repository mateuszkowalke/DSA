#ifndef STACK
#define STACK

// stack needs dyn_arr for type T to be declared by caller
#define decl_stack_type(T) \
    typedef T##_dyn_arr_t T##_s_t; \
    T##_s_t new_##T##_stack() { \
        return new_##T##_dyn_arr(16); \
    } \
    void push_##T##_s(T##_s_t *s, T data) { \
        push_##T(s, data); \
    } \
    T pop_##T##_s(T##_s_t *s) { \
        return pop_##T(s); \
    } \
    T *peek_##T##_s(T##_s_t s) { \
        if (s.len == 0) { \
            return NULL; \
        } \
        return &s.arr[s.len - 1]; \
    } \

#endif
