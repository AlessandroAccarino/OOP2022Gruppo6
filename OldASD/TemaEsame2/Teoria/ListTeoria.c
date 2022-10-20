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

Liste ordinate ----------------------------------------------------------
complessità computazionale:

per la ListInsert:
T(1)=c
T(n)=T(n-1)+c= T(n-2)+2c=T(n-i)+ic
Ponendo i= n-1 
abbiamo: =T(n-n+1)+(n-1)c= T(1) +nc -c 

La complessità computazionale è O(n) poichè la funzione dipende da n.
idem per il caso avarege
Nel caso migliore è O(1), perché viene inserito all'inizio della lista

Discorso analogo per la ListDelete, per la ListSearch e la ListVisit!

-- Spiegazione visita di list
• Divide: la divisione del problema deve essere realizzata in modo tale da rag-
giungere il caso base. Quest’obiettivo `e conseguito riducendo ricorsivamente la
lista l alla lista l′ ottenuta eliminando da l il suo elemento di testa. Quindi, nel
caso induttivo la visita di l `e decomposta nel pi`u semplice problema della visita
di l′.
• Caso Base: il caso base `e quello che si riferisce alla stampa di una lista vuota;
in questo caso non bisogna effettuare alcuna operazione.
• Impera: si ipotizza che il problema figlio, consistente nella visita di l′, fornisca
il risultato corretto.
• Combina: la soluzione al problema padre `e ottenuta visitando il primo elemento
della lista l e poi visitando la lista l′, invocando quindi la soluzione del problema
figlio, corretta per l’ipotesi della fase precedente.

-- Ricerca di List
• Divide: la divisione del problema deve essere realizzata in modo tale da rag-
giungere il caso base. Quest’obiettivo `e conseguito riducendo ricorsivamente la
lista l alla lista l′ ottenuta eliminando da l il suo elemento di testa. Quindi, nei
casi non banali, il problema della ricerca di un elemento in l `e decomposto nel
pi`u semplice problema della ricerca dell’elemento in l′.
• Caso Base: il problema della ricerca `e banale quando la lista `e vuota, quando il
primo elemento della lista `e pi`u grande di quello da cancellare o ancora quando
l’elemento ricercato `e proprio il primo elemento della lista. Nei primi due casi
la ricerca pu`o terminare in quanto l’elemento ricercato certamente non esiste.
Anche nel terzo caso la ricerca termina, ma stavolta con successo.
• Impera: Come gi`a detto in precedenza, si ritiene, per ipotesi induttiva, che il
problema figlio consistente nella ricerca dell’elemento in l′, fornisca il risultato
corretto.
• Combina: La soluzione al problema padre `e allora ottenuta verificando che il
primo elemento di l non sia quello cercato; in caso negativo, se l’elemento esso
esiste `e presente in l′ e quindi, sempre in tal caso, la soluzione del problema
padre coincide con quella del problema figlio.

-- inserimento di List
• Divide: la divisione del problema `e realizzata come nelle funzioni precedente-
mente illustrate.
• Caso Base: e’ da premettere che il problema dell’inserimento di un elemento in
una lista ordinata `e banale quando la lista `e vuota o quando il primo elemento
della lista `e maggiore dell’elemento da inserire; in queste circostanze l’inserimen-
to va effettuato in testa alla lista, allocando opportunamente un nuovo nodo,
che avr`a come successore la lista iniziale.
• Impera: per ipotesi induttiva il problema dell’inserimento dell’elemento in l′ `e
risolto correttamente.
• Combina: Se non ci troviamo nei casi base, vuol dire che l’elemento di testa di l,
se esiste, `e pi`u piccolo dell’elemento da inserire e quindi la soluzione del problema
padre `e ricondotta all’inserimento nella lista l′; quest’ ultimo problema, per
ipotesi induttiva, `e risolto correttamente. Bisogna osservare che l’inserimento
in l′ pu`o aver cambiato il puntatore di testa della lista, e pertanto la soluzione
al problema padre consiste semplicemente nell’aggiornamento del campo link
dell’elemento di testa di l.

-- cancellazone di List
• Divide: Divide: la divisione del problema `e realizzata come nelle funzioni prece-
dentemente illustrate. . Quest’obiettivo `e conseguito riducendo ricorsivamente
la lista l alla lista l ottenuta eliminando da l il suo elemento di testa. Quindi,
nei casi non banali, la cancellazone in l `e decomposto nel pi`u semplice problema
della cancellazione l′.
• Caso Base: il problema della cancellazione `e banale quando la lista `e vuota,
oppure quando il primo elemento della lista `e pi`u grande di quello da cancellare
o ancora quando l’elemento da cancellare `e proprio il primo elemento della lista.
Nei primi due casi la cancellazione non pu`o essere effettuata in quanto l’elemento
da cancellare non esiste, e di conseguenza la lista rimane inalterata. Nel terzo
caso, invece, la cancellazione viene effettuata in testa, prima logicamente e poi
fisicamente.
• Impera: si ritiene, per ipotesi induttiva, che il problema della cencellazione in
l′ sia risolto correttamente e, sulla base della soluzione corretta a tale problema
si ricava la soluzione al problema della cancellazione dell’elemento nella lista l.
• Combina: Se non ci troviamo nei casi banali vuol dire che l’elemento di testa
di l, se esiste, `e pi`u piccolo dell’elemento da cancellare e quindi la soluzione
del problema padre `e ricondotta alla cancellazione nella lista l′. Quest’ ultimo
problema `e risolto correttamente nella fase di impera; l’elemento da cancellare,
se esiste, `e cancellato correttamente in l′. Bisogna solo osservare che la cancella-
zione in l′ pu`o aver cambiato il puntatore di testa a l’, e pertanto la soluzione al
problema padre consiste semplicemente nell’aggiornamento del campo link del-
l’elemento di testa di l con il nuovo valore del puntatore a l′. La lista risultante
dalla cancellazione `e ovviamente l.
*/