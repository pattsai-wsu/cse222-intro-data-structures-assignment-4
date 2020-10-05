#include <stdio.h>

/*
lrn function - this is a traversal of the tree, uses a rucurssion starting with a pointer to the root.
it starts on the left subtree and works it's way from the left bottom, to the right, then up and back to the next highest node and to the right
*/

#include "header.h"

void lrn(struct node *root) {
  if (root==NULL) {
    return;
  }
  lrn(root->left);
  lrn(root->right);
  printf("Plate: <%s>  Name: %s, %s\n",root->plate, root->last, root->first);
}


