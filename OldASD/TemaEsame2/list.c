#include "list.h"
#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "info.h"


/* 
 * Operazioni su THLNode e TList
 */

THLNode *node_create(TInfo2 info) {
    THLNode *new = malloc (sizeof(THLNode));
    if (new != NULL) {
        new->info = info;
        new->link = NULL;
    }
    return new;
}

void node_destroy(THLNode *node) {
    free (node);
}

TList list_create() {
    return NULL;
}

TList list_destroy(TList list) {
    THLNode *node;
    while (list != NULL) {
        node = list;
        list = list->link;
        node_destroy(node);
    }
    return list;
}

TList list_insert(TList l, TInfo2 info) {
    if (l == NULL || info2_greater(l->info, info)) {
        THLNode *node = node_create(info);
        assert (node != NULL);
        node->link = l;
        return node;
    }
    TList m = list_insert(l->link, info);
    l->link = m;
    return l;
}

THLNode *list_search(TList list, TInfo2 info) {
    THLNode *node = list;
    while (node != NULL && !info2_equals(info, node->info))
        node = node->link;
    return node;
}

TList list_delete(TList list, TInfo2 info) {
    THLNode *prec = NULL, *node = list;
    while (node != NULL && !info2_equals(info, node->info)) {
        prec = node;
        node = node->link;
    }
    if (node != NULL && info2_equals(info, node->info)) {
        if (prec == NULL) 
            list = node->link;
        else
            prec->link = node->link;
        node_destroy(node);
    }
    return list;
}

void list_print(TList list) {
    THLNode *node = list;
    while (node != NULL) {
        info2_print (node->info);
        node = node->link;
    }
}
