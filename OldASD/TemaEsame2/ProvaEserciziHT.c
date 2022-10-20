#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "TInfo.h"
#include "THT.h"

/* ESERCIZIO 1
 * Scrivere una funzione che, se esiste un valore associato con una chiave key
 * ne incrementa di 1 il valore, altrimenti inserisce nella tabella hash ht il dato (key, 1).
 */

void HTincrease(THT *ht, TKey key) {   
    TValue *v = HTsearch(ht, key);
    if (v == NULL)
        HTinsert (ht, key, 1);
    else
        (*v)++;
}

/* ESERCIZIO 2
 * Scrivere una funzione che prende in input un puntatore a una HT
 * oltre che i valori key e newKey. Se esiste un elemento nella HT
 * con chiave key allora sostituisce la sua chiave con newKey.
 */

void changeKey(THT *ht, TKey key, TKey newKey) {
    TValue *v = HTsearch(ht, key);
    if (v != NULL) {
        HTinsert(ht, newKey, *v);
        if (key != newKey)
            HTdelete(ht, key);
    }
}

/* ESERCIZIO 3
 * Scrivere una funzione che restituisce una lista (ordinata per chiave) che 
 * include tutte le coppie (chiave, valore) di una hash table per cui la chiave e' 
 * compresa tra due valori min e max.
 */

TList HTextractList(THT* ht, TKey min, TKey max) {
    TList list = listCreate();
    TInfo imin = {min}, imax = {max};
    for (int i = 0; i < ht->n_bucket; i++)
        for (TNode *node = ht->bucket[i]; node != NULL; node = node->link)
            if (!infoLess(node->info, imin) && !infoGreater(node->info, imax))
                list = listInsert(list,node->info);
    return list;
}

/* ESERCIZIO 4
 * Scrivere una funzione che inserisce in una hash table ht tutte le coppie (chiave, valore)
 * di una lista solo se la chiave non e' gia'  presente in ht.
 */

void HTmergeList(THT* ht, TList list) {
    if (list == NULL)
        return;
    HTmergeList(ht, list->link);
    if (HTsearch(ht, list->info.key) == NULL)
        HTinsert(ht, list->info.key, list->info.value);
}

/* 
 * Codice di test
 */

int main (int argc, char **argv)
{

    THT *ht = HTcreate (10);


    /* Inserire le chiamate delle funzioni sviluppate */
  
    HTincrease(ht, 1000);
    HTincrease(ht, 1111);
    HTincrease(ht, 1111);
    HTincrease(ht, 1871);
    HTincrease(ht, 1171);
    printf("Hash Table dopo gli increase: ");
    HTprint(ht);
    
    changeKey (ht, 1000, 1001);
    changeKey (ht, 1111, 1871);
    printf("\nHash Table dopo i changeKey: ");
    HTprint(ht);
    
    TList list = HTextractList(ht, 1000, 1500);
    printf("\nLista degli elementi con chiave tra 1000 e 1500: ");
    listPrint(list);
    
    listDestroy(list);
    list = listCreate();
    list = listInsert(list, (TInfo) {2020, 5.22});
    list = listInsert(list, (TInfo) {1870, 6.22});
    list = listInsert(list, (TInfo) {1171, 5.99});
    list = listInsert(list, (TInfo) {1386, 8.17});
    list = listInsert(list, (TInfo) {1001, 2.99});
    printf("Lista degli elementi da inserire: ");
    listPrint(list);
    
    HTmergeList(ht, list);
    printf("Hash Table dopo l'inserimento: ");
    HTprint(ht);
    printf("\nStruttura Hash Table:\n");
    HTprintStructure(ht);
    
    HTdestroy(ht);
    listDestroy(list);

  return 0;
}
