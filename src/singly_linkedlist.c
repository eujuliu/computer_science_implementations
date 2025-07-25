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

int value_at(LinkedList *ll, int index) {
  Node *node = ll->head;

  while (index) {
    if (!node) {
      return -1;
    }

    node = node->next;
    index--;
  }

  return node->value;
}

int pop_front(LinkedList *ll) {
  if (!ll->head) {
    return -1;
  }

  Node *removed = ll->head;

  ll->head = ll->head->next;

  ll->size--;

  if (!ll->head) {
    ll->tail = NULL;
  }

  int value = removed->value;
  free(removed);

  return value;
}

int pop_back(LinkedList *ll) {
  if (ll->head == NULL) {
    return -1;
  }

  int value = ll->tail->value;

  if (ll->head == ll->tail) {
    ll->head = NULL;
    free(ll->tail);
    ll->tail = NULL;
  } else {
    Node *node = ll->head;
    while (node->next != ll->tail) {
      node = node->next;
    }

    Node *remove = node->next;

    node->next = NULL;
    ll->tail = node;
    free(remove);
  }

  ll->size--;

  return value;
}

int insert(LinkedList *ll, int index, int value) {
  if (index < -1 || index > ll->size - 1) {
    return -1;
  }

  if (index == 0) {
    return push_front(ll, value);
  }

  if (index == -1 || index == ll->size - 1) {
    return push_back(ll, value);
  }

  Node *node = (Node *)malloc(sizeof(Node));

  node->value = value;
  node->next = NULL;

  int count = index;
  Node *crr = ll->head;

  while (count > 0) {
    crr = crr->next;
    count--;
  }

  node->next = crr->next;
  crr->next = node;
  ll->size++;

  return node->value;
}

int erase(LinkedList *ll, int index) {
  if (!ll->head) {
    return -1;
  }

  if (index == 0) {
    return pop_front(ll);
  }

  if (index == ll->size - 1 || index == -1) {
    return pop_back(ll);
  }

  int count = index - 1;
  Node *crr = ll->head;

  while (count > 0) {
    crr = crr->next;
    count--;
  }

  Node *remove = crr->next;
  int value = remove->value;
  crr->next = crr->next->next;
  ll->size--;

  free(remove);

  return value;
}

int value_n_from_end(LinkedList *ll, int n) {
  int count = ll->size - n;
  Node *node = ll->head;

  while (count) {
    node = node->next;
    count--;
  }

  return node->value;
}

void reverse(LinkedList *ll) {
  LinkedList *ll2 = (LinkedList *)malloc(sizeof(LinkedList));

  ll2->head = NULL;
  ll2->tail = NULL;
  ll2->size = ll->size;

  Node *crr = ll->head;

  while (crr != NULL) {
    Node *next = crr->next;

    crr->next = NULL;

    if (ll2->head) {
      crr->next = ll2->head;
      ll2->head = crr;
    } else {
      ll2->head = crr;
      ll2->tail = crr;
    }

    crr = next;
  }

  ll->head = ll2->head;
  ll->tail = ll2->tail;
  free(ll2);
}

int remove_value(LinkedList *ll, int value) {
  if (ll->head == NULL) {
    return -1;
  }

  Node *crr = ll->head;
  Node *prev = NULL;
  int index = 0;

  while (crr != NULL) {
    if (crr->value == value) {
      if (prev == NULL) {
        ll->head = crr->next;

        if (ll->head == NULL) {
          ll->tail = NULL;
        }
      } else {
        prev->next = crr->next;

        if (ll->tail == crr) {
          ll->tail = prev;
        }
      }

      free(crr);
      ll->size--;
      return index;
    }

    prev = crr;
    crr = crr->next;
    index++;
  }

  return -1;
}
