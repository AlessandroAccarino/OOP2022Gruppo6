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

Tabelle Hash Complessità ----------------------------------------------------------

tabella ad indirizzamento diretto 
facile di realizzazione
possono funzionare solo se la chiave è effettivamente un numero intero e
non possano esistere duplicati di chiavi, in questo caso la chiave e come se
fosse l'indice di un vettore, ciò permette di avere un ottima Complessità computazionale
ma con una pesante occupazione spaziale

N_m (Complessità spaziale) = k/m
con k = numero di chiavi impiegate
con m = numero di elementi (e chiavi)

la Complessità computazionale delle operazioni di ricerca, inserimento e cancellazione
è O(1)

Infatti, dalla chiave si ottiene in tempo costante la posizione del vettore nel
quale è contenuta l’informazione da ricercare, inserire o cancellare.

-- Tabelle a indirizzamento indiretto

Nascono con l'intento di preservare l' elevata efficienza computazionale delle tabelle dirette
ma cercando anche di risparmiare sulla memoria occupata
L'idea è quella di una funzione "Hash" che a partire da una data chiave sia in
grado di generare la posizione del vettore nel quale è memorizzata l'informazione

La migliore funzione Hash deve godere della propriettà di essere iniettiva
purtroppo non esiste una funzione perfetta...
se generà lo stesso indice di chiave allora genera una collissione

Per risolvere questo problema, si ipotizza a creare una struttura dati
che possa rappresentare anche le eventuali chiavi collidenti

- Liste di collisione (indirizzamento chiuso):
gli elementi collidenti sono contenuti all'interno di liste esterne alla tabella stessa

- indirizzamento aperto:
Tutti gli elementi sono contenuti nella tabella, eventuali collissioni sono gestiti
mediante l'occupazzione di posizioni sucessive


il principale vantaggio dell'indirizzamento aperto è quello di evitare
completamente l'impiego di puntatori e di strutture esterne, ma lo svantaggio
è quello di non consentire in alcun modo di aggiungere elementi ulteriori alla 
tabella una volta raggiunta la sua capienza massima, mentre in quello chiuso
accetando un degrado prestazionale, è sempre possibile aggiungere ulteriori elementi alla lista
essendo queste strutture dinamiche, quindi espandibili all'occorenza

Dal punto di vista computazonale i due metodi sono molto simili

Se la tabella contiene n chiavi e il bucket, o la sequenza di scansione,
ha dimensione m, e la distribuzione uniforme, tutte le liste di collisione 
hanno la medessima lunghezza, pari a n/m allora -> O(n/m)
per il worst case, perchè ciò significherebbe scorrere tutto il bucket o l'intera 
sequenza di scansione per trovare l'elemento cercato

In caso di una distribuzione poco uniforme nei bucket (liste di collisione)
si avrà un degrado prestazionale nel worst case da O(n/m) a O(I_max)
I_max = lunghezza della più lunga lista di collisione

-- indirizzamento chiuso

Per le operazioni di acesso e modifica di una tabella ad indirizzamento chiuso
sono svolte in due fasi:

Si applica la funzione di hash alla chiave per individuare il bucket interessato
dall'operazione 

quando si effettua l'operazione sulla struttura dati dinamica contenuta nel bucket

La struttura dati per una tabella hash a indirizzamento chiuso richiede un vettore di
bucket, in cui ciascun bucket contiene una lista concatenata, il vettore sarà allocato 
dinamicamente, nella struttura dati perciò sarà contenuto il puntatore al primo elemento
del vettore dei bucket, e il numero di bucket

L'inizializzazione della tabella hash richiede innanzitutto l'allocazione della
struttura che rappresenta la tabella, quindi l'allocazione del vettore di bucket, con
una dimensione scelta attraverso un parametro, e infine l'inizializzazione di ciascuna 
delle liste associate ai bucket.

La deallocazione di una tabella hash a indirizzamento chiuso richiede preliminarmente
la deallocazione di ciascuna delle liste associate ai bucket.
Compiuta questa operazione, è possibile deallocare il vettore di bucket e quindi 
la struttura che rappresenta la tabella stessa.

-- HT SEARCH (comp. computazionale)

Le operazioni necessarie per la determinazione del bucket da usare non dipendono
dal numero n di elemnti presenti nella tabella, quindi la relativa Complessità
temporale è O(1)

Se indichiamo con m il numero di bucket, assumendo che la funzione di hash produca
una distrubuzione uniforme delle chiavi, avremo che la lunghezza media 
della lista è n/m, e quindi la Complessità nel caso medio è:

T(n) = O(1) + O(n/m) = O(n/m)

se scegliamo il numero di bucket in modo che sia proporzionale al massimo
numero di elementi che prevediamo di inserire nella tabella avremo

T(n) = O(1)

se tutti gli n elementi scelti nella tabella sono associati ad un unico bucket
e la chiave cercata appartiene al medessimo bucket
la lista del bucket possiede lunghezza = n, e l'operazione di ricerca richiedera tempo:

T(n) = O(n)

ragionamento analogo per l'operazione di inserimento e cancellazione

per la visita di una tabella:

T(n) = O(n)

sia per avarege e worst case

- SEARCH:
La ricerca del valore associato a una chiave in una tabella a indirizzamento chiuso si
effetua semplicemente individuando il bucket corrispondente alla chiave, ed effetuando
la ricerca nella lista che possiede il bucket

è utile far ritornare l'indirizzo del campo "value" dell'informazione ricercata
la restituzione del puntatore porta questi vantaggi:

è possibile segnalare la chiave non è stata trovata utilizzando il puntatore NULL come 
valore di ritorno

il chiamante può cosi modificare il valore associato alla chiave

La funzione inizia con il calcolo dell'indice del bucket corrispondente alla chiave cercata
Una volta determinato il bucket da utilizzare, si inizia a scorrere il bucket fino 
a qunado non si trova il valore interessato.

- INSERT:
bisogna individuare il bucket interessato, e quindi l'inserimento nella lista associata
al bucket.
Bisogna verificare, prima della creazione di un nuovo nodo nella lista, che essa non contenga
già un elemento con la stessa chiave: in quest'ultimo caso infatti l'operazione di inserimento
deve semplicemente sostituire il valore associato all'interno del nodo esistente, per garantire
la proprietà che esiste al più un unico valore in corrispondenza di una determinata chiave

Viene determinato l'indice del bucket a cui fare riferimento, e viene cercata la chiave 
nella lista associata al bucket

se il nodo contenente la chiave non è stato trovato, viene aggiunto un nuovo nodo alla 
lista; se invece il nodo è stato trovato, l'informazione corrispondente viene sostituita
usando un' assegnazione al campo info.

- DELETE
Bisogna individuare il bucket corrispondente alla chiave, e quindi la rimozione 
dalla lista corrispondente

La funzione deve calcolare l'indice del bucket corrispondente alla chiave, e poi 
rimuovere il nodo corrispondente dalla lista (se presente)

- VISIT
Si intende la stampa di tutti gli elementi presenti nella tabella.
la visita di una tabella esamina gli elementi senza avere un ordine significativo
per l'utente, esso non corrisponde all'ordine di inserimento degli elementi, e ne esiste
una relazione tra la chiavi
La realizazzione è semplice, presenta due cicli annidati
Il ciclo esterno, scorre il vettore dei bucket della tabella
Il ciclo interno, scorre i nodi della lista associata al bucket
Il corpo del ciclo interno, poi effettua la stampa della coppia chiave-valore

--- indirizzamento aperto 

cioeè nel caso peggiore cè una sola lista dato che ci sono tuttte collisioni
per il migliore non c'è nessuna

e n/m ha praticamente n>>>>>di m
quindi Theta(n)

La struttura dati per una tabella a indirizzamento aperto prevede che la chiave e il 
valore siano memorizzati direttamente all'interno del bucket.
Inoltre gli algoritmi devono anche essere in grado di determinare se un bucket è occupato
oppure libero per cui è necessario associare un'informazione logica che indichi questa 
condizione a ciascun bucket.

Olre al vettore di bucket e alla sua dimensione, la tabella deve anche mantenere il numero 
di elementi presenti, in modo da poter controllare se è necessario un ridimensionamento 
del vettore di bucket.

L'operazione di inizializzazione di una tabella hash a indirizzamento aperto non richiede
commenti particolari; una volta allocata la struttura dati che rappresenta la tabella, e il
vettore di bucket, occore semplicemente contrassegnare ciascun bucket come libero.
 
- Search
La ricerca in una tabella a indirizzamento aperto si svolge individuando l'indice
del bucket che dovrebbbe contenere la chiave cercare, si ispeziona il bucket in questione 
e i sucessivi fino a che non si verifica una delle seguenti condizioni:

Il bucket contiene la chiave cercata, la ricerca termina con sucesso.

Il bucket è vuoto, la chiave cercata non è presente nella tabella

- Insert
Più complicata di quella chiusa perché deve rispettare i vincoli sul fattore di carico
e della gestione delle collisioni.

L'algoritmo deve vedere se la chiave è gia presente nella tabella, effettuando un'operazione di ricerca
In caso affermativo, è necessario cambiare il solo valore associato, evitando di dover inserire una nuova chiave

Se invece occore inserire una nuova chiave, l'algoritmo deve verificare se l'aggiunta 
del nuovo elemento invaliderebbe il limite massimo della fattore di carico della tabella
se fosse cosi, allora bisognerà prima ridimensionare la tabella con un operazione
di ridimensionamento

Infine può essere effetuato l'inserimento della nuova chiave, prima occore individuare il bucket
di destinazione, se questo fosse già occupato si procede a esaminare il bucket sucessivo fino a trovare
una posizione libera, in cui verrano inserire le informazioni (chiave-valore)

- Ridimensionamento
Un operazione semplice, occore in primis allocare un nuovo vettore di bucket, quindi
gli elementi presenti nel vecchio vettore di bucket devono essere inseriti nel nuovo vettore

- Delete

Purtroppo non è sufficiente individuare il bucket che contiene la chiave da rimuovere
e contrassegnare il bucket come non utilizzato, in quanto il "buco" cosi creato potrebbe
rendere irragiungibile una chiave il cui bucket di appartenenza dovrebbe trovarsi prima 
del bucket svuotato, ma che è stata inserita in un bucket sucessivo per effetto delle collissioni

abbiamo due soluzioni
Il bucket dell'elemento da cancellare non viene contrassegnato come "inutilizzato" ma come 
"cancellato".
I bucket cancellati vengono considerati come pieni dalle sucessive operazioni di ricerca, e come
vuoti dalle operazioni di inserimento.
la soluzione è semplice da implementare, ma rende poco efficiente la ricerca in una tabella
in cui sono state fatte troppe cancellazioni.

Un alternativa è: l'algoritmo cerca nella sequenza di ispezione che parte dal bucket cancellato
se c'è un altro elemento che può essere spostato per riempire lo spazio reso vuoto
Se fosse cosi, l'elemento viene spostato in tale bucket, ovviamente questo crea un'altro bucket
vuoto per il quale occore ripetere la ricerca di un potenziale occupante.
L'operazione termina quando nella sequenza di ispezione viene trovato un bucket vuoto.

Ciò permette di mantenere un'elevata efficienza nelle operazioni di ricerca, a discapito 
di quella della cancellazione. 

- Visit
La visita di una tabella a indirizzamento aperto è piuttosto semplice: si effetua
la scansione del vettore di bucket, operando su tutti i bucket che risultano utilizzati.


NOTE:

1. Il tempo di esecuzione è pari a O(n/m) nel caso dell'inserimento con lista
ordinata, dove n sono i bucket occupati e m i bucket disponibili
(la grandezza del bucket array). Quindi essendo m=n/logn abbiamo O(logn).

Nel caso dell'albero binario ordinato abbiamo O(1).


*/
