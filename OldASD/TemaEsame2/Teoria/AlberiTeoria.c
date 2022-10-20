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

Alberi Complessità ----------------------------------------------------------

(n = numero di nodi dell'albero)
-- Bst Visit:

T(1) = c
T(n) = 2T(n/2) + c  = 2[2T(n/2) + c/2 ]+c
= 2^i * T(n/2^i)+ ic

ponendo: i = log(n)
abbiamo: nc + log(n)*c
 
risulta quindi che la Complessità computazionale della visita è: O(n)

-- Bst search:

T(1) = c
T(n) = T(n/2) + c  = T(n/4) + 2c = T(n/2^i)+ic =

ponendo: i = log(n)
abbiamo: c + c*log(n) = O(1) + O(log(n)) 

Best case: O(1)  // L'elemento da cercare è il nodo radice
worst case: O(log(n)) // L'elemento da cercare è una foglia oppure non esiste

n.b essendo n il numero di nodi un albero, il log(n) equivale all'altezza (h) dell'albero.

Attenzione: se l'elemento NON esiste, allora il best case corrisponde al worst case

Lo stesso ragionamento è applicabile sia per l'inserimento e la cancellazione di un nodo

L'algoritmo di ricerca di un'elemento in un BST sfrutta la condizione di ordinamento
dell'albero stesso.
Dovendo cercare un elemento di valore prefissato, si verifica che l'elemento non sia contenuto
nella radice, condizione questa che ci consente di arrestare immediatamente la ricerca.
Nel caso in cui l'elemnto non sia contenuto nella radice, si procede nella ricerca dell'elemento
nel sottoalbero destro, nel caso in cui l'elemento da cercare sia maggiore della radice,
discorso analogo se fosse stato minore, si sarebbe ispezionato il sottoalbero sinistro.
In caso non fosse trovato in uno dei due sotto alberi, allora l'elemento non è presente nell'albero.

-- Bst Insert

Si deve far rispettare la condizione di ordinamento dell'albero, percò si richiede
la preventiva determinazione del punto in cui inserire il nuovo elemento.

perciò si considera l'inserimento come l'aggiunta di un nuovo nodo foglia dell'albero

ciò non modifica la struttura pre-esistente del BST, ma si limita ad aggiungere all'ultimo livello
è più facile da realizzare

• B1) Ricerca del punto dove effettuare l’inserimento della foglia; la nuova foglia
deve essere inserita in una posizione tale da mantenere ancora rispettata la
propriet`a di ordinamento dell’albero. Una procedura semplice per determinare
la posizione di inserimento a partire dalla radice dell’ albero consiste, nello
scegliere, per ciascun nodo visitato, il sottoalbero destro o sinistro a seconda
che il valore da inserire sia rispettivamente maggiore o minore del valore del
nodo corrente. Questo processo termina quando si `e raggiunto il sottoalbero
vuoto. Tale posizione `e quella che deve occupare la nuova foglia per mantenere
soddisfatta la propriet`a di ordinamento

• B2) Creazione di un nodo per accogliere il nuovo valore. Nel nodo creato viene
inserito il nuovo valore e nei campi Left e Right il valore NULL, dal momento
che il nodo inserito `e, come detto in precedenza, una foglia.

• B3) Aggiornamento dei puntatori per collegare il nuovo nodo. Il puntatore da
aggiornare `e quello del successore del nodo da inserire che dovr`a contenere il
riferimento al nodo appena allocato.

-- Bst Delete

La cancellazione di un nodo da un albero presenta una maggiore difficolt`a rispetto
 all’inserimento, poich`e il nodo da cancellare pu`o occupare posizioni diverse

1. il nodo da cancellare `e una foglia dell’albero,
2. il nodo da cancellare ha un solo figlio (indifferentemente il sottoalbero destro o
quello sinistro),
3. il nodo da cancellare possiede entrambi i figli.

Il primo caso `e evidentemente quello pi`u semplice da gestire: in tale situazione
la rimozione del nodo, che consiste nell’eliminazione della foglia in questione, non
comporta alcuna modifica strutturale nell’albero e quest’ultimo continua a soddisfare
il criterio di ordinamento; 

Nel secondo caso, la cancellazione del nodo comporta la necessit`a di collegare
il sottoalbero non vuoto del nodo cancellato con il padre del nodo cancellato. E’
semplice verificare che tale operazione, sebbene appaia ad una prima analisi non
banale, pu`o essere condotta con un unico passo. Basta infatti collegare il sottoalbero
non vuoto del nodo cancellato al posto del nodo cancellato

Il terzo caso `e quello che si verifica allorquando il nodo da cancellare presenta
entrambi i figli;

1. la sostituzione del valore presente nel nodo da cancellare, con il valore minimo
del sottoalbero destro (o in alternativa con il massimo nel sottoalbero sinistro);

2. la cancellazione del valore minimo dal sottoalbero destro (o del massimo dal
sottoalbero sinistro)

-- Bst Visit 

la visita in un albero è ricondotta, infatti alla visita del nodo corrente ed alla
visita ricorsiva dei suoi sottoalberi
(in un ordine relativo che diversifica le tipologie di visita)

In ordine:
• visita simmetrica del sottoalbero sinistro,
• visita del nodo radice,
• visita simmetrica del sottoalbero destro.

Pre-ordine:
• visita del nodo radice,
• visita simmetrica del sottoalbero sinistro,
• visita simmetrica del sottoalbero destro.

Post-ordine:
• visita simmetrica del sottoalbero sinistro,
• visita simmetrica del sottoalbero destro,
• visita del nodo radice.

*/