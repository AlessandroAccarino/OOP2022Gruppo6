#ifndef BST_H
#define BST_H

    #include <stdbool.h>
    #include "info.h"
    typedef struct SBSTNode TBSTNode;
    typedef TBSTNode* TBST;

    TBST bst_create();
    TBST bst_insert(TBST tree, TInfo1 info);
    void bst_print(TBST tree);
    TInfo1* bst_search(TBST tree, TInfo1 info);
    TInfo1* bst_partial_search(TBST tree, TInfo1 info, int max);
    TBST bst_delete(TBST tree, TInfo1 info);
    void bst_destroy(TBST);
     	
    TInfo1* bst_min(TBST tree);
    TInfo1* bst_max(TBST tree);

#endif /* BST_H */

