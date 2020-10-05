#include <stdio.h>

/*
balance function - takes in a root node and uses recurrsion to find the balance of left and right side of the tree.

I'm had a lot of trouble with this function, I did get it working but I followed instructions from the youtube video https://youtu.be/TWDigbwxuB4

*/

#include "header.h"

int balance(struct node *root) {
  if (root==NULL) {  // base case
    return 0;
  }

  int leftHeight=balance(root->left);
  if (leftHeight==-1) {  // checks if left is balanced
    return -1;
  }
  int rightHeight=balance(root->right);
  if (rightHeight==-1) {  // checks if right is balanced
    return -1;
  }

  if (abs(leftHeight-rightHeight)>1) {  // checks if difference in height is more than 1
    return -1;
  }

return (1+max(leftHeight,rightHeight));  // returns balanced
}
