#include <stdio.h>

/*
freeTree is a function to free all the remaining nodes where memory has been mallocd
this basically uses a LRN recurrsion to free all nodes from database
it is called before exiting the program 
*/

#include "header.h"

void freeTree(struct node *root) {
  if (root==NULL) {
    return;
  }
  freeTree(root->left);
  freeTree(root->right);
    free(root->plate);
    free(root->first);
    free(root->last);
    free(root);
}
