#include <stdio.h>

/*
delete function - takes a pointer to the root and the string for the plate that needs to be deleted then uses a recurssion to find the plate.
once the plate is found it frees the node and replaces it with the appropriate node if it is not a leaf.
*/

#include "header.h"

struct node *delete(struct node *root, char *deletePlate) {
  int flag=0;
  struct node *temp;

  if (strcmp(root->plate,deletePlate)==0) {
    //do stuff
    if (root->left==NULL && root->right==NULL) {
      temp=NULL;
      free(root->plate);  // frees mallocd mem
      free(root->first);
      free(root->last);
      free(root);
    }
    else if (root->left==NULL && root->right!=NULL) {
      temp=root->right;
      free(root->plate); // frees mallocd mem
      free(root->first);
      free(root->last);
      free(root);  
    }
    else {
      struct node *rootLeft;
      struct node *largest;
      rootLeft=root->left;
      largest=getLargestLeft(rootLeft, &flag);  // finds the largest node from the left side of the tree
      if (flag==0) {
        largest->left=root->left;
      }
      if (root->right!=NULL) {
        largest->right=root->right;
      }
      else {
        largest->right=NULL;
      }
      temp=largest;
      free(root->plate); // frees mallocd mem
      free(root->first);
      free(root->last);
      free(root);
    }
    return (temp);
  }

  if (strcmp(deletePlate,root->plate)<0) {  // recurssion for the left side
    temp=delete(root->left,deletePlate);
    root->left=temp;
    return (root);
  }
  
  temp=delete(root->right,deletePlate);  // recurrsion for the right side
  root->right=temp;
  return (root);
}
