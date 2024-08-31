#include "../inc/assembler.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
extern int yyparse();
extern FILE *yyin;

int main(int argc, char** argv) {
  //FILE *myfile = fopen(argv[1], "r");
  FILE *myfile = fopen("tests/proba.s", "r");
  if (!myfile) {
    printf("Error opening file\n");
    return -1;
  }
  yyin = myfile;
  yyparse();
  fclose(myfile);

  return 0;
}