#ifndef ARRAY_H
#define ARRAY_H

#define INITIAL_CAPACITY 8
#define DATA_POINTER_ERROR "Failed to create Array data Pointer"
#define ARRAY_POINTER_ERROR "Failed to create Array Pointer"

typedef struct {
  unsigned int size;
  unsigned int capacity;
  int *data;
} Array;

Array *new_array(int *args, unsigned int size);
void free_array(Array *arr);
unsigned int is_empty(Array *arr);
int at(Array *arr, unsigned int index);
unsigned int set(Array *arr, unsigned int index, int value);
void push(Array *arr, int value);
void insert(Array *arr, int index, int value);

#endif // !ARRAY_H
