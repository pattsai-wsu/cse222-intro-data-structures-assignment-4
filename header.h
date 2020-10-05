#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct node {
  char *plate;
  char *first;
  char *last;
  struct node *left;
  struct node *right;
};

typedef struct node *Node;

struct node* databaseHandler(FILE*, struct node*, char*, char*, char*);
struct node* add(struct node*, char*, char*, char*);
void lnr(struct node*);
void nlr(struct node*);
void lrn(struct node*);
int search(struct node*, char*, char*, char*);
void lnrSearch(struct node*, char*, char*, char*, int*);
struct node* delete(struct node*, char*);
struct node* getLargestLeft(struct node*, int*);
int height(struct node*);
int balance(struct node*);
int max(int,int);
void freeTree(struct node*);
