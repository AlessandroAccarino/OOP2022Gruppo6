/******************************************************************************

* Sono dati:
 * 1) una prima struttura dati chiamata SD1 implementata mediante un albero 
 * binario di ricerca  e 
 * 2) una seconda struttura dati chiamata SD2 implementata mediante una tabella hash
 * con indirizzamento chiuso
 * Un elemento di SD1 è una stringa, mentre un elemento di SD2 è costituito da una 
 * coppia chiave-valore di tipo stringa-intero.
 * 
 * Il candidato realizzi un programma che:
 * a) chiede da standard input un numero intero che chiamiamo max
 * b) stampa tutti gli elementi di SD2 ad eccezione
 * di quelli la cui chiave e' presente nei primi max livelli in SD1
 * 
 * Esempio:
 * 
 * Dati in input:
 * SD1: uno, due, tre, quattro, cinque, sei, sette, otto, nove, dieci, undici 
 * SD2: (tre,3), (sette,7), (undici,11), (due,2)
 *
 * max:3 
 *
 * Stampa in output:
 * SD2: (sette,7), (undici,11)
 * 
 * Si noti che nell'esempio gli elementi (tre,3) e (due,2) di SD2 non sono stati stampati
 * in quanto i valori tre e due sono presenti nei primi 3 livelli di SD1.
 *
 * Se, invece max fosse 1, stamperebbe in output
 * SD2: (tre,3), (sette,7), (undici,11), (due,2)
 * in quanto solo la radice (che conterrebbe uno) sarebbe considerata
 * 
 * Il candidato realizzi l'esercizio implementando le seguenti funzioni, il cui
 * corpo vuoto è già predisposto nei file appropriati:
 * 1) hashTable_delete in hashtable.c
 * 2) bst_partial_search in bst.c
 * che cerca un valore nei primi max livelli del BST 
 * (ovviamente il primo livello è quello della radice) e restituisce
 *   un puntatore all’elemento che contiene il valore (se trovato) o NULL 
 * (se non trovato o se max = 0)
 * 3) hashTable_partial_print in hashtable.c
 * che stampa tutti gli elementi della hash table ad eccezione di quelli la 
 * cui chiave e' presente nei primi max livelli di un bst passato in input
 * 4) la logica applicativa all'interno del main
 * 
 * 
 * Il candidato può (ed è incoraggiato a) cambiare il contenuto delle strutture
 * dati per testare approfonditamente la propria soluzione.
 *
 * Si noti che sono presenti due tipi generici, TInfo1 e TInfo2, 
 * il primo utile per SD1 ed il secondo utile per SD2. 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "info.h"
#include "hashtable.h"
#include "bst.h"

#define INITIAL_HT_SIZE 10

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    // Creo le strutture dati
    TBST SD1 = bst_create();
    THashTable* SD2 = hashTable_create(INITIAL_HT_SIZE);
    // Popolo le strutture dati
    SD1 = bst_insert(SD1, "uno");
    SD1 = bst_insert(SD1, "due");
    SD1 = bst_insert(SD1, "tre");
    SD1 = bst_insert(SD1, "quattro");
    SD1 = bst_insert(SD1, "cinque");
    SD1 = bst_insert(SD1, "sei");
    SD1 = bst_insert(SD1, "sette");
    SD1 = bst_insert(SD1, "otto");
    SD1 = bst_insert(SD1, "nove");
    SD1 = bst_insert(SD1, "dieci");
    SD1 = bst_insert(SD1, "undici");
    hashTable_insert(SD2, "tre", 3);
    hashTable_insert(SD2, "sette", 7);
    hashTable_insert(SD2, "undici", 11);
    hashTable_insert(SD2, "due", 2);
    
    // Stampo lo stato iniziale della struttura
    printf("Dati in input:\n");
    printf("SD 1: ");
    bst_print(SD1);
    printf("\n");
    printf("SD 2: ");
    hashTable_print(SD2);
    printf("\n");
    
    int max;
    printf("Inserisci un massimo a piacere\n");
    scanf("%d", &max);
    
    // Stampo lo stato finale della struttura
    printf("\n");
    printf("Dati in output:\n");
    printf("\n");

    // INSERIRE QUI LA LOGICA APPLICATIVA --------------------------------------
 
    printf("Max = %d\n", max);
    
    hashTable_partial_print(SD2, SD1, max);

    // FINE --------------------------------------------------------------------
    printf("\n");
    
    // Distruggo le strutture dati
    bst_destroy(SD1);
    hashTable_destroy(SD2);
    
    return (EXIT_SUCCESS);
}
