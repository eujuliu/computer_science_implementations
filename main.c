#include <stdio.h>

int main() {
  int arr[10] = {10, 20, 30, 40, 50};

  size_t length = sizeof(arr) / sizeof(arr[0]);

  printf("%zu\n", length);

  return 1;
}
