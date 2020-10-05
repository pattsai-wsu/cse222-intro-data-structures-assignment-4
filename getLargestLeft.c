#include <stdio.h>

/*
getLargestLeft function - gets the largest node from the left side of the tree.
it takes a pointer to root->left from the delete function and assigns it to node.
then it finds the largest node in that subtree. 
*/

#include "header.h"

struct node* getLargestLeft (struct node *root, int *flag) {
  struct node *largest;
  struct node *previous;
  struct node *current;

  previous=root;
  if (root->right==NULL) {  // there is only one large node in the left side first colum
    largest=previous;       // therefore the largest will be the root node and no manipulation of the left side of the new node
    *flag=1;
  }
  else {
    current=root->right;
    while (current->right!=NULL) {
      previous=current;
      current=current->right;
    }
  
    largest=current;
    if (largest->left!=NULL) {
      previous->right=largest->left;
    }
    else {
      previous->right=NULL;
    }
  }
//  printf("LARGEST plate: %s name: %s %s\n",largest->plate,largest->first,largest->last);
  return (largest);
}

