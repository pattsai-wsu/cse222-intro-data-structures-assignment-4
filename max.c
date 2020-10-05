#include <stdio.h>

/*
max function - called by the height and balance functions
this function takes 2 integer values and returns the largest of the two

I was having trouble programming this into the height and balance functions
directly so I looked online to find how to add this type of functionality

I followed the code found on codeforwin.org/2016/02/c-program-to-find-maximum-and-minimum-using-functions.html
*/


#include "header.h"

int max(int val1, int val2) {
  return (val1 > val2) ? val1 : val2;
}
