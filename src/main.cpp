#include "../inc/assembler.hpp"

#include <stdio.h>
#include <stdlib.h>
extern int yyparse();
extern FILE *yyin;

int main(int argc, char** argv) {
  FILE *myfile = fopen(argv[1], "r");
  if (!myfile) {
    printf("Error opening file\n");
    return -1;
  }
  yyin = myfile;
  yyparse();
  fclose(myfile);
  return 0;
}