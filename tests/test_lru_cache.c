#include <criterion/criterion.h>

#include "../src/lru_cache.h"

decl_lru_cache_type(int);

Test(lru_cache, should_create_with_no_errors) { new_int_lru_cache(24); }

Test(lru_cache, should_add_key_and_return_its_value) {
  char *key = "test key";
  int_lru_cache_t lru_cache = new_int_lru_cache(10);
  update_int_lru_cache(&lru_cache, key, 2);
  int *res = get_int_lru_cache(lru_cache, key);
  cr_expect(*res == 2);
}

Test(lru_cache, should_add_key_and_evict_from_full_cache) {
  int_lru_cache_t lru_cache = new_int_lru_cache(4);
  update_int_lru_cache(&lru_cache, "key1", 1);
  update_int_lru_cache(&lru_cache, "key2", 2);
  update_int_lru_cache(&lru_cache, "key3", 3);
  update_int_lru_cache(&lru_cache, "key4", 4);
  update_int_lru_cache(&lru_cache, "key5", 5);
  int *res = get_int_lru_cache(lru_cache, "key1");
  cr_expect(res == NULL);
}

Test(lru_cache, should_update_key) {
  int_lru_cache_t lru_cache = new_int_lru_cache(4);
  update_int_lru_cache(&lru_cache, "key1", 1);
  update_int_lru_cache(&lru_cache, "key2", 2);
  update_int_lru_cache(&lru_cache, "key3", 3);
  update_int_lru_cache(&lru_cache, "key4", 4);
  update_int_lru_cache(&lru_cache, "key1", 5);
  int *res = get_int_lru_cache(lru_cache, "key1");
  cr_expect(*res == 5);
}

Test(lru_cache, should_return_empty_value_for_non_existent_key) {
  int_lru_cache_t lru_cache = new_int_lru_cache(4);
  update_int_lru_cache(&lru_cache, "key1", 1);
  update_int_lru_cache(&lru_cache, "key2", 2);
  update_int_lru_cache(&lru_cache, "key3", 3);
  update_int_lru_cache(&lru_cache, "key4", 4);
  int *res = get_int_lru_cache(lru_cache, "key5");
  cr_expect(res == NULL);
}
