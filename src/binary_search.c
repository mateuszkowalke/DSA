int binary_search(int el, int *arr, int len) {
  if (len == 0)
    return -1;

  int i = 0, j = len - 1, d;

  while (i != j) {
    d = (j - i) / 2;
    if (arr[i + d] == el) return i + d;

    if (arr[i + d] > el) {
      j -= d + 1;
    } else {
      i += d + 1;
    }
  }

  if (arr[i] == el)
    return i;

  return -1;
}
