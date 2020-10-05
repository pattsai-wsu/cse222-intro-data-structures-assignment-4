#include <stdio.h>

/*
height function - this function uses a recurssion to calculate the heights of the left and right subtree
i built a max function inorder to compare two integers, which in this case are the heights of the subtrees
the function takes a root and returns the integer of the tallest of the two subtrees.
*/

#include "header.h"

int height(struct node *root) {
  int heightTree, heightTreeLeft, heightTreeRight;
  if(root==NULL) {
    return -1;   // basecase root is null
  }

  heightTreeLeft=(height(root->left));    // recurrsion on the left subtree
  heightTreeRight=(height(root->right));  // recurrsion on the riht subtree

  heightTree=1+max(height(root->left),height(root->right));  // compares the subtree hieghts

return (heightTree);  // returns the tallest of the two subtrees
}
