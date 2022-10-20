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

Note Alberi ----------------------------------------------------------
1)   h=4  p=0
     h=3  p=1
     h=2  p=2
     h=1  p=3
     h=0  p=4
La profondità della radice è sempre zero, l'altezza di un albero equivale 
alla massima profondità di un nodo.

2) Un albero è ordinato se vale che il valore di un node è >= dei valori dei
discendenti presenti nel sottoalbero sinistro e <= dei valori dei discendenti
presenti nel sottoalbero destro

3) Albero binario è pieno
– Tutte le foglie hanno la stessa profondità e tutti i nodi interni hanno 2 figli
– Nota: se i nodi sono n, l'altezza sarà ⌊log2 n⌋

4) Albero binario è quasi pieno
– Tutte le foglie hanno la stessa profondità a meno di 1
– Tutti i nodi interni hanno due figli

5) Albero binario è bilanciato
– Tutte le foglie hanno la stessa profondità a meno di 1

6) Albero binario è perfettamente bilanciato
– Tutte le foglie hanno la stessa profondità
Nota: albero quasi pieno è bilanciato (viceversa non sempre vero); pieno è perfettamente bilanciato
(viceversa non sempre vero

Albero binario ottimo se altezza è ⌊log2 n⌋
– Quindi quelli pieni o quasi pieni sono ottimi (viceversa non sempre vero)

Quesiti: 
1) Quali sono l’altezza minima e massima di un Albero binario avente n>= 1 nodi 

2) Quali sono il numero minimo e massimo di nodi di un Albero Binario avente
altezza h>=0?

3) Quanti sono i nodi interni di un albero binario pieno di altezza h>=1?

1. Risposta: altezza minima: parte intera inferiore di log2(n) (⌊log2(n)⌋) è il caso di
un albero binario completo; altezza massima: n-1 è il caso di un albero che
equivale a una lista con tutti i nodi interni che hanno un figlio.
2. Risposta: il numero minimo è h+1 e corrisponde al caso in cui tutti i nodi
interni hanno al più un figlio; il numero massimo è 2^(h+1)-1 e corrisponde a un
alberobinario completo perfettamente bilanciato.
3. Risposta:  in quanto un albero binario completo perfettamente bilanciato
di altezza h ha in totale 2^(h+1)–2 nodi interni, di cui 2^h foglie.
Infatti, sappiamo che 2^(h+1)–2 – 2^h = 2^(h)–2.

4) Tipo di visita se si vuole cancellare un nodo?

4. Risposta: è possibile utilizzare in maniera efficiente solo la visita in 
post-ordine in quanto utilizzando le altre perdiamo l'indirizzo del nodo radice.

Def:
Un albero binario è ordinato se, ricorsivamente per ogni suo nodo, si verifica che:
1) il valore della chiave del nodo è non minore di tutti i valori delle chiavi contenute nel suo sottoalbero
sinistro;
2) e non maggiore di tutti i nodi contenuti nel suo sottoalbero destro

VISITA IN ORDINE:

Per un albero binario ordinato, l’algoritmo di visita più naturale è quello in ordine: in
tal caso i nodi dell’albero sono visitati in ordine crescente rispetto ai valori in esso
contenuti.

La visita in ordine è detta anche visita simmetrica: è possibile dimostrare
semplicemente (per induzione matematica) che la visita simmetrica si ottiene
eseguendo ricorsivamente i seguenti passi:
1) visita simmetrica del sottoalbero sinistro;
2) visita del nodo radice;
3) visita simmetrica del sottoalbero destro

VISITA IN PRE/POST ORDINE

Oltre alla visita simmetrica, si definiscono una
visita in pre-ordine ed una in post-ordine;
la visita in pre-ordine, viene realizzata,
eseguendo ricorsivamente i seguenti passi:
1) visita del nodo radice;
2) visita simmetrica del sottoalbero sinistro;
3) visita simmetrica del sottoalbero destro.
Il motivo per cui tale visita è definita in pre-
ordine è evidente: il nodo radice dell’albero
corrente è visitato prima del suo sottoalbero
sinistro, come avviene per la visita simmetrica.

Analogamente la visita in post-
ordine si articola, posticipando
la visita della radice a quella
del suo sottoalbero destro:
1) visita simmetrica del sottoalbero
sinistro;
2) visita simmetrica del sottoalbero
destro;
3) visita del nodo radice

CANCELLAZIONE (CASO 1)
Il primo caso è evidentemente
quello più semplice da gestire: in
tale situazione la rimozione del
nodo, che consiste nell’eliminazione
della foglia in questione, non
comporta alcuna modifica
strutturale nell’albero e quest’ultimo
continua a soddisfare il criterio di
ordinamento

CANCELLAZIONE (CASO 2)
la cancellazione del nodo comporta la
necessità di collegare il sottoalbero non
vuoto del nodo cancellato con il padre del
nodo cancellato.
E` semplice verificare che tale operazione,
sebbene appaia ad una prima analisi non
banale, può essere condotta con un unico
passo.
Basta infatti collegare il sottoalbero non
vuoto del nodo cancellato al posto del
nodo cancellato.

CANCELLAZIONE (CASO 3)
Il terzo caso è quello che si verifica allorquando il nodo da cancellare presenta
entrambi i sottoalberi.
La procedura di cancellazione, dopo aver identificato il nodo da cancellare,
provvede ad eseguire i seguenti passi:
1) la sostituzione del valore presente nel nodo da cancellare, con il valore minimo del sottoalbero
destro (o in alternativa con il massimo nel sottoalbero sinistro)
2) la cancellazione del valore minimo dal sottoalbero destro (o del massimo dal sottoalbero sinistro nel
caso in cui si sia proceduto al passo precedente con l’ipotesi alternativa

Complessità computazionale:

                Operazione Lista ordinata || BST di altezza h
                        Best Average Worst Best Average Worst
creazione                ⇥(1) ⇥(1) ⇥(1) ⇥(1) ⇥(1) ⇥(1)
inserimento              ⇥(1) ⇥(n) ⇥(1) ⇥(1) ⇥(h) ⇥(h)
ricerca (elem. presente) ⇥(1) ⇥(n) ⇥(n) ⇥(1) ⇥(h) ⇥(h)
ricerca (elem. assente)  ⇥(1) ⇥(n) ⇥(n) ⇥(h) ⇥(h) ⇥(h)
cancellazione            ⇥(1) ⇥(n) ⇥(n) ⇥(1) ⇥(h) ⇥(h)
visita                   ⇥(n) ⇥(n) ⇥(n) ⇥(n) ⇥(n) ⇥(n)
distruzione              ⇥(n) ⇥(n) ⇥(n) ⇥(n) ⇥(n) ⇥(n)


La maggior parte degli algoritmi di ordinamento presentati hanno una complessità
temporale asintotica che nel caso peggiore è Θ(n2)
Tuttavia, con l’algoritmo Merge Sort si riesce a ottenere Θ(n logn).
Domanda: È possibile fare di meglio?

No, nessun algoritmo di ordinamento per confronto riesce ad avere una complessità computazionale inferiore.

--------------------------------------------------------------------------------------

Ordinamento stabile (stable sorting): la sequenza finale preserva l’ordine iniziale
tra due elementi dello stesso valore:

• Selection sort: Sì – in base all’implementazione di search_min
• Insertion sort: Sì – in base all’implementazione di insert_in_order
• Bubble sort: Sì – se, quando viene incontrata una coppia di elementi adiacenti
equivalenti, essi non vengono scambiati di posto
• Merge sort: Sì – se la funzione merge, nel caso in cui gli elementi confrontati
siano uguali, sceglie l’elemento del primo sotto-array
• Quick sort: No – nella fase di partition, a causa dello scambio del pivot con il
primo elemento del sotto-array da ordinare

RICERCA SEQUENZIALE:

trovare l'elemento k in un array di dimensione n

T(n) = c1 + (n+1)*c2 + n*c3 = O(1)+O(n)+O(1)+O(n) = O(n)
Caso peggiore = O(n)
Caso migliore = O(1)

RICERCA BINARIA (dicotomica):

T(1) = c1
T(n) = c2 + T(n/2) = T(n/4) + c2 + c2 = T(n/2^i)+ i*c2

ponendo: i= log(n)
otteniamo:
T(n/2^log2(n)) +log2(n)*c2 = Teta(1)+ Teta(log(n)) = Teta(log(n))



TORRE DI HANOI: 

T(1) = c1
T(n) = 2T(n-1) +c2  = 2[2T(n-1) +c2] +c2 = 2^i *T(n-i)+ (2^i-1)*c2 = O(2^n)

ponendo i = n-1

SELECTION SORT:

Ricordando che il selection sort si basa sulla search_min che ha complessità 
computazionale basata sugli n elementi quindi Teta(n)

se viene applicata al caso di un array di n-1 allora Teta(n-1)

T^i(n) = Teta(n-1) + Teta(1) = Teta(n-1)

          n-2
T(n)=Somm [    Teta(n-i) 
          i=0
      
Applicando la somma di Gauss Sn = (1/2)*n*(a1+an)
      
    T(n) = Teta(n^2)

ciò vale per tutti i casi

INSERTION SORT:

poichè possiede un invocazione ad insert_in_order su un sotto array di i elementi
quindi avendo una complessità computazionale Teta(1) (best case) e nel worst e medio Teta(i)
 
(Si applicca sempre la somma di gauss)

              n-1
Tbest(n)=Somm [    Teta(1) = (n-1)*Teta(1) = Teta(n)
              i=1

              n-1
Tworst(n)=Somm [    Teta(i) = Teta(n*(n-1)/2) = Teta(n^2)
              i=1

MERGE SORT:

La complessità della funzione merge è Teta(n1 + n2)
dove n1 e n2 sono le dimensioni di due sotto array

T(1) = Teta(1)
T(n) = 2T(n/2) + Teta(n)

T(1) = c1
T(n) = 2T(n/2) + nc2

T(n) = 2[2T(n/4)+(n/2)*c2] + nc2 = 4T(n/4) +2nc2 = 2^i *T(n/2^i) + inc2

ponendo i = log(n)

= O(n*log(n))

La complessità è la stessa in tutti i casi.

QUICK SORT:

complessità della funzione partition è Teta(n)

caso migliore:
Dopo ogni partizionamento il pivot si trova sempre circa al centro dell'array

T(1) = Teta(1)
T(n) = Teta(n) + 2T(n/2)

(stesssi conti del merge sort, il risultato è lo stesso)

Teta(n*log(n))

caso peggiore:

Dopo ogni partizionamento il pivot si trova sempre all'inizio
o alla fine dell'array

T(1) = Teta(1)

                                  n-2 
T(n) = T(n-1) + Teta(n) = T(1)+ c [   (n-i)
                                  i=0

per la K essima iterazione dove k = n-1
      
Applicco la somma di Gauss:  Teta(n^2) 

La maggior parte degli algoritmi di ordinamento presentati hanno una complessità
temporale asintotica che nel caso peggiore è Θ(n2)
Tuttavia, con l’algoritmo Merge Sort si riesce a ottenere Θ(n logn).
Domanda: È possibile fare di meglio?
risposta: No, nessun algoritmo di ordinamento (per confronti) può avere una
complessità computazionale nel caso peggiore inferiore a Θ(n logn)

Riformulando il problema dell'ordinamento in termini di permutazioni:
data una sequenza di n elementi a_0, ... m a_n-1 vogliamo trovare una permutazione
p_0, ..., p_n-1 dell'insieme degli indici della sequenza tale che:

a_p0 < a_p1 < a_pn-1

suppondendo che gli elementi della sequenza siano tutti distinti il contro
tra due elementi avra solo due esiti: ai < aj e viceversa

• Poiché stiamo cercando un limite inferiore alla complessità, supponiamo che il nostro
algoritmo scelga a ogni passo il confronto che restituisce il maggiore beneficio
• Al contempo, poiché stiamo cercando un limite inferiore alla complessità nel caso
peggiore, dobbiamo anche supporre che il risultato del confronto sia sempre quello
meno favorevole al nostro algoritmo
Questo algoritmo ‘astratto’ effettua ad ogni iterazione un confronto tra due elementi
della sequenza da ordinare, e in base al risultato del confronto l’algoritmo esclude alcune
delle possibili permutazioni dall’insieme delle soluzioni del problema
      
--------------------------------------------------------------------------------------

Hash Table Aperte:
Nell’indirizzamento aperto, tutti gli elementi sono invece contenuti nella tabella T;
la funzione di hash in questo caso consente di determinare la posizione di inizio, a
partire dalla quale sono collocati tutti gli elementi collidenti: applicata la funzione di
hash alla chiave, si ottiene infatti la posizione nella quale è presente l’elemento.
Se tale cella risultasse occupata, se ne cercherebbe un’altra libera, con una tecnica
particolare di scansione. La scansione più semplice è quella lineare che prevede la
scansione in celle consecutive a quella di partenza.

HT Aperte VS chiuse.

il principale vantaggio dell’indirizzamento aperto è quello di evitare completamente
l’impiego dei puntatori;
lo svantaggio più significativo è quello di non consentire in alcun modo di aggiungere
elementi ulteriori alla tabella una volta raggiunta la sua capienza.

Nell’indirizzamento chiuso, accettando un degrado prestazionale, è sempre possibile
aggiungere ulteriori elementi che trovano comunque posto nelle liste di collisione,
essendo quest’ultime strutture dinamiche e quindi espandibili all’occorrenza.
Dal punto di vista computazionale i due approcci sono equivalenti.

TABELLE A INDIRIZZAMENTO INDIRETTO:

Le tabelle ad indirizzamento indiretto nascono con l’obiettivo di preservare l’elevata
efficienza computazionale delle tabelle ad accesso diretto, ma risparmiando
sensibilmente sulla memoria occupata.
L’idea di base è quella di introdurre una funzione h, detta di hash, che a partire
dalla chiave Ki sia in grado di generare la posizione del vettore nel quale è
memorizzata l’informazione ad essa associata.

FUNZIONE DI HASH:
deve godere della proprietà matematica di essere iniettiva, ovvero non deve generare lo stesso
indice per due chiavi diverse.
Se ciò avviene, si dice che si genera una collisione tra le chiavi. Per meglio
comprendere la problematica che si manifesta in presenza di collisioni tra le chiavi, si
consideri la situazione in cui la chiave Ki collide con Kj, ovvero h(Ki) = h(Kj), essendo i
≠ j.
L’occorrenza della collisione non rende possibile la memorizzazione dei valori
associati alle chiavi collidenti in un’unica cella del vettore; pertanto, le informazioni
non rappresentabili in una cella unica sono Vi e Vj, associate alle chiavi Ki e Kj.

Si ipotizza di utilizzare una struttura dati, che possa consentire la rappresentazione
di eventuali chiavi collidenti.
Nel corso degli anni si sono consolidati due metodi:
• Liste di collisione, detto anche indirizzamento chiuso. In tal caso, gli elementi
collidenti sono contenuti all’interno di liste esterne alla tabella stessa;
• Indirizzamento aperto: tutti gli elementi sono contenuti nella tabella; eventuali
collisioni sono gestite mediante l’occupazione di posizioni successive.

*/