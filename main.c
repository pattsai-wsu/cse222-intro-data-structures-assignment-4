#include <stdio.h>

/*
NAME: Patrick Tsai
CLASS: CSE 222 M-F 10 AM
DATE DUE: 2/28/2020 8:00 AM
ASSIGNMENT: PA4

SYNOPSIS - This program uses a binary search tree (BST) to order license plate numbers, and saves them according to size vs tree root. The program can search, display the database  based on 3 different traversals LNR NLR and LRN, and the program can also delete a listing and reorder the tree accordingly.

I've added handling for entries for people with only one name. Their single name must be in the first name position for it to work.

I am having trouble with the balance function
*/

#include "header.h"

int main(int argc, char** argv) {
  int i,usrNum,returnVal,dumpNum, returnValTemp;
  char c, usrIn[120], temp[120];
  char plate[120],first[120],last[120];
  char deletePlate[120];

  Node root=NULL;
  if (argc==2) {

    returnVal=sscanf(argv[1], "%s", temp);
    if (returnVal!=1) {
      printf("ERROR: not a valid entry\n");    //  error if user enters something after the number for hashsize on the command line
      exit(1);
    }

  FILE *fptr;            // pointer for file, and file handling below
  fptr=fopen(argv[1],"r");
  root=databaseHandler(fptr,root,plate,first,last);
  fclose(fptr);

  printf("Enter a command or plate: ");
  while(fgets(temp, 120, stdin)!=NULL) {
    sscanf(temp,"%s",usrIn);

  // Delete Section
  // takes entered input and creates a string used to find the
  // plate for deletetion, uses search then delete 
    if (sscanf(temp, "*DELETE %s", deletePlate)==1){
      if (temp[7]!=' ') {
        printf("ERROR: usage, use space between *DELETE and [plate]\n");  // error for not entering a space after *DELETE
        printf("Enter a command or plate: ");
      }
      else {
        int deletePlateLen=strlen(deletePlate);        
        deletePlate[deletePlateLen]='\0';
        int d=0;
          while(d<deletePlateLen){
            plate[d]=deletePlate[d];
            d++;
          }
        plate[d]='\0';
        int deleteSearchReturnVal=search(root,plate,first,last);

        if (deleteSearchReturnVal==1) {
          root=delete(root,plate);
          printf("SUCCESS\n");
          printf("\n");

            if (root==NULL) {
              printf("You deleted the entire database\n");
              exit(1);
            }
        }
        else {
          printf("Plate not found\n");
        } 
      printf("Enter a command or plate: ");
      }
    }
    else if (strcmp(temp,"*DUMP\n")==0){
      // Call to tree height function
      int treeHeight=height(root);
      printf("TREE HEIGHT: %d\n",treeHeight);

      // Call to balance function
      int balanceReturn=balance(root);
      printf("BALANCED: ");
      if (balanceReturn==-1) {
        printf("NO\n");
      }
      else {
        printf("YES\n");
      }

      // Call to LNR function
      printf("\n");
      printf("LNR\n"); 
      lnr(root);

      // Call to NLR function
      printf("\n");
      printf("NLR\n");
      nlr(root);

      // Call to LRN function
      printf("\n");
      printf("LRN\n"); 
      lrn(root);

      printf("\n");
      printf("Enter a command or plate: ");
    }
    else {
     // search functionality - occurs if dump or load is not called
      int inputLen=strlen(usrIn);       
      usrIn[inputLen]='\0';
      int k=0;
      while(k<inputLen){
        plate[k]=usrIn[k];
        k++;
      }
      plate[k]='\0';
      int searchResultVal=search(root,plate,first,last);
      if (searchResultVal==0) {
        printf("Plate not found\n");
        printf("Enter a command or plate: ");
      }
      if (searchResultVal==1) {
        printf("First name: %s\n",first);
        printf("Last name: %s\n",last);
        printf("\n");
        printf("Enter a command or plate: ");
      }
    }
  } // closer of the while loop
  } // closer of the big main if statement
  else {
    printf("ERROR: program usage\n");   // if user does not enter 2 line arguments then exit
    exit(1);
  }
  printf("\n"); 

  freeTree(root);
return 0;
}
