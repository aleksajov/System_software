
%{
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern char* yytext;

#include "../inc/instruction.hpp"
#include "../inc/directive.hpp"

void yyerror(const char *s);

char* intToChar(int num);
%}

%union {
  int integerValue;
  char *stringValue;
}

%token DOLAR
%token COMMA
%token LEFT_BRACKET;
%token RIGHT_BRACKET;
%token GLOBAL
%token EXTERN
%token SECTION
%token WORD
%token SKIP
%token END
%token HALT
%token INT
%token IRET
%token CALL
%token RET
%token JMP
%token BEQ
%token BNE
%token BGT
%token PUSH
%token POP
%token XCHG
%token ADD
%token SUB
%token MUL
%token DIV
%token NOT
%token AND
%token OR
%token XOR
%token SHL
%token SHR
%token LD
%token ST
%token CSRRD
%token CSRWR
%token <stringValue> LABEL
%token <stringValue> IDENT
%token <stringValue> DOLARIDENT
%token <integerValue> INTEGER
%token <integerValue> DOLARINTEGER
%token <integerValue> REGISTER
%token <integerValue> SP
%token <integerValue> PC
%token STATUS
%token HANDLER
%token CAUSE
%token PLUS
%type <stringValue> list_of_symbols
%type <stringValue> list_of_literals_or_symbols
%type <stringValue> literal_or_symbol
%type <stringValue> operand
%type <integerValue> csr

%start program

%%
program:
  statements
  ;
statements:
    statement
    | statements statement
    ;
statement:
    directive
    | instruction
    | LABEL  { printf("Parsed LABEL: %s\n", $1); Assembler::getInstance().handleLabel($1); free($1);}
    ;
directive:
    GLOBAL list_of_symbols { printf("Parsed global: %s\n", $2);  Directive::global($2); free($2); }
    | EXTERN list_of_symbols { printf("Parsed extern: %s\n", $2);  Directive::_extern($2); free($2);}
    | SECTION IDENT { printf("Parsed section: %s\n", $2); Directive::section($2); free($2); }
    | WORD list_of_literals_or_symbols { printf("Parsed word: %s\n", $2); Directive::word($2); }
    | SKIP INTEGER { printf("Parsed skip: \n"); Directive::skip($2); }
    | END { printf("Parsed end: \n"); Directive::end(); YYACCEPT;}
    ;
list_of_symbols:
    IDENT { $$=strdup($1); free($1);}
    | list_of_symbols COMMA IDENT { 
        $$=(char*)malloc(strlen($1)+strlen($3)+2);
        sprintf($$, "%s %s", $1, $3);
        free($1);
        free($3);
        }
    ;
list_of_literals_or_symbols:
    literal_or_symbol { 
        $$ = strdup($1);
        free($1);
    }
    | list_of_literals_or_symbols COMMA literal_or_symbol { 
        $$ = (char*)malloc(strlen($1) + strlen($3) + 2);
        sprintf($$, "%s %s", $1, $3);
        free($1);
        free($3);
    }
    ;

literal_or_symbol:
    INTEGER { $$=(char*)malloc(12);
        sprintf($$, "%d", $1); 
    }
    | IDENT { $$ = strdup($1); free($1); }
    ;

instruction:
    HALT { printf("Parsed halt \n"); Instruction::halt();}
    | INT { printf("Parsed int: \n"); Instruction::interrupt();}
    | IRET { printf("Parsed iret: \n"); Instruction::iret();}
    | CALL literal_or_symbol { printf("Parsed call %s\n", $2); Instruction::call($2); free($2);}
    | RET { printf("Parsed ret: \n"); Instruction::ret(); }
    | JMP literal_or_symbol { printf("Parsed jmp: %s\n", $2); Instruction::jmp($2); free($2);}
    | BEQ REGISTER COMMA REGISTER COMMA literal_or_symbol { printf("Parsed beq with registers %d %d and %s: \n", $2, $4, $6); Instruction::beq($2, $4, $6); free($6);}
    | BNE REGISTER COMMA REGISTER COMMA literal_or_symbol { printf("Parsed bne: with registers %d %d and %s: \n", $2, $4, $6); Instruction::bne($2, $4, $6); free($6);}
    | BGT REGISTER COMMA REGISTER COMMA literal_or_symbol { printf("Parsed bgt: with registers %d %d and %s: \n", $2, $4, $6); Instruction::bgt($2, $4, $6); free($6);}
    | PUSH REGISTER{ printf("Parsed push: %d\n", $2); Instruction::push($2); }
    | POP REGISTER{printf("Parsed pop:  %d\n", $2); Instruction::pop($2); }
    | XCHG REGISTER COMMA REGISTER { printf("Parsed xchg: with registers %d %d: \n", $2, $4); Instruction::xchg($2, $4);}
    | ADD REGISTER COMMA REGISTER { printf("Parsed add: with registers %d %d: \n", $2, $4); Instruction::add($4, $2); }
    | SUB REGISTER COMMA REGISTER { printf("Parsed sub: with registers %d %d: \n", $2, $4); Instruction::sub($4, $2);}
    | MUL REGISTER COMMA REGISTER { printf("Parsed mul: with registers %d %d: \n", $2, $4); Instruction::mul($4, $2);}
    | DIV REGISTER COMMA REGISTER { printf("Parsed div: with registers %d %d: \n", $2, $4); Instruction::div($4, $2);}
    | NOT REGISTER{ printf("Parsed not: %d\n", $2); Instruction::_not($2); }
    | AND REGISTER COMMA REGISTER { printf("Parsed and: with registers %d %d: \n", $2, $4); Instruction::_and($4, $2);}
    | OR REGISTER COMMA REGISTER {printf("Parsed or:with registers %d %d: \n", $2, $4); Instruction::_or($4, $2);}
    | XOR REGISTER COMMA REGISTER {printf("Parsed xor:with registers %d %d: \n", $2, $4); Instruction::_xor($4, $2);}
    | SHL REGISTER COMMA REGISTER {printf("Parsed shl: with registers %d %d: \n", $2, $4); Instruction::shl($4, $2);}
    | SHR REGISTER COMMA REGISTER {printf("Parsed shr: with registers %d %d: \n", $2, $4); Instruction::shr($4, $2);}
    | LD operand COMMA REGISTER { printf("Parsed ld: with register %d : \n",  $4);}
    | ST REGISTER COMMA operand {printf("Parsed st: with register %d : \n", $2); }
    | CSRRD csr COMMA REGISTER { printf("Parsed csrrd:  %d , %d\n",  $2, $4); Instruction::csrrd($2, $4); }
    | CSRWR REGISTER COMMA csr {printf("Parsed csrwr: reg %d , %d\n",  $2, $4); Instruction::csrrw($2, $4); }
    ;

operand:
    DOLARINTEGER { $$ = intToChar($1); printf("$%d\n", $1);}
    | DOLARIDENT { $$ = $1; printf("$%s\n", $1); free($1); }
    | INTEGER { $$ = intToChar($1); printf("%d\n", $1);}
    | IDENT { $$ = $1; printf("%s\n", $1); free($1); }
    | REGISTER { $$ = intToChar($1); printf("r%d\n", $1);}
    | LEFT_BRACKET REGISTER RIGHT_BRACKET { $$ = intToChar($2); printf("[r%d]\n", $2);}
    | LEFT_BRACKET REGISTER PLUS INTEGER RIGHT_BRACKET { $$ = intToChar($2); printf("[r%d+%d]\n", $2, $4);}
    | LEFT_BRACKET REGISTER PLUS IDENT RIGHT_BRACKET { $$ = intToChar($2); printf("[r%d+%s]\n", $2, $4); free($4);}
    ;

csr:
    STATUS { $$=0;}
    | HANDLER { $$=1;}
    | CAUSE { $$=2;}
    ;
 
%%

//izmeniti
char* intToChar(int num) {
    // Allocate memory for the string
    // Assuming a maximum of 11 characters for an integer (-2147483648 to 2147483647) + 1 for null terminator
    char* str = (char*)malloc(12 * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Convert the integer to a string
    sprintf(str, "%d", num);

    return str;
}

void yyerror(const char *s) {
  printf("Parsing error: %s\n", s);
  exit(-1);
}