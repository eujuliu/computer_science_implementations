#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define INITIAL_CAPACITY 8
#define DATA_POINTER_ERROR "Failed to create Array data Pointer"
#define ARRAY_POINTER_ERROR "Failed to create Array Pointer"

#define DEFINE_ARRAY(T, Name)                                                  \
  typedef struct {                                                             \
    T *data;                                                                   \
    size_t size;                                                               \
    size_t capacity;                                                           \
  } Name;

DEFINE_ARRAY(int, IArray);
DEFINE_ARRAY(float, FArray);
DEFINE_ARRAY(char *, CArray);

typedef struct {
  size_t size;
  size_t capacity;
  int *data;
} Array;

Array *new_array(int *args, size_t size);
void free_array(Array *arr);
unsigned int is_empty(Array *arr);
int at(Array *arr, int index);
unsigned int set(Array *arr, unsigned int index, int value);
void push(Array *arr, int value);
unsigned int insert(Array *arr, unsigned int index, int value);
unsigned int prepend(Array *arr, int value);
int pop(Array *arr);
unsigned int delete_item(Array *arr, int index);
void remove_item(Array *arr, int value);
int find(Array *arr, int value);

#endif // !ARRAY_H
