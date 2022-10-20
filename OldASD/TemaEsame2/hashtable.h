#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "bst.h"


typedef struct SHashTable THashTable;


/* Operazioni su THashTable */

THashTable *hashTable_create (int n);
void hashTable_destroy (THashTable* ht);
TValue *hashTable_search (THashTable* ht, TKey key);
void hashTable_insert (THashTable* ht, TKey key, TValue value);
void hashTable_delete (THashTable* ht, TKey key);
void hashTable_print(THashTable* ht);
void hashTable_partial_print(THashTable *ht, TBST t, int max);
#endif
