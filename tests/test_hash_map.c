#include <criterion/criterion.h>

#include "../src/hash_map.h"

decl_hash_map_type(int);

Test(hash_map, should_create_new_hash_map) {
  int_hash_map_t hm = new_int_hash_map(128, NULL);
  cr_expect(hm.dyn_arr.cap == 128);
}

Test(hash_map, should_insert_new_items) {
  int_hash_map_entry_t entry = {.key = "test key", .val = 17};
  int_hash_map_t hm = new_int_hash_map(128, NULL);
  put_int_hash_map(&hm, entry.key, entry.val);
  bool found = false;
  for (size_t i = 0; i < hm.dyn_arr.cap; i++) {
    if (hm.dyn_arr.arr[i].key != NULL &&
        strcmp(hm.dyn_arr.arr[i].key, entry.key) == 0 &&
        hm.dyn_arr.arr[i].val == entry.val) {
      found = true;
      break;
    }
  }
  cr_expect(found);
}

Test(hash_map, should_keep_copy_of_key) {
  char *key = malloc(sizeof(char) * 10);
  key[0] = 'k';
  key[1] = 'e';
  key[2] = 'y';
  key[3] = 0;
  int_hash_map_entry_t entry = {.key = key, .val = 17};
  int_hash_map_t hm = new_int_hash_map(128, NULL);
  put_int_hash_map(&hm, entry.key, entry.val);
  bool found = false;
  for (size_t i = 0; i < hm.dyn_arr.cap; i++) {
    if (hm.dyn_arr.arr[i].key != NULL &&
        strcmp(hm.dyn_arr.arr[i].key, entry.key) == 0 &&
        hm.dyn_arr.arr[i].val == entry.val) {
      found = true;
      break;
    }
  }
  cr_expect(found);
  free(key);
  char *key2 = malloc(sizeof(char) * 10);
  key2[0] = 'k';
  key2[1] = 'e';
  key2[2] = 'y';
  key2[3] = 0;
  found = false;
  for (size_t i = 0; i < hm.dyn_arr.cap; i++) {
    if (hm.dyn_arr.arr[i].key != NULL &&
        strcmp(hm.dyn_arr.arr[i].key, key2) == 0 &&
        hm.dyn_arr.arr[i].val == entry.val) {
      found = true;
      break;
    }
  }
  cr_expect(found);
}

Test(hash_map, should_retrieve_inserted_item) {
  int value = 17;
  int_hash_map_entry_t entry = {.key = "test key", .val = value};
  int_hash_map_t hm = new_int_hash_map(128, NULL);
  put_int_hash_map(&hm, entry.key, entry.val);
  int res = *get_int_hash_map(hm, entry.key);
  cr_expect(res == value);
}

Test(hash_map, should_return_NULL_for_non_existent_key) {
  int value = 17;
  int_hash_map_entry_t entry = {.key = "test key", .val = value};
  int_hash_map_t hm = new_int_hash_map(128, NULL);
  put_int_hash_map(&hm, entry.key, entry.val);
  int *res = get_int_hash_map(hm, "non existent key");
  cr_expect(res == NULL);
}

Test(hash_map, should_delete_key) {
  int value = 17;
  int_hash_map_entry_t entry = {.key = "test key", .val = value};
  int_hash_map_t hm = new_int_hash_map(128, NULL);
  put_int_hash_map(&hm, entry.key, entry.val);
  delete_int_hash_map(&hm, entry.key);
  int *res = get_int_hash_map(hm, entry.key);
  cr_expect(res == NULL);
}
