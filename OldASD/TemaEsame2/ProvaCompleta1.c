/* 
 *
 *      TRACCIA 3 (Completa)
 *
 * Una biblioteca deve riorganizzare alcuni elenchi di libri tra cui elenco1 
 * (un BST), elenco2 (una HT) ed elenco3 (una lista).
 * In ciascuna struttura un libro e' rappresentato da
 * un codice ISBN numerico (campo chiave) e da un titolo. 
 * 
 * Si dovra' realizzare un programma che individui tutti i libri presenti in 
 * entrambi gli elenchi, li stampi in ordine crescente di ISBN (completare nella
 * funzione main) e che sostituisca in elenco2
 * il codice ISBN di un libro in base al titolo.
 * Infine, da elenco3 verranno rimossi tutti i libri con ISBN pari e anche l'elemento
 * con ISBN piu' piccolo.
 * Per realizzare tale programma occorre sviluppare le seguenti funzioni.
 * 
 * 1) BSTHTdupList(bst, ht, list): funzione RICORSIVA che copia in list (lista 
 *    ordinata) tutti i libri che sono presenti contemporaneamente sia in bst che 
 *    in ht (fa fede il codice ISBN).
 * 
 * 2) HTchangeKey(ht, value, newKey): funzione ITERATIVA che sostituisce in ht
 *    la chiave associata a value con la nuova chiave newKey.
 *    Se value non e' presente in ht allora non fa nulla.
 *    Se value compare piu' di una volta in ht allora alle fine ci sara' una sola
 *    coppia (newKey, value). Se newKey e' gia' presente in ht allora il vecchio valore
 *    viene rimosso e poi viene inserito il nuovo valore.
 *
 * 3) listDeleteEven(list): funzione RICORSIVA che elimina da list tutti i 
 *    libri con ISBN pari. Restituisce la lista aggiornata.
 *
 * 4) deleteMinList(list): funzione che elimina il libro con ISBN piu' basso.
 * 
 * I prototipi delle funzioni sono gia' presenti nel file main.c. La funzione main 
 * e' gia' fornita e include del codice di test che riempie le strutture con i dati 
 * di alcuni studenti e richiama le funzioni necessarie. E' altresi' fornito il codice 
 * delle strutture dati richieste. Si suggerisce di testare le funzioni anche con 
 * valori diversi da quelli forniti.
 *
 * Per la consegna, copiare il codice sviluppato (all'interno del file main.c)
 * e incollarlo nella apposita casella di testo su e-learning (Moodle).
 */
 
 /*COGNOME: .............
 * NOME: ................
 * MATRICOLA: ...........
 */

#include <stdio.h>
#include <string.h>
#include "THT.h"
#include "TBST.h"
#include "TArray.h"

int infoIsEven(TInfo num){
TInfo temp;
TInfo temp2 = num;
temp2.key = temp2.key%2;
temp.key = 0;

	if(infoEqual(temp2, temp))
		return 1;
	else
		return 0;
}

TList BSTHTdupList(TBST bst, THT *ht, TList list) {

    if (bst == NULL){
        
        return list;
    }
    
    if (HTsearch(ht, bst->info.key) != NULL){
        
      list = listInsert(list, bst->info);
        
    }
    
    list = BSTHTdupList(bst->left, ht, list);
    list = BSTHTdupList(bst->right, ht, list);
    
    return list;
}

void HTchangeKey(THT* ht, TValue value, TKey newKey) {
    
    for (int i = 0; i < ht->n_bucket; i++){
        for (TNode *node = ht->bucket[i]; node != NULL; node = node->link){

          if (!strcmp(value.titolo, node->info.value.titolo)){
              
             node->info.key = newKey;
        
          }
       
         }
        
    }
}


TList listDeleteEven(TList list) {

    if (list == NULL){
        
        return list;
    }
    
    list->link = listDeleteEven(list->link);

    if(infoIsEven(list->info)){
       
       list = listDelete(list, list->info);
        
    }
    
    return list;
}

TList deleteMinList(TList list) {
    
return list = listDelete(list, list->info);
    
/*
TList temp = list;

TInfo min = temp->info;

while(temp != NULL){
    
    if(infoLess(temp->info, min)){
        
       TInfo min = temp->info; 
        
    } 
    
    temp = temp->link;
}
  
   //TNode *canc = listSearch(list, min);
   list = listDelete(list, min);
*/ 
}



int main() {
    TBST elenco1 = BSTcreate();
    elenco1 = BSTinsert(elenco1, (TInfo) {3233, "Pippi Calzelunghe"});
    elenco1 = BSTinsert(elenco1, (TInfo) {2372, "Orgoglio e pregiudizio"});
    elenco1 = BSTinsert(elenco1, (TInfo) {3432, "Finzioni"});
    elenco1 = BSTinsert(elenco1, (TInfo) {4223, "Delitto e castigo"});
    elenco1 = BSTinsert(elenco1, (TInfo) {1445, "Il processo"});
    elenco1 = BSTinsert(elenco1, (TInfo) {2234, "Madame Bovary"});
    elenco1 = BSTinsert(elenco1, (TInfo) {1238, "L'amore ai tempi del colera"});
    elenco1 = BSTinsert(elenco1, (TInfo) {6643, "Il vecchio e il mare"});
    elenco1 = BSTinsert(elenco1, (TInfo) {1111, "Anna Karenina"});

    THT* elenco2 = HTcreate(5);
    HTinsert(elenco2, 3357, (TValue) {"Il rosso e il nero"});
    HTinsert(elenco2, 7675, (TValue) {"Alla ricerca del tempo perduto"});
    HTinsert(elenco2, 4222, (TValue) {"Moby-Dick"});
    HTinsert(elenco2, 1445, (TValue) {"Il processo"});
    HTinsert(elenco2, 3233, (TValue) {"Pippi Calzelunghe"});
    HTinsert(elenco2, 3321, (TValue) {"L'uomo senza qualita'"});
    HTinsert(elenco2, 1111, (TValue) {"Anna Karenina"});
    HTinsert(elenco2, 9090, (TValue) {"Le metamorfosi"});
    HTinsert(elenco2, 3432, (TValue) {"Finzioni"});

    printf("Libri in elenco1 (BST):\n");
    BSTprint(elenco1);
    printf("\nLibri in elenco2 (HT):\n");
    HTprint(elenco2);

    TList elenco3 = listCreate();
    printf("\nCopio in elenco3 (lista) i libri contenuti sia in elenco1 che elenco2.");
    elenco3 = BSTHTdupList (elenco1, elenco2, elenco3);
    printf("\nLibri in elenco3 in ordine crescente di ISBN:\n");
    
    /* Completare con la chiamata a funzione corretta */
    listPrint(elenco3);

    TValue titolo = (TValue) {"Il processo"};
    TKey nuovoISBN = 1000;
    printf("\nCambio in elenco2 (HT) il codice di '%s' in %d", titolo.titolo, nuovoISBN);
    HTchangeKey(elenco2, titolo, nuovoISBN);
    printf("\nLibri in elenco2 dopo la modifica:\n");
    HTprint(elenco2);

    elenco3 = listDeleteEven(elenco3);
    printf("\nStudenti in elenco3 (Lista)\n(dopo aver rimosso gli ISBN pari)\n");
    listPrint(elenco3);
    
    elenco3 = deleteMinList(elenco3);
    printf("\nLibri in elenco3 (Lista)\n(tutti quelli di elenco3 tranne ISBN piu' basso)\n");
    listPrint(elenco3);

    BSTdestroy(elenco1);
    HTdestroy(elenco2);
    listDestroy(elenco3);
    return 0;
}
