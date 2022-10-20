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


/*

ORDINAMENTO INTERNO & ESTERNO:
Una prima distinzione dipende da quale dispositivo viene usato per mantenere la
sequenza di elementi:
Si parla di ordinamento interno (internal sorting) se la sequenza è interamente
contenuta in memoria centrale
Si parla di ordinamento esterno (external sorting) se la sequenza è (almeno in
parte) contenuta in un file.

ORDINAMENTO SUL POSTO & NON SUL POSTO
Una seconda distinzione riguarda l’uso di memoria addizionale durante
l’ordinamento.
Negli algoritmi di ordinamento sul posto (in-place sorting), la sequenza ordinata
sostituisce la sequenza iniziale, occupando la medesima struttura dati e utilizzando
al più strutture dati aggiuntive la cui occupazione di memoria sia O(logn).
Negli algoritmi di ordinamento non sul posto (out-of-place sorting) invece è
richiesta la creazione di altre strutture dati per memorizzare temporaneamente la
sequenza, la cui occupazione di memoria è 𝛀(n).

-- SELECTION SORT

L’algoritmo cerca il minimo dell’array di partenza, e lo posiziona nella prima
posizione dell’array ordinato.
Quindi sceglie il minimo tra elemen5 rimanen5, e lo posiziona nella seconda
posizione dell’array ordinato, e così via.
Questo algoritmo risulta estremamente semplice da implementare e da analizzare,
anche se la sua complessità computazionale lo rende uGlizzabile in praGca solo per
array molto piccoli.

-- INSERTION SORT
L’algoritmo di ordinamento per inserimenG successivi, o InserGon sort, si basa sulla
riduzione dell’ordinamento a un problema più semplice: l’inserimento in ordine.
È sufficiente prelevare uno alla volta gli elemenG dell’array e inserirli in un nuovo
array (inizialmente vuoto) uGlizzando l’inserimento in ordine.
Poiché l’array vuoto è banalmente ordinato, e l’inserimento in ordine produce un
array ordinato se applicato a un array di partenza ordinato, è facile verificare che al
termine degli inserimenG oOerremo nel nuovo array una versione ordinata
dell’intero array di partenza.

-- BUBBLE SORT
Il nome deriva dalla metafora che ha ispirato l’algoritmo:
come le bollicine di anidride carbonica all’interno di una bevanda gasata vengono spinte
verso l’alto perché hanno un peso specifico minore del liquido che le circonda (per il
principio di Archimede), così l’algoritmo sposta verso la fine dell’array gli elementi che
hanno un valore più alto di quelli adiacenti, finché l’array è ordinato.
L’algoritmo esamina in ordine tutte le coppie di elementi dell’array:
(a 0 ,a 1 );(a 1 ,a 2 );...;(a i ,a i+1 );...;(a n-2 ,a n-1 )
Se nell’esaminare la coppia (a i ,a i+1 ) si riscontra che vale la relazione greater(a i ,a i+1 ) – e
quindi la coppia non è localmente ordinata – allora, l’algoritmo scambia di posto a i e a i+1
prima di passare alla coppia successiva.

Se nessuna delle coppie è fuori ordine vuol dire che l’array è già ordinato, e
l’algoritmo termina.
Altrimenti, se è stata trovata almeno una coppia di elementi adiacenti localmente
fuori ordine, al termine dell’esame di tutte le coppie l’algoritmo ricomincia da capo.
Quindi:
1. esamina le coppie di elementi (ai, a i+1 ) per ogni i da 0 a n-2; se a i > a i+1 , scambia
di posto a i e a i+1 ;
2. se al passo 1 non è stato fatto nessuno scambio (segnalato mediante una flag),
l’array è ordinato e l’algoritmo termina; altrimenti ricomincia dal passo 1.

-- MERGE SORT
L’ordinamento per fusione o Merge Sort riconduce il problema dell’ordinamento
al problema della fusione di array ordinati, che può essere formulato come segue:
Date due sequenze ordinate a0, . . . , an e b0, . . . , bm, vogliamo ottenere una nuova
sequenza, anch’essa ordinata, di n+m elementi c0, . . . , cn+m, che contenga tutti gli
elementi delle due sequenze di partenza.
Una volta trovata una soluzione per questo problema, possiamo utilizzarla per
risolvere il problema dell’ordinamento attraverso una decomposizione ricorsiva:
dividiamo la nostra sequenza da ordinare in due parti, che ordiniamo
separatamente attraverso la ricorsione; quindi fondiamo le due parti ordinate in
un’unica sequenza anch’essa ordinata

-- QUICK SORT
Sfortunatamente, l’algoritmo di Merge Sort non effettua l’ordinamento sul posto (almeno
per quanto riguarda gli array)
Il Quick Sort mantiene la stessa efficienza nel caso medio, ma effettua l’ordinamento sul
posto; perciò è particolarmente adatto all’ordinamento di array. Da queste proprietà deriva
il suo nome: Quick Sort, letteralmente “ordinamento rapido”.
Anche il Quick Sort si basa su una decomposizione ricorsiva del problema dell’ordinamento.
Mentre il Merge Sort prevede una fase di Divide estremamente semplice, e una fase di
Combina più complicata, nel Quick Sort è la suddivisione in sotto-problemi ad essere
complicata, mentre la combinazione delle soluzioni diventa banale

*/