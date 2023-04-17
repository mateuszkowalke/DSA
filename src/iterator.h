#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef void (*MapFunction)(const void *, void *);
typedef bool (*FilterFunction)(const void *);

typedef struct iterator Iterator;

Iterator *iterator_forward(void *, size_t, size_t);
Iterator *iterator_reverse(void *, size_t, size_t);
Iterator *iterator_map(Iterator *, MapFunction, size_t);
Iterator *iterator_filter(Iterator *, FilterFunction);
Iterator *iterator_enumerate(Iterator *, int);
Iterator *iterator_zip(Iterator *, Iterator *);
void iterator_destroy(Iterator *);
bool iterator_next(Iterator *, void *);
