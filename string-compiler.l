%{
#include "y.tab.h"
extern int yylineno;
%}

%%

[ \t]+             ;  /* Ignore whitespace */
\n                 { yylineno++; }

"="                  { return '='; }
";"                  { return ';'; }
"+"                  { return '+'; }
","                  { return ','; }
"("                  { return '('; }
")"                  { return ')'; }

"length"               { return LENGTH; }
"reverse"              { return REVERSE; }
"substring"            { return SUBSTRING; }
"palindrome"           { return PALINDROME; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.sval = strdup(yytext); return ID; }

\"([^"\\]|\\.)*\"      { yylval.sval = strdup(yytext); return STRING_LITERAL; }

[0-9]+               { yylval.ival = atoi(yytext); return NUMBER; }

.                    { return yytext[0]; }  /* Return any other character as is */

%%

int yywrap(void) { return 1; }
