#include <stdio.h>

/*
lnrSearch is a function that uses the lnr recurrsion algorithm to search for a string entered by the user. if the plate is found it sets the string pointers and a flag and returns
to the search function.
*/

#include "header.h"

void lnrSearch(struct node *root,char *searchPlate, char *first, char *last, int *flag) {
  if (root==NULL) {
    return;
  }
  lnrSearch(root->left,searchPlate,first,last,flag);
  if (strcmp(root->plate,searchPlate)==0) {
    strcpy(first,root->first);
    strcpy(last,root->last);
    *flag=1;
    return;
  }
  lnrSearch(root->right,searchPlate,first,last,flag);
}
