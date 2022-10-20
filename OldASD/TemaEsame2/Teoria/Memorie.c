/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    printf("Hello World");

    return 0;
}



/* 

TIPI DI MEMORIA IN C:

• Memoria allocata a tempo di compilazione
1. Memoria statica
• Memoria allocata a tempo di esecuzione
2. Stack (pila)
3. Memoria dinamica (heap)
• Normalmente, un programma usa tutti e tre i meccanismi

-- MEMORIA STATICA:

Le variabili hanno un indirizzo assoluto, mantenuto per tutta la durata
dell’esecuzione
• Nella memoria statica vengono allocate:
• variabili globali
• costanti determinabili a tempo di compilazione
• non vale per le costanti definite con #define tramite direttive al pre-processore (effettua
letteralmente la copia del valore assegnato all’interno del codice)
• tabelle usate dal supporto a run-time (per type checking, garbage collection)

• Ad ogni variabile (locale o globale) viene assegnato un indirizzo univoco
• Le variabili locali di una funzione mantengono il valore anche dopo la fine della
stessa
Svantaggi:
• Possibili problemi con l’accesso alle variabili in base alla loro visibilità (scope)
• Non permette la ricorsione (in maniera sicura)
• Le varie chiamate ricorsive di una stessa procedura devono avere ciascuna uno
spazio privato di memoria
• per conservare una copia delle variabili locali: ogni chiamata ricorsiva le può modificare in
modo diverso
• Forza all’utilizzo di più spazio del necessario:
• costringe ad allocare spazio per tutte le variabili di tutto il codice, di volta in volta, solo una
piccola parte di queste è attiva (quelle associate alle procedure aperte)
• non permette strutture dati dinamiche
Vantaggi:
accesso diretto e veloce a tutte le variabili

-- STACK
• La memoria stack è usata per memorizzare i record di attivazione
delle funzioni (RdA)
all'inizio viene salvato il record di attivazione del main
• Il record di attivazione è costituito da:
• i parametri formali
• le variabili locali
• l’indirizzo di ritorno (Return Address, RA) che indica il punto a cui tornare (nel
codice del chiamante) al termine della funzione, per permettere al chiamante
(cliente) di proseguire una volta che la funzione termina
• un collegamento al record di attivazione del chiamante (Link Dinamico, DL),
per sapere dove finisce il record di attivazione corrente (utile per la gestione
della memoria)
• l’indirizzo del codice della funzione (puntatore alla prima istruzione)

-- MEMORIA HEAP
• Notiamo che sebbene, in generale, non sappiamo quanti record di
attivazione saranno istanziati nello stack durante l’esecuzione del
programma, la dimensione di un record di attivazione si conosce
dall’analisi (statica) del codice
• La memoria dinamica consente di allocare spazi di memoria la cui
dimensione si conosce solo in fase di esecuzione

-- CLASSI DI MEMORIZZAZIONE:
• In funzione del proprio tempo di vita, una variabile appartiene
a una delle seguenti classi di memorizzazione:
• Statica
• Automatica
• Dinamica

SPAZII DI INDIRIZZAMENTO:
La memoria allocata a ogni programma in esecuzione è suddivisa in varie
parti (segment), ovvero:

•code segment: contiene il codice eseguibile del
programma
•data segment: contiene le variabili globali
•heap: contiene le variabili dinamiche
•stack: è l'area dove vengono allocati i record di
attivazione
ÎCode segment e data segment sono di
dimensione fissata staticamente (a tempo di
compilazione).
ÎLa dimensione dell'area associata a stack +
heap è fissata staticamente: man mano che lo
stack cresce, diminuisce l'area a disposizione
dell'heap, e viceversa.

concetti che un programmatore deve avere in mente:
• si creano automaticamente le variabili con classe di memorizzazione statica e
automatica (queste ultime si distruggono anche automaticamente)
• si possono allocare le variabili dinamicamente

 Direzioni di crescita:
– la memoria dinamica
cresce man mano che
vengono allocati oggetti
– Lo stack cresce man
mano che si annidano
chiamate di funzion

-- ALLOCAZIONE DINAMICA CON HEAP:

• Heap: zona di memoria le cui parti (blocchi) possono essere allocate
(e deallocate) a seconda delle esigenze
• Necessario quando il linguaggio permette:
• tipi di dato dinamici
• dimensioni variabili
• variabili che sopravvivono alla procedura che li ha creati
• La gestione dello heap presenta problemi:
• gestione efficiente dello spazio
• frammentazione
• velocità di ricerca spazi liberi

- Heap suddiviso in blocchi di dimensione fissa:
• In origine, tutti i blocchi collegati nella lista libera
• allocazione: uno o più blocchi
• deallocazione: restituzione alla lista libera
• Il vincolo della dimensione fissa rende il meccanismo troppo
rigido:
• non fornisce blocchi di elevata dimensione per strutture dati
contigue di dimensione elevata
• non si può implementare la malloc di C (per i vari tipi di dato)

- Heap suddiviso in blocchi di dimensione variabile:
• Inizialmente, la lista libera è costituita da un unico blocco
• Successivamente, la lista è formata da blocchi di dimensione variabile
• allocazione: individuazione di un blocco libero della dimensione opportuna che
viene diviso in parte assegnata e resto del blocco libero
• deallocazione: restituzione del blocco aggiunta alla lista dei blocchi liberi

USO DEL HEAP:
• In C, l’allocazione nella memoria heap e la sua liberazione sono
espliciti, cioè si usano apposite chiamate a funzioni
• in C/C++, non sono nativamente previste strategie automatiche di gestione
della memoria (garbage collection)
• La funzione malloc della libreria stdlib.h alloca uno spazio di
memoria contiguo nell’heap e restituisce un puntatore al primo byte
allocato
• in caso di fallimento, restituisce il valore NULL che corrisponde all’indirizzo
riservato 0
• La funzione free della libreria stdlib.h libera lo spazio di memoria
precedentemente allocato con la malloc

GESTIONE DEL HEAP e Problemi:
• Le operazioni devono essere efficienti evitare lo spreco di memoria
(memory leak)
• Frammentazione: presente anche nella gestione memoria virtuale
tramite segmentazione
• poiché vengono assegnati blocchi di dimensione variabile che, dopo un certo
tempo, possono liberarsi

FRAMMENTAZIONE:
• Frammentazione interna: lo spazio richiesto è X, viene allocato un
blocco di dimensione Y > X
• lo spazio Y–X è sprecato
• Frammentazione esterna: la continua allocazione e deallocazione di
blocchi porta alla creazione di blocchi liberi e sparsi di piccole
dimensioni
• differenze tra il blocco libero usato e lo spazio effettivamente allocato
• spazio sprecato per l’esistenza di piccoli difficilmente usabili
• non è possibile allocare un blocco di grandi dimensioni, anche con tanta
memoria libera
• più problematica rispetto alla frammentazione interna

Gestione della lista libera: unica lista
• Ad ogni richiesta di allocazione, si cerca un blocco di dimensione
opportuna
• First fit: primo blocco abbastanza grande
• Best fit: quello di dimensione più piccola (tra quelli sufficienti)
• Se il blocco scelto è abbastanza più grande di quello che serve, esso
viene diviso in due e la parte inutilizzata è aggiunta alla lista libera
• Quando un blocco è deallocato, esso viene restituito alla lista libera
(se un blocco adiacente è libero i due blocchi sono “fusi” in un unico
blocco)
• First fit: più veloce, occupazione memoria peggiore
• Best fit: più lento, occupazione memoria migliore

Gestione della lista libera: liste multiple
• Unica lista libera: costo allocazione lineare nel numero di blocchi liberi
• Utilizzo di liste libere multiple per migliorare i tempi di ricerca:
• ogni lista contiene blocchi liberi di dimensione simile
• viene preso il primo blocco disponibile nella lista opportune
• La lista k-esima ha blocchi di dimensione 2k
• Se si desidera un blocco di dimensione 2j , e la relativa lista libera è vuota:
• si cerca un blocco, nella lista successiva, di dimensione doppia;
• viene diviso in due parti;
• se anche la lista successiva è vuota, la procedura si ripete ricorsivamente.
• Quando un blocco di dimensione 2k viene deallocato, viene riunito alla sua
altra metà (buddy, compare), se disponibile
• Fibonacci heap: simile, ma i blocchi hanno dimensioni numeri di Fibonacci
• maggiore scelta di dimensione, in quanto i numeri di Fibonacci crescono più
lentamente delle potenze di 2
• minore frammentazione interna

Uso delle variabili dinamiche:
• Le variabili dinamiche comportano una evidente maggiore difficoltà di
gestione rispetto alle variabili statiche e automatiche
• Comportano anche un maggiore utilizzo della memoria, a causa delle
strutture dati nascoste necessarie per gestirne correttamente
l’allocazione e la deallocazione
• Quindi, l’allocazione dinamica va utilizzata solo se è chiaramente la
soluzione migliore o addirittura l’unica soluzione per il problema da
risolvere

rappresenta il "contesto della funzione”: nasce e muore con essa
• è creato al momento della invocazione di una funzione
• permane per tutto il tempo in cui la funzione è in esecuzione
• è distrutto (deallocato) al termine dell’esecuzione della funzione stessa
• Ad ogni chiamata di funzione viene creato un nuovo record, specifico per
quella chiamata di quella funzione
• La dimensione del record di attivazione
• varia da una funzione all’altra
• per una data funzione, è fissa e calcolabile a tempo di compilazione

• Il compilatore, quando traduce una chiamata di funzione, inserisce nel
file oggetto alcune istruzioni aggiuntive
• Prima dell’inizio dell’esecuzione di una funzione, si crea in memoria il
corrispondente record di attivazione (RdA)
• struttura dati contenente fondamentalmente le variabili locali alla funzione
(variabili/costanti con nome locali, nonché parametri formali)
• tipicamente memorizzata in una zona contigua di memori

Parametri formali,
inizializzati con iinizializzati con i
parametri attualiparametri attuali

Variabili (costanti)Variabili (costanti)
localilocali

Indirizzo del record di attiva-Indirizzo del record di attiva-
zione del chiamante, per tor-zione del chiamante, per tor-
nare al suo record di attivazio-nare al suo record di attivazio-
ne alla fne dellnesecuzionene alla fne dellnesecuzione
della funzionedella funzione

Indirizzo dellnistruzione delIndirizzo dellnistruzione del
chiamante a cui saltare alla fnechiamante a cui saltare alla fne
dellnesecuzione della funzionedellnesecuzione della funzione

Indirizzo base e offset
• Quali informazioni occorre conoscere per poter accedere ad una
variabile locale della funzione in esecuzione in un dato momento?
• L’indirizzo a cui inizia il record di attivazione della funzione
• Indirizzo base
• Distanza (in memoria) della variabile da tale indirizzo
• Offset
• Un registro del processore, chiamato Base Pointer (BP), è utilizzato
tipicamente per memorizzare l’indirizzo base del record di attivazione
(RdA) della funzione correntemente in esecuzione

Accesso ai dati nello stack di attivazione:
• Base Pointer (BP):
• punta all’indirizzo base dell’ultimo RdA
• i dati dell’ultimo RdA sono accessibili per offset rispetto al BP:
• Indirizzo del dato = BP + offset
ü offset determinabile staticamente, a tempo di compilazione
• Dati non locali al blocco in esecuzione
• necessario determinare l’indirizzo base del RdA del dato
• Link Dinamico (o control link) (puntatore di catena dinamica)
• puntatore al precedente record sullo stack
• necessario per ripercorrere la catena dinamica

-- GESTIONE DELLO STACK:
Per la gestione dello stack di attivazione, è necessario anche:
• Stack Pointer (SP)
• punta alla cima della pila, primo spazio di memoria disponibile

 I record di attivazione sono a loro volta memorizzati in una zona della
memoria del processo chiamata stack (pila)
• Il record di attivazione di una funzione:
• viene creato dinamicamente nel momento in cui la funzione viene chiamata
• rimane sullo stack per tutto il tempo in cui la funzione è in esecuzione
• viene deallocato solo quando la funzione termina

• Il codice aggiuntivo inserito dal compilatore per realizzare la chiamata di
una funzione è chiamato prologo
• Le azioni principali compiute dal prologo sono:
• creare il record di attivazione
• inizializzare il BP con l’indirizzo del record di attivazione

1. sequenza di chiamata – chiamante
2. prologo – chiamato
3. epilogo – chiamato
4. sequenza di ritorno – chiamante

Prima di chiamare una funzione, si aggiunge tipicamente un ulteriore
elemento nel record di attivazione del chiamante, destinato a
contenere il valore di ritorno della funzione che si sta per chiamare

• Il codice che crea il record di attivazione di una funzione prima di
saltare all’indirizzo (della prima istruzione) della funzione si chiama
tipicamente prologo
• Il codice che immette il valore di ritorno di una funzione nel record di
attivazione del chiamante o in un registro di memoria, e poi dealloca il
record di attivazione della funzione stessa si chiama tipicamente
epilogo

CATENA DINAMICA:
• Nel record di attivazione è sempre inserito un campo denominato
collegamento dinamico
• contiene l’indirizzo del record di attivazione del chiamante
• al ritorno da una funzione permette di sapere l’indirizzo del record
di attivazione della funzione che torna in esecuzione
• Il BP può così essere aggiornato con tale indirizzo
• Si può nuovamente accedere, mediante l’offset, alle variabili locali
della funzione che torna in esecuzione
• in sostanza, si ripristina l’ambiente (contesto) del chiamante quando la
funzione chiamata termina
• La sequenza dei collegamenti dinamici costituisce la cosiddetta
catena dinamica, che rappresenta la storia delle attivazioni

Stack dei record di attivazione
• Nel linguaggio C/C++, tutto si basa su funzioni
• anche il main() è una funzione
• Per catturare la semantica delle chiamate annidate (una funzione che
chiama un’altra funzione, che ne chiama un’altra e così via), è
necessario gestire opportunamente l’area di memoria che contiene i
record di attivazione relative alle varie chiamate di funzione proprio
come una pila (stack):
• Last In, First Out → LIFO
(l’ultimo record ad entrare è il primo a uscire)
• l’ordine di collocazione dei record di attivazione nello stack indica la cronologia
delle chiamate:

La gestione dello stack avviene
mediante due operazioni:
push: aggiunta di un elemento (in cima
alla pila)
pop: prelievo di un elemento (dalla cima
della pila)

Sequenze di record di attivazione
• Funzioni che chiamano altre funzioni danno luogo a
una sequenza di record di attivazione
• allocati secondo l’ordine delle chiamate
• deallocati in ordine inverso (politica LIFO)
• i record di attivazione sono innestati

4. La memoria stack è utile per memorizzare i record di attivazione di ogni funzione.
All'inizio viene salvato il record di attivazione del main.
A ogni funzione chiamata viene aggiunto allo stack il record di attivazione
relativo alla funzione chiamata, che include: le sue variabili locali, 
l'indirizzo di ritorno al chiamante (ovvero l'indirizzo alla fine del record di
attivazione del chiamante nello stack)  e l'indirizzo che specifica a che
istruzione saltare una volta terminata la funzione chiamata (ovvero l'istruzione
successiva alla chiamata effettuata).
Una volta terminata la funzione chiamata  viene deallocato dalla memoria stack
il suo record di attivazione e si ritorna al record di attivazione del chiamante.
Ogni record di attivazione viene aggiunto allo stack in ordine cronologico 
(in base a quando viene chiamata una funzione).
Questo è fondamentale per le chiamate ricorsive,
l'ultimo record di attivazione (una volta arrivato al caso base) resituisce il suo
risultato al record di attivazione/funzione precedente e così via fino alla prima
chiamata e poi viene restituito il valore finale calcolato al main.

*/
