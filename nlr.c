#include <stdio.h>

/*
nlr function - this is a traversal of the tree, uses a rucurssion starting with a pointer to the root.
it starts on the top node and works it's way the left bottom, up and to the right, then back to the next highest node and to the right
*/

#include "header.h"

void nlr(struct node *root) {
  if (root==NULL) {
    return;
  }
  printf("Plate: <%s>  Name: %s, %s\n",root->plate, root->last, root->first);
  nlr(root->left);
  nlr(root->right);
}


