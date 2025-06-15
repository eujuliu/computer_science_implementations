#include "../include/singly_linkedlist.h"
#include "utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARROW_LENGTH 4;

char *to_string(LinkedList *ll) {
  if (ll->head == NULL) {
    return NULL;
  }

  Node *crr = ll->head;
  size_t buffer_size = 64;
  size_t count = 0;
  size_t longest = 0;

  while (crr != NULL) {
    buffer_size += get_unit_count(crr->value) + ARROW_LENGTH;
    longest = MAX(buffer_size, longest);
    crr = crr->next;
    count++;
  }

  char *result = (char *)malloc(buffer_size);

  if (!result) {
    perror("Error allocating space for char");
    return NULL;
  }

  crr = ll->head;

  char temp[longest];

  while (crr != NULL) {
    snprintf(temp, sizeof(temp), "%d", crr->value);
    strcat(result, temp);

    if (crr->next != NULL) {
      strcat(result, " -> ");
    }

    crr = crr->next;
  }

  return result;
}

int push_back(LinkedList *ll, int value) {
  Node *node = (Node *)malloc(sizeof(Node));

  if (node == NULL) {
    perror("Error in node allocation of memory");
    return -1;
  }

  node->value = value;
  node->next = NULL;
  ll->size += 1;

  if (ll->head == NULL) {
    ll->head = node;
    ll->tail = node;

    return (*ll->head).value;
  }

  ll->tail->next = node;
  ll->tail = node;

  return (*ll->tail).value;
}

int push_front(LinkedList *ll, int value) {
  Node *node = (Node *)malloc(sizeof(Node));

  if (node == NULL) {
    perror("Error in node allocation of memory");
    return -1;
  }

  node->value = value;
  node->next = ll->head;

  ll->head = node;
  ll->size += 1;

  return (*ll->head).value;
}
