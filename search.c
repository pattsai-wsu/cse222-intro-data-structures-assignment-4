#include <stdio.h>

/*
search function - searches for a plate input by the user.
this function relies on another function called lnrSearch
which uses a lnr algorithm to traverse the BST whille searching
for the plate in question.
*/

#include "header.h"

int search(struct node *root, char *searchPlate, char *first, char *last) {
  int flag=0;

  if (root==NULL) {     // checks for an empty list
    printf("Empty List\n");
    return 0;
  }

  lnrSearch(root, searchPlate, first, last, &flag);

  if (flag==1) {
    return 1;
  }
  else {
    return 0;
  }
}


