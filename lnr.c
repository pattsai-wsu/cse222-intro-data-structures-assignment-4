#include <stdio.h>

/*
lnr function - this is a traversal of the tree, uses a rucurssion starting with a pointer to the root.
it starts on the left subtree and works it's way from the left bottom, up and to the right, then back to the next highest node and to the right
it prints the nodes in order from least to greatest.
*/

#include "header.h"

void lnr(struct node *root) {
  if (root==NULL) {
    return;
  }
  lnr(root->left);
  printf("Plate: <%s>  Name: %s, %s\n",root->plate, root->last, root->first);
  lnr(root->right);
}

