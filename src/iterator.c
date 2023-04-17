#include "iterator.h"

typedef struct iterator {
  Iterator *inner_iter1;
  Iterator *inner_iter2;
  void *arr;
  void *next;
  void *end;
  size_t el_size;
  bool forward;
  bool enumerate;
  int curr_i;
  MapFunction map_fn;
  FilterFunction filter_fn;
} Iterator;

Iterator *iterator_forward(void *arr, size_t len, size_t el_size) {
  Iterator *iter = malloc(sizeof(Iterator));
  iter->inner_iter1 = NULL;
  iter->inner_iter2 = NULL;
  iter->map_fn = NULL;
  iter->filter_fn = NULL;
  iter->arr = arr;
  iter->next = arr;
  iter->end = arr + (len * el_size);
  iter->el_size = el_size;
  iter->curr_i = -1;
  iter->enumerate = false;
  iter->forward = true;
  return iter;
}

Iterator *iterator_reverse(void *arr, size_t len, size_t el_size) {
  Iterator *iter = malloc(sizeof(Iterator));
  iter->inner_iter1 = NULL;
  iter->inner_iter2 = NULL;
  iter->map_fn = NULL;
  iter->filter_fn = NULL;
  iter->arr = arr;
  iter->next = arr + ((len - 1) * el_size);
  iter->end = arr - el_size;
  iter->el_size = el_size;
  iter->curr_i = -1;
  iter->enumerate = false;
  iter->forward = false;
  return iter;
}

void iterator_destroy(Iterator *iter) {
  if (iter != NULL)
    free(iter);
}

bool iterator_next(Iterator *iter, void *el) {
  // handle zipped iterators
  if (iter->inner_iter1 != NULL && iter->inner_iter2 != NULL) {
    if (!iterator_next(iter->inner_iter1, el)) {
      return false;
    }
    if (!iterator_next(iter->inner_iter2, el + iter->inner_iter1->el_size)) {
      return false;
    }
    return true;
  }
  // handle nested iterator
  if (iter->inner_iter1 != NULL) {
    if (iterator_next(iter->inner_iter1, el)) {
      if (iter->map_fn != NULL) {
        iter->map_fn(el, el);
      }
      if (iter->filter_fn != NULL) {
        if (!iter->filter_fn(el)) {
          return iterator_next(iter, el);
        }
      }
      if (iter->enumerate) {
        memmove(el + sizeof(int), el, iter->inner_iter1->el_size);
        *(int *)el = iter->curr_i;
        iter->curr_i++;
      }
      return true;
    }
    return false;
  }

  // handle base iterator
  if (iter->next == iter->end) {
    return false;
  }
  memcpy(el, iter->next, iter->el_size);
  if (iter->forward) {
    iter->next += iter->el_size;
  } else {
    iter->next -= iter->el_size;
  }
  return true;
}

Iterator *iterator_map(Iterator *inner_iter, MapFunction map_fn,
                       size_t out_el_size) {
  Iterator *iter = malloc(sizeof(Iterator));
  iter->inner_iter1 = inner_iter;
  iter->inner_iter2 = NULL;
  iter->map_fn = map_fn;
  iter->filter_fn = NULL;
  iter->arr = NULL;
  iter->next = NULL;
  iter->end = NULL;
  iter->el_size = out_el_size;
  iter->curr_i = -1;
  iter->enumerate = false;
  iter->forward = true;
  return iter;
}

Iterator *iterator_filter(Iterator *inner_iter, FilterFunction filter_fn) {
  Iterator *iter = malloc(sizeof(Iterator));
  iter->inner_iter1 = inner_iter;
  iter->inner_iter2 = NULL;
  iter->map_fn = NULL;
  iter->filter_fn = filter_fn;
  iter->arr = NULL;
  iter->next = NULL;
  iter->end = NULL;
  iter->el_size = inner_iter->el_size;
  iter->curr_i = -1;
  iter->enumerate = false;
  iter->forward = true;
  return iter;
}

Iterator *iterator_enumerate(Iterator *inner_iter, int idx) {
  Iterator *iter = malloc(sizeof(Iterator));
  iter->inner_iter1 = inner_iter;
  iter->inner_iter2 = NULL;
  iter->map_fn = NULL;
  iter->filter_fn = NULL;
  iter->arr = NULL;
  iter->next = NULL;
  iter->end = NULL;
  iter->el_size = inner_iter->el_size + sizeof(int);
  iter->enumerate = true;
  iter->forward = true;
  iter->curr_i = idx;
  return iter;
}

Iterator *iterator_zip(Iterator *inner_iter1, Iterator *inner_iter2) {
  Iterator *iter = malloc(sizeof(Iterator));
  iter->inner_iter1 = inner_iter1;
  iter->inner_iter2 = inner_iter2;
  iter->map_fn = NULL;
  iter->filter_fn = NULL;
  iter->arr = NULL;
  iter->next = NULL;
  iter->end = NULL;
  iter->el_size = inner_iter1->el_size + inner_iter2->el_size;
  iter->curr_i = -1;
  iter->enumerate = false;
  iter->forward = true;
  return iter;
}
