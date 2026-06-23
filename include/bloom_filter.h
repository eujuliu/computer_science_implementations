#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

static int hash1_bf(char *k);
static int hash2_bf(char *k);
static int hash3_bf(char *k);
int search_bf(int bf, char *k);
int set_bf(int bf, char *k);

#endif // !BLOOM_FILTER_H
