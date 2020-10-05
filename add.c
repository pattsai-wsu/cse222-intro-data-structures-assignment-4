#include <stdio.h>

/*
add is used for adding entries to the binary tree.
it takes a pointer to the root, the plate, first and last pointers
it returns the root node.
*/



#include "header.h"

struct node* add (struct node* root,char *plate, char *first, char *last) {
  int plateLen;
  if (root==NULL) {
    root=malloc(sizeof(struct node));
    plateLen=strlen(plate);
    if (plateLen==0) {  // if a database file has a null entry where a plate should be it ERRORs to exit
      printf("ERROR: database invalid - plate of 0 length exists\n");
      exit(1);
    }
    root->plate=malloc(strlen(plate)+1);
    strcpy(root->plate,plate);  // copies contents to field

    root->first=malloc(strlen(first)+1);
    strcpy(root->first,first); // copies contents to field
    if (root->first[0]==' ' || root->first[0]=='\n') {  // if a db file does not have a valid name to go with a plate, it Errors to exit
      printf("ERROR: database invalid - entry with no name associated  exists\n");
      exit(1);
    }

    root->last=malloc(strlen(last)+1);
    strcpy(root->last,last); // copies contents to field

    root->left=NULL;
    root->right=NULL;
  return (root);
  }
  if (strcmp(plate,root->plate)<0) {
//    root->left=malloc(sizeof(struct node));
    root->left=add(root->left, plate, first, last);
  }
  else {
    root->right=add(root->right, plate, first, last);
  }
  return (root);
}
