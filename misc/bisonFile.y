
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern char* yytext;

#include "../inc/instruction.hpp"
#include "../inc/directive.hpp" 

void yyerror(const char *s);
%}

%union {
  unsigned int integerValue;
  char *stringValue;
}

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
%token STATUS
%token HANDLER
%token CAUSE
%token PLUS
%type <stringValue> list_of_symbols
%type <stringValue> list_of_literals_or_symbols
%type <stringValue> literal_or_symbol
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
    | LABEL  { Assembler::getInstance().handleLabel($1); free($1);}
    ;
directive:
    GLOBAL list_of_symbols { Directive::global($2); free($2); }
    | EXTERN list_of_symbols { Directive::_extern($2); free($2);}
    | SECTION IDENT { Directive::section($2); free($2); }
    | WORD list_of_literals_or_symbols { Directive::word($2); }
    | SKIP INTEGER { Directive::skip($2); }
    | END { Directive::end(); YYACCEPT;}
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
        sprintf($$, "%u", $1); 
    }
    | IDENT { $$ = strdup($1); free($1); }
    ;

instruction:
    HALT { Instruction::halt();}
    | INT { Instruction::interrupt();}
    | IRET { Instruction::iret();}
    | CALL literal_or_symbol { Instruction::call($2); free($2);}
    | RET {  Instruction::ret(); }
    | JMP literal_or_symbol { Instruction::jmp($2); free($2);}
    | BEQ REGISTER COMMA REGISTER COMMA literal_or_symbol { Instruction::beq($2, $4, $6); free($6);}
    | BNE REGISTER COMMA REGISTER COMMA literal_or_symbol { Instruction::bne($2, $4, $6); free($6);}
    | BGT REGISTER COMMA REGISTER COMMA literal_or_symbol { Instruction::bgt($2, $4, $6); free($6);}
    | PUSH REGISTER{ Instruction::push($2); }
    | POP REGISTER{ Instruction::pop($2); }
    | XCHG REGISTER COMMA REGISTER { Instruction::xchg($2, $4);}
    | ADD REGISTER COMMA REGISTER {  Instruction::add($4, $2); }
    | SUB REGISTER COMMA REGISTER {  Instruction::sub($4, $2);}
    | MUL REGISTER COMMA REGISTER {  Instruction::mul($4, $2);}
    | DIV REGISTER COMMA REGISTER { Instruction::div($4, $2);}
    | NOT REGISTER{  Instruction::_not($2); }
    | AND REGISTER COMMA REGISTER {  Instruction::_and($4, $2);}
    | OR REGISTER COMMA REGISTER { Instruction::_or($4, $2);}
    | XOR REGISTER COMMA REGISTER { Instruction::_xor($4, $2);}
    | SHL REGISTER COMMA REGISTER { Instruction::shl($4, $2);}
    | SHR REGISTER COMMA REGISTER { Instruction::shr($4, $2);}
    | CSRRD csr COMMA REGISTER {  Instruction::csrrd($2, $4); }
    | CSRWR REGISTER COMMA csr {Instruction::csrrw($2, $4); }
    | LD DOLARINTEGER COMMA REGISTER { Instruction::load_imm_literal($2, $4);}
    | LD DOLARIDENT COMMA REGISTER { Instruction::load_imm_symbol($2, $4); free($2);}
    | LD INTEGER COMMA REGISTER {  Instruction::load_literal($2, $4);}
    | LD IDENT COMMA REGISTER { Instruction::load_symbol($2, $4); free($2);}
    | LD REGISTER COMMA REGISTER {  Instruction::load_regdir($2, $4);}
    | LD LEFT_BRACKET REGISTER RIGHT_BRACKET COMMA REGISTER {  Instruction::load_reg_ind($3, $6);}
    | LD LEFT_BRACKET REGISTER PLUS INTEGER RIGHT_BRACKET COMMA REGISTER {  Instruction::load_reg_ind_offset($5, $3, $8);}
    | ST REGISTER COMMA DOLARINTEGER {printf("Parsing err: Tried st to literal "); exit(1); }
    | ST REGISTER COMMA DOLARIDENT {printf("Parsing err: Tried immediate adressing with st"); free($4); exit(1); }
    | ST REGISTER COMMA INTEGER { Instruction::store_literal($2, $4);}
    | ST REGISTER COMMA IDENT { Instruction::store_symbol($2, $4); free($4);}
    | ST REGISTER COMMA REGISTER { Instruction::load_regdir($2, $4);}
    | ST REGISTER COMMA LEFT_BRACKET REGISTER RIGHT_BRACKET {Instruction::store_regind($2, $5);}
    | ST REGISTER COMMA LEFT_BRACKET REGISTER PLUS INTEGER RIGHT_BRACKET {Instruction::store_regind_offs($7, $2, $5); }
    ;


csr:
    STATUS { $$=0;}
    | HANDLER { $$=1;}
    | CAUSE { $$=2;}
    ;
 
%%

void yyerror(const char *s) {
  printf("Parsing error: %s\n", s);
  exit(1);
}