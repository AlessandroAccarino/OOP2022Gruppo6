#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "TInfo.h"
#include "TBST.h"

/* Rimuove tutti i duplicati dall'albero */
TBST BSTremoveDuplicates(TBST bst) {

    /* COMPLETARE QUESTA FUNZIONE - SEGUE CODICE DA RIMUOVERE */
     
    //caso base
    if(bst==NULL)
       return NULL;
    
    //divide et impera
    
    bst=BSTremoveDuplicates(bst->left);
    if(bst->info.key==bst->left->info.key || bst->info.key==bst->right->info.key)
       bst=BSTdelete(bst,bst->info);
    bst=BSTremoveDuplicates(bst->right);
    
    return bst;


}



/* ESERCIZIO 1
 * Scrivere una funzione RICORSIVA che restituisce la somma dei nodi di un 
 * albero binario di interi che si trovano a profondità k.
 */
 
 TInfo BSTsumDepth(TBST tree, int k) {
    // Casi base
    if (tree == NULL)
        return 0;
    if (k == 0)
        return tree->info;
        
    // Divide et impera
    TInfo left_depth = BSTsumDepth(tree->left, k-1);
    TInfo right_depth = BSTsumDepth(tree->right, k-1);
    
    // Combina
    return left_depth + right_depth;
}

/* ESERCIZIO 2
 * Scrivere una funzione RICORSIVA che restituisce la somma dei nodi di un 
 * albero binario di interi i cui valori siano numeri pari.
 */
 
 int isEven(TInfo num){
     if(num%2==0)
        return 1;
     else
        return 0;
 }
 
 TInfo BSTsumEven(TBST tree){
     // Caso base
    if (tree == NULL)
        return 0;
        
    // Divide et impera
    TInfo sumEven_left = BSTsumEven(tree->left);
    TInfo sumEven_right = BSTsumEven(tree->right);
    
    // Combina
    if(isEven(tree->info))
        return tree->info + sumEven_left + sumEven_right;
    else
        return sumEven_left + sumEven_right;
 }
 
/* ESERCIZIO 3
 * Scrivere una funzione RICORSIVA che visualizza in ordine tutti gli elementi
 * di un BST di interi compresi tra min e max (inclusi gli estremi)
 */
 
void BSTprintInterval(TBST tree, TInfo min, TInfo max) {
    // Caso base
    if (tree == NULL)
        return;
    
    // Divide et impera
    BSTprintInterval(tree->left, min, max);
    if (!infoGreater(min, tree->info) && !infoLess(max, tree->info)) // tree->info >= min && tree->info <= max
        infoPrint(tree->info);
    BSTprintInterval(tree->right, min, max);
}

// Soluzione alternativa (piu' efficiente)

void BSTprintInterval2 (TBST tree, int min, int max) {
    // Caso base
    if (tree == NULL)
        return;
        
    // Divide et impera (+ combina)
    if (!infoGreater(min, tree->info)) // tree->info >= min
        BSTprintInterval2(tree->left, min, max);
    if (!infoGreater(min, tree->info) && !infoLess(max, tree->info)) // tree->info >= min && tree->info <= max
        infoPrint(tree->info);
    if (!infoLess(max, tree->info)) // tree->info <= max
        BSTprintInterval2(tree->right, min, max);
}

/* ESERCIZIO 4
 * Scrivere una funzione RICORSIVA che restituisce il riferimento al padre
 * di un nodo di un albero binario di cui è noto il riferimento
 * (NULL nel caso il nodo sia la radice o non sia presente nell’albero).
 */
 
 TBST BSTfather(TBST tree, TBST node) {
    // Casi base
    if (tree == NULL || node == NULL || tree == node)
        return NULL;
    if (tree->left == node || tree->right == node)
        return tree;
    
    // Divide et impera
    TBST father = BSTfather(tree->left, node);
    if (father == NULL)
        return BSTfather(tree->right, node);
    
    // Combina
    return father;
}

// Soluzione più efficiente

TBST BSTfather2(TBST tree, TBST node) {
    // Casi base
    if (tree == NULL || node == NULL || tree == node)
        return NULL;
    if (tree->left == node || tree->right == node)
        return tree;
        
    // Divide et impera
    TBST father = NULL;
    if (!infoGreater(node->info, tree->info)) // node->info <= tree->info
        father = BSTfather2(tree->left, node);
    if (father == NULL && !infoLess(node->info, tree->info)) // father == NULL && node->info >= tree->info
        father = BSTfather2(tree->right, node);
        
    // Combina
    return father;
}
 
 /* ESERCIZIO 5
 * Scrivere una funzione RICORSIVA che restituisce il più piccolo sotto-albero
 * di un BST contenente due elementi info1 e info2.
 */
 
 TBST BSTsubTree(TBST tree, TInfo info1, TInfo info2) {
    // Controllo che tree non sia nullo
    if (tree != NULL) {
        // Controllo se sia info1 che info2 si trovino nel sotto-albero sinistro di tree
        if (infoLess(info1, tree->info) && infoLess(info2, tree->info))
            // Chiamata ricorsiva sul sotto-albero sinistro
            return BSTsubTree(tree->left, info1, info2);
        // Controllo se sia info1 che info2 si trovino nel sottoalbero destro di tree
        if (infoGreater(info1, tree->info) && infoGreater(info2, tree->info))
            // Chiamata ricorsiva sul sotto-albero destro
            return BSTsubTree(tree->right, info1, info2);
        // Dopo aver identificato il sotto-albero minimo che potrebbe contenere
        // info1 e info2, si effettua la ricerca dei due elementi mediante BSTsearch
        if (BSTsearch(tree, info1) != NULL && BSTsearch(tree, info2) != NULL)
            return tree;
    }
    return NULL;
}

/* 
 * Codice di test
 */

int main(int argc, char** argv) {
    
    TBST tree = BSTcreate(), f = BSTcreate();
    tree = BSTinsert(tree, 20);
    tree = BSTinsert(tree, 10);
    tree = BSTinsert(tree, 30);
    tree = BSTinsert(tree, 15);
    tree = BSTinsert(tree, 8);
    tree = BSTinsert(tree, 35);
    tree = BSTinsert(tree, 25);
    tree = BSTinsert(tree, 22);
    printf ("Albero:\n");
    BSTprintStructure(tree);
    
    /* Inserire le chiamate delle funzioni sviluppate */
    printf ("\nAltezza: %d\n", BSTheight(tree));
    
    printf ("Somma profondita' 0: ");
    infoPrint(BSTsumDepth(tree,0)); printf("\n");
    printf ("Somma profondita' 1: ");
    infoPrint(BSTsumDepth(tree,1)); printf("\n");
    printf ("Somma profondita' 2: ");
    infoPrint(BSTsumDepth(tree,2)); printf("\n");
    printf ("Somma profondita' 3: ");
    infoPrint(BSTsumDepth(tree,3)); printf("\n");
    printf ("Somma profondita' 4: ");
    infoPrint(BSTsumDepth(tree,4)); printf("\n");
    printf("\n");
    
    printf ("Somma elementi pari: ");
    infoPrint(BSTsumEven(tree));
    printf("\n");

    
    printf ("\nElementi tra 10 e 30:\n");
    BSTprintInterval(tree,10,30);
    printf("\n");
    
    f = BSTfather2(tree,BSTsearch(tree,15));
    printf ("Padre di 15: ");
    if(f == NULL)
        printf("%d",-1);
    else
        infoPrint(f->info);
    printf("\n");
    
    f = BSTfather2(tree,BSTsearch(tree,10));
    printf ("Padre di 10: ");
    if(f == NULL)
        printf("%d",-1);
    else
        infoPrint(f->info);
    printf("\n");
    
    f = BSTfather2(tree,BSTsearch(tree,20));
    printf ("Padre di 20: ");
    if(f == NULL)
        printf("%d",-1);
    else
        infoPrint(f->info);
    printf("\n");  
    
    f = BSTsubTree(tree,8,15);
    printf ("Il sottoalbero che include 8 e 15 ha radice in: ");
    if(f == NULL)
        printf("%d",-1);
    else
        infoPrint(f->info);
    printf("\n");
    
    f = BSTsubTree(tree,15,30);
    printf ("Il sottoalbero che include 15 e 30 ha radice in: ");
    if(f == NULL)
        printf("%d",-1);
    else
        infoPrint(f->info);
    printf("\n");
    
    f = BSTsubTree(tree,17,35);
    printf ("Il sottoalbero che include 17 e 35 ha radice in: ");
    if(f == NULL)
        printf("%d",-1);
    else
        infoPrint(f->info);
    printf("\n");   
    

    return 0;
}