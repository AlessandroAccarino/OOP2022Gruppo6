#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

#include <string.h>

struct SBSTNode {
    TInfo1 info;
    TBSTNode* right;
    TBSTNode* left;
};



TBSTNode* nodebst_create(TInfo1 info) {
    TBSTNode* newNode = (TBSTNode*) malloc(sizeof (TBSTNode));
    if (!newNode) {
        fprintf(stderr, "Errore, impossibile allocare!");
        exit(1);
    }
    newNode->info = info;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void nodebst_destroy(TBSTNode* node) {
    free(node);
}

TBST bst_create() {
    return NULL;
}

TBST bst_insert(TBST tree, TInfo1 info) {
    if (tree == NULL) {
        tree = nodebst_create(info);
        return tree;
    }
    if (info1_greater(info, tree->info)) {
        tree->right = bst_insert(tree->right, info);
        return tree;
    } else {
        tree->left = bst_insert(tree->left, info);
        return tree;
    }
}

void bst_print(TBST tree) {
    if (tree == NULL)
        return;
    bst_print(tree->left);
    info1_print(tree->info);
    bst_print(tree->right);
}

TInfo1* bst_search(TBST tree, TInfo1 info) {
    if (tree == NULL)
        return NULL;
    if (info1_equals(tree->info, info))
        return &tree->info;
    if (info1_greater(info, tree->info))
        return bst_search(tree->right, info);
    else
        return bst_search(tree->left, info);
}

TInfo1* bst_partial_search(TBST tree, TInfo1 info, int max) {

if (tree == NULL || max == 0 ){
    
    return NULL;
}

if(info1_equals(tree->info, info)){
    
    return &tree->info;
}
else if(info1_less(info, tree->info)){
    
    return bst_partial_search(tree->left, info, max-1);
}
else{
    
       return bst_partial_search(tree->right, info, max-1);
}

}

static TBSTNode* bst_min_internal(TBST tree) {
    if (NULL == tree) {
        return NULL;
    }
    if (NULL == tree->left)
        return tree;
    else
        return bst_min_internal(tree->left);
}

static TBSTNode* bst_max_internal(TBST tree) {
    if (NULL == tree) {
        return NULL;
    }
    if (NULL == tree->right)
        return tree;
    else
        return bst_max_internal(tree->right);
}

TInfo1* bst_min(TBST tree) {
    TBSTNode* node = bst_min_internal(tree);
    if(node)
        return &(node->info);
    else
        return NULL;
}


TInfo1* bst_max(TBST tree) {
    TBSTNode* node = bst_max_internal(tree);
    if(node)
        return &(node->info);
    else
        return NULL;

}

TBST bst_delete(TBST tree, TInfo1 info) {

    if (tree == NULL) {
        return tree;
    }
    if (info1_equals(info, tree->info)) {
        if (tree->left == NULL && tree->right == NULL) {
            nodebst_destroy(tree);
            return NULL;
        }
        if (tree->left == NULL) {
            TBST alias = tree->right;
            nodebst_destroy(tree);
            return alias;
        }
        if (tree->right == NULL) {
            TBST alias = tree->left;
            nodebst_destroy(tree);
            return alias;
        }
        TInfo1* min_bst_info = bst_min(tree->right);
        tree->info = *min_bst_info;
        tree->right = bst_delete(tree->right, tree->info);
    }
    if (info1_greater(info, tree->info)) {
        tree->right = bst_delete(tree->right, info);
        return tree;
    } else {
        tree->left = bst_delete(tree->left, info);
        return tree;
    }
}

void bst_destroy(TBST tree) {
    if (NULL == tree)
        return;
    bst_destroy(tree->left);
    bst_destroy(tree->right);
    nodebst_destroy(tree);
}
