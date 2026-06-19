#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int binary_search(int *arr, size_t len, int target);
int binary_search_recursion(int *arr, int target, int l, int r);

#endif // !BINARY_SEARCH_H
