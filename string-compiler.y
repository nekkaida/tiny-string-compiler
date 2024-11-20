%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100

extern int yylineno;

struct var {
    char* name;
    char* value;
};

struct var vars[MAX_VARS];
int var_count = 0;

char* get_var_value(char* name);
void set_var_value(char* name, char* value);

int yylex(void);
void yyerror(const char *s);

%}

%union {
    char* sval;
    int ival;
}

/* Declare types for tokens */
%token <sval> ID STRING_LITERAL
%token <ival> NUMBER
%token LENGTH REVERSE SUBSTRING PALINDROME

%type <sval> expr term function_call

%%

program:
    program statement
    |
    ;

statement:
    assignment ';'
    ;

assignment:
    ID '=' expr    { set_var_value($1, $3); free($1); free($3); }
    ;

expr:
    expr '+' term    { 
        char* tmp = malloc(strlen($1) + strlen($3) + 1);
        strcpy(tmp, $1);
        strcat(tmp, $3);
        $$ = tmp;
        free($1); free($3);
    }
    | term          { $$ = $1; }
    ;

term:
    STRING_LITERAL     { 
        /* Remove surrounding quotes */
        char* str = strdup($1);
        str[strlen(str)-1] = '\0';
        $$ = strdup(&str[1]);
        free(str); free($1);
    }
    | ID               { 
        char* val = get_var_value($1);
        if (val) {
            $$ = strdup(val);
        } else {
            yyerror("Undefined variable");
            $$ = strdup("");
        }
        free($1);
    }
    | function_call    { $$ = $1; }
    ;

function_call:
    LENGTH '(' expr ')'    {
        char buffer[20];
        sprintf(buffer, "%d", (int)strlen($3));
        $$ = strdup(buffer);
        free($3);
    }
    | REVERSE '(' expr ')'  {
        int len = strlen($3);
        char* reversed = malloc(len +1);
        for(int i=0; i<len; i++){
            reversed[i] = $3[len - i -1];
        }
        reversed[len] = '\0';
        $$ = reversed;
        free($3);
    }
    | SUBSTRING '(' expr ',' NUMBER ',' NUMBER ')' {
        int start = $5;
        int end = $7;
        int len_str = strlen($3);
        int len = end - start;
        if(len<0 || start<0 || end>len_str){
            yyerror("Invalid substring indices");
            $$ = strdup("");
        } else {
            char* substr = malloc(len +1);
            strncpy(substr, $3 + start, len);
            substr[len] = '\0';
            $$ = substr;
        }
        free($3);
    }
    | PALINDROME '(' expr ')' {
        int len = strlen($3);
        int is_palindrome = 1;
        for(int i=0; i<len/2; i++){
            if($3[i] != $3[len - i -1]){
                is_palindrome = 0;
                break;
            }
        }
        if(is_palindrome)
            $$ = strdup("true");
        else
            $$ = strdup("false");
        free($3);
    }
    ;

%%

char* get_var_value(char* name) {
    for(int i=0; i<var_count; i++){
        if(strcmp(vars[i].name, name) == 0){
            return vars[i].value;
        }
    }
    return NULL;
}

void set_var_value(char* name, char* value) {
    for(int i=0; i<var_count; i++){
        if(strcmp(vars[i].name, name) == 0){
            free(vars[i].value);
            vars[i].value = strdup(value);
            return;
        }
    }
    if(var_count < MAX_VARS){
        vars[var_count].name = strdup(name);
        vars[var_count].value = strdup(value);
        var_count++;
    } else {
        yyerror("Variable limit reached");
    }
}

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

int main(void){
    yylineno = 1;
    yyparse();
    printf("Variables:\n");
    for(int i=0; i<var_count; i++){
        printf("%s = %s\n", vars[i].name, vars[i].value);
        free(vars[i].name);
        free(vars[i].value);
    }
    return 0;
}
