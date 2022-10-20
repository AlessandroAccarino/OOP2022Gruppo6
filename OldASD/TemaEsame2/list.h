#ifndef LIST_H
#define LIST_H

/* Operazioni su THLNode e TList ---------------------- */
#include "info.h"
typedef struct SHLNode THLNode;
struct SHLNode {
    TInfo2 info;
    THLNode *link;
};
typedef THLNode* TList;

TList list_create();
TList list_destroy(TList);
TList list_insert(TList, TInfo2);
THLNode *list_search(TList, TInfo2);
TList list_delete(TList, TInfo2);
void list_print(TList);

#endif /* LIST_H */

