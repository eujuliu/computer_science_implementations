#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 16

typedef struct {
  int size;
  int capacity;
  int *data;
} Vector;

int at(Vector *vec, int index) {
  if (vec == NULL || (vec != NULL && index > vec->size - 1)) {
    return -1;
  }

  return vec->data[index];
}

int push(Vector *vec, int value) {
  if (vec->size + 1 >= vec->capacity) {
    int new_capacity = vec->capacity + 1;
    int* new_ptr = (int *)malloc(new_capacity * sizeof(int));

    for (int i = 0; i < vec->size; i++) {
      new_ptr[i] = vec->data[i];
    }

    vec->data = new_ptr;
  }

  vec->data[vec->size] = value;
  vec->size += 1;

  return vec->data[vec->size - 1];
}

int main() {
  int *ptr = (int *)malloc(INITIAL_CAPACITY * sizeof(int));

  if (ptr == NULL) {
    perror("Error in vector allocation of memory");
    return 1;
  }

  Vector vec = {0, INITIAL_CAPACITY, ptr};
  Vector * vec_ptr = &vec;

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

  return 0;
}
