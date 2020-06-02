#ifndef _COLLECTIONS_HTAB_H_
#define _COLLECTIONS_HTAB_H_

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HTAB_DEFAULT_INIT_SIZE				32

typedef struct HtabNode {

	struct HtabNode *next;
	void *key;
	size_t key_size;
	void *val;
	size_t val_size;

} HtabNode;

typedef struct HtabBucket {

	struct HtabNode *start;
	size_t size;

} HtabBucket;

typedef struct Htab {

	HtabBucket **table;

	size_t size;
	size_t count;

	size_t (*hash)(const void *key, size_t key_size, size_t table_size);
	int (*compare)(const void *k1, size_t s1, const void *k2, size_t s2);

	// TODO: allow for key value copy
	// int (*copy)(void **dst, const void *src, size_t sz);

	// method to delete the data
	void (*delete_data)(void *data);

} Htab;

// creates a new htab
// size --> initial htab nodes size, the default is 7
// hash_f --> ptr to a custom hash function, NULL to use default
// compare_f -> ptr to a custom value compare function, NULL to use default
// kcopy_f --> ptr to a custom function to copy keys into the htab (generate a new copy), NULL to us ethe same key
// allow_copy --> select if you want to create a new copy of the values
// vcopy_f --> ptr to a custom function to copy values into the htab (generate a new copy), NULL to use the same value
// destroy --> custom function to destroy copied values
// extern Htab *htab_init (unsigned int size, Hash hash_f, Compare compare_f, Copy kcopy_f, 
// 	bool allow_copy, Copy vcopy_f, void (*destroy)(void *data));

extern Htab *htab_create (size_t size,
	size_t (*hash)(const void *key, size_t key_size, size_t table_size),
	int (*compare)(const void *k1, size_t s1, const void *k2, size_t s2),
	void (*delete_data)(void *data));

// inserts a new value to the htab associated with its key
extern int htab_insert (Htab *ht, const void *key, size_t key_size, 
	void *val, size_t val_size);

// returns a ptr to the data associated with the key
extern void *htab_get_data (Htab *ht, const void *key, size_t key_size);

// removes the data associated with the key from the htab
extern void *htab_remove (Htab *ht, const void *key, size_t key_size);

// checks if the htab containes the matching value for the key
extern bool htab_contains_key (Htab *ht, const void *key, size_t key_size);

// destroys the htb and all of its data
extern void htab_destroy (Htab *ht);

// extern int htab_get (Htab *ht, const void *key, size_t ksz, void **val, size_t *vsz);

extern void htab_print (Htab *htab);

#endif