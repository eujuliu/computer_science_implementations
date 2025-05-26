#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int run_vector() {
  int *ptr = (int *)malloc(INITIAL_CAPACITY * sizeof(int));

  if (ptr == NULL) {
    perror("Error in vector allocation of memory");
    return 1;
  }

  Vector vec = {0, INITIAL_CAPACITY, ptr};
  Vector *vec_ptr = &vec;

  for (int i = 0; i < vec.capacity; i++) {
    vec.size += 1;
    vec.data[i] = i + 1;
  }

  printf("Size: %d\n", vec.size);
  printf("Capacity: %d\n", vec.capacity);
  printf("Is empty: %d\n", vec.size == 0);
  printf("At: %d\n", at(vec_ptr, 15));
  printf("At: %d\n", at(vec_ptr, 16));
  printf("Push: %d\n", push(vec_ptr, 17));
  printf("Push: %d\n", push(vec_ptr, 18));
  printf("Pop: %d\n", pop(vec_ptr));
  printf("Pop: %d\n", pop(vec_ptr));
  printf("Size: %d\n", vec.size);
  printf("Capacity: %d\n", vec.capacity);

  return 0;
}

int main() {
  run_vector();
  return 0;
}
