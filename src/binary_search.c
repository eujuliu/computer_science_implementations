#include "binary_search.h"

int binary_search(int *arr, size_t len, int target) {
  int l = 0;
  int r = len - 1;

  while (l <= r) {
    int mid = (r + l) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return -1;
}

int binary_search_recursion(int *arr, int target, int l, int r) {
  if (l > r) {
    return -1;
  }

  int mid = (r + l) / 2;

  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] < target) {
    return binary_search_recursion(arr, target, mid + 1, r);
  } else {
    return binary_search_recursion(arr, target, l, mid - 1);
  }
}
