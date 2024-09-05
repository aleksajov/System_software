%{
    #include <stdio.h>
    #include <stdlib.h>
 
    #include "bisonFile.tab.h"


    int lineNum=1;
%}

%option noyywrap

%%

"#".*   { }


[ \t]+ { }
\n { lineNum++; }


,       {return COMMA; }
\[      {return LEFT_BRACKET; }
\]      {return RIGHT_BRACKET; }
"+"     {return PLUS;}


\.global { return GLOBAL; }
\.extern { return EXTERN; }
\.section  { return SECTION; }
\.word { return WORD; }
\.skip { return SKIP; }
\.end  { return END; }

halt {return HALT;}
int {return INT;}
iret {return IRET;}
call {return CALL;}
ret {return RET;}
jmp {return JMP;}
beq {return BEQ;}
bne {return BNE;}
bgt {return BGT;}
push {return PUSH;}
pop {return POP;}
xchg {return XCHG;}
add {return ADD;}
sub {return SUB;}
mul {return MUL;}
div {return DIV;}
not {return NOT;}
and {return AND;}
or {return OR;}
xor {return XOR;}
shl {return SHL;}
shr {return SHR;}
ld {return LD;}
st {return ST;}
csrrd {return CSRRD;}
csrwr {return CSRWR;}

^[ \t]*[a-zA-Z_][a-zA-Z0-9_]*: {
    int labelLen = yyleng - 1;
    yylval.stringValue = (char *)malloc(labelLen + 1);
    strncpy(yylval.stringValue, yytext, labelLen);
    yylval.stringValue[labelLen] = '\0';
    return LABEL;
}

\$[a-zA-Z_][a-zA-Z0-9_]* {
  yylval.stringValue = strdup(yytext+1);
  return DOLARIDENT;
}

[a-zA-Z_][a-zA-Z0-9_]* {
  yylval.stringValue = strdup(yytext);
  return IDENT;
}



%r([0-9]|1[0-3]) { yylval.integerValue= (char)(atoi(yytext+2));  return REGISTER;} 
%(sp|r14)       { yylval.integerValue=14; return REGISTER;}
%(pc|r15)       { yylval.integerValue=15; return REGISTER;}

%status {return STATUS;}
%handler {return HANDLER;}
%cause {return CAUSE;}

\$[0-9]+            { yylval.integerValue = atoi(yytext+1); return DOLARINTEGER; }
\$0x[0-9a-fA-F]+    { yylval.integerValue = (unsigned int)strtoul(yytext+1, NULL, 16); return DOLARINTEGER; }

[0-9]+           { yylval.integerValue = atoi(yytext); return INTEGER; }
0x[0-9a-fA-F]+    { yylval.integerValue = (unsigned int)strtoul(yytext, NULL, 16); return INTEGER; }

. {
    printf("Flex error:character %c on line %d\n", yytext[0], lineNum);
    exit(1);
}


%%