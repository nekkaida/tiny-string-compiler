%{
/* Include standard C libraries needed for input/output, string manipulation, and character functions. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>    // For character functions like toupper, tolower, and isspace

/* Define a maximum number of variables that can be stored. */
#define MAX_VARS 100

/* Declare the external variable for line numbers, used in error messages. */
extern int yylineno;

/* Define a structure to represent a variable, which has a name and a value. */
struct var {
    char* name;   /* Variable name */
    char* value;  /* Variable value */
};

/* Declare an array to act as a simple symbol table for storing variables. */
struct var vars[MAX_VARS];
int var_count = 0;  /* Keep track of the number of variables stored */

/* Function prototypes for managing variables and handling errors. */
char* get_var_value(char* name);
void set_var_value(char* name, char* value);

/* Function prototypes for lexer and error reporting. */
int yylex(void);
void yyerror(const char *s);
%}

/* Define a union to specify the types of semantic values that tokens and non-terminals can have. */
%union {
    char* sval;  /* For string values */
    int ival;    /* For integer values */
}

/* Declare tokens with their associated types. */
%token <sval> ID STRING_LITERAL  /* ID and STRING_LITERAL have string values */
%token <ival> NUMBER             /* NUMBER has an integer value */
%token LENGTH REVERSE SUBSTRING PALINDROME  /* Tokens for string functions */
%token TOUPPER TOLOWER PADLEFT PADRIGHT TRIM FIND  /* Tokens for new string functions */
%token REPLACE SPLIT JOIN COUNT


/* Declare the types of non-terminal symbols used in the grammar rules. */
%type <sval> expr term function_call

/* Start of the grammar rules section. */
%%
/* The 'program' rule defines the structure of the program as a sequence of statements. */
program:
    program statement   /* A program can be another program followed by a statement */
    |
    ;                   /* An empty program */

/* A 'statement' is an assignment followed by a semicolon. */
statement:
    assignment ';'
    ;

/* An 'assignment' assigns the value of an expression to a variable. */
assignment:
    ID '=' expr    {
        /* Store the variable and its value in the symbol table. */
        set_var_value($1, $3);
        /* Free the memory allocated for the variable name and value. */
        free($1);
        free($3);
    }
    ;

/* An 'expr' can be an expression concatenated with a term, or just a term. */
expr:
    expr '+' term    {
        /* Concatenate the two strings. */
        char* tmp = malloc(strlen($1) + strlen($3) + 1);
        strcpy(tmp, $1);
        strcat(tmp, $3);
        $$ = tmp;  /* Set the result as the value of the expression */
        /* Free the memory allocated for the operands. */
        free($1);
        free($3);
    }
    | term          { $$ = $1; }  /* An expression can also be a single term */
    ;

/* A 'term' can be a string literal, an identifier, or a function call. */
term:
    STRING_LITERAL     {
        /* Remove the surrounding quotes from the string literal. */
        char* str = strdup($1);
        str[strlen(str)-1] = '\0';       /* Remove the ending quote */
        $$ = strdup(&str[1]);            /* Remove the starting quote */
        /* Free the temporary strings. */
        free(str);
        free($1);
    }
    | ID               {
        /* Retrieve the value of the variable from the symbol table. */
        char* val = get_var_value($1);
        if (val) {
            $$ = strdup(val);  /* Set the variable's value as the term's value */
        } else {
            yyerror("Undefined variable");  /* Report an error if the variable is not found */
            $$ = strdup("");  /* Set an empty string to prevent crashes */
        }
        free($1);  /* Free the memory allocated for the variable name */
    }
    | function_call    { $$ = $1; }  /* A term can also be the result of a function call */
    ;

/* Define how each function call is handled. */
function_call:
    LENGTH '(' expr ')'    {
        /* Calculate the length of the string and convert it to a string. */
        char buffer[20];
        sprintf(buffer, "%d", (int)strlen($3));
        $$ = strdup(buffer);  /* Set the length as the function's result */
        free($3);             /* Free the memory allocated for the argument */
    }
    | REVERSE '(' expr ')'  {
        /* Reverse the input string. */
        int len = strlen($3);
        char* reversed = malloc(len +1);
        for(int i=0; i<len; i++){
            reversed[i] = $3[len - i -1];  /* Copy characters from the end to the start */
        }
        reversed[len] = '\0';  /* Null-terminate the reversed string */
        $$ = reversed;         /* Set the reversed string as the function's result */
        free($3);              /* Free the memory allocated for the argument */
    }
    | SUBSTRING '(' expr ',' NUMBER ',' NUMBER ')' {
        /* Extract a substring from the input string between 'start' and 'end' indices. */
        int start = $5;  /* Starting index */
        int end = $7;    /* Ending index */
        int len_str = strlen($3);
        int len = end - start;
        if(len<0 || start<0 || end>len_str){
            yyerror("Invalid substring indices");  /* Report an error if indices are invalid */
            $$ = strdup("");  /* Set an empty string to prevent crashes */
        } else {
            char* substr = malloc(len +1);
            strncpy(substr, $3 + start, len);  /* Copy the substring */
            substr[len] = '\0';                /* Null-terminate the substring */
            $$ = substr;  /* Set the substring as the function's result */
        }
        free($3);  /* Free the memory allocated for the input string */
    }
    | PALINDROME '(' expr ')' {
        /* Check if the input string is a palindrome. */
        int len = strlen($3);
        int is_palindrome = 1;  /* Flag to indicate if it's a palindrome */
        for(int i=0; i<len/2; i++){
            if($3[i] != $3[len - i -1]){
                is_palindrome = 0;  /* Set flag to 0 if characters don't match */
                break;
            }
        }
        if(is_palindrome)
            $$ = strdup("true");   /* Set result to "true" */
        else
            $$ = strdup("false");  /* Set result to "false" */
        free($3);  /* Free the memory allocated for the input string */
    }
    | TOUPPER '(' expr ')' {
        /* Convert the input string to uppercase. */
        int len = strlen($3);
        char* upper_str = strdup($3);
        for(int i = 0; i < len; i++) {
            upper_str[i] = toupper((unsigned char)upper_str[i]);
        }
        $$ = upper_str;  /* Set the uppercase string as the function's result */
        free($3);        /* Free the memory allocated for the input string */
    }
    | TOLOWER '(' expr ')' {
        /* Convert the input string to lowercase. */
        int len = strlen($3);
        char* lower_str = strdup($3);
        for(int i = 0; i < len; i++) {
            lower_str[i] = tolower((unsigned char)lower_str[i]);
        }
        $$ = lower_str;  /* Set the lowercase string as the function's result */
        free($3);        /* Free the memory allocated for the input string */
    }
    | PADLEFT '(' expr ',' NUMBER ',' STRING_LITERAL ')' {
        /* Pad the input string on the left with a character to reach the total length. */
        int total_length = $5;  /* Desired total length */
        /* Process the pad character string literal */
        char* pad_str = strdup($7);
        pad_str[strlen(pad_str)-1] = '\0';  /* Remove ending quote */
        char* pad_content = &pad_str[1];    /* Remove starting quote */
        char pad_char;
        if (strlen(pad_content) >= 1) {
            pad_char = pad_content[0];     /* Use the first character */
        } else {
            yyerror("Pad character must not be empty");
            pad_char = ' ';  /* Default to space */
        }
        int str_len = strlen($3);
        if(total_length <= str_len) {
            $$ = strdup($3);  /* Return the original string */
        } else {
            int pad_len = total_length - str_len;
            char* padded_str = malloc(total_length + 1);
            memset(padded_str, pad_char, pad_len);       /* Fill with pad_char */
            strcpy(padded_str + pad_len, $3);            /* Copy the original string */
            padded_str[total_length] = '\0';             /* Null-terminate */
            $$ = padded_str;
        }
        free(pad_str);
        free($3);
        free($7);
    }
    | PADRIGHT '(' expr ',' NUMBER ',' STRING_LITERAL ')' {
        /* Pad the input string on the right with a character to reach the total length. */
        int total_length = $5;  /* Desired total length */
        /* Process the pad character string literal */
        char* pad_str = strdup($7);
        pad_str[strlen(pad_str)-1] = '\0';  /* Remove ending quote */
        char* pad_content = &pad_str[1];    /* Remove starting quote */
        char pad_char;
        if (strlen(pad_content) >= 1) {
            pad_char = pad_content[0];     /* Use the first character */
        } else {
            yyerror("Pad character must not be empty");
            pad_char = ' ';  /* Default to space */
        }
        int str_len = strlen($3);
        if(total_length <= str_len) {
            $$ = strdup($3);  /* Return the original string */
        } else {
            int pad_len = total_length - str_len;
            char* padded_str = malloc(total_length + 1);
            strcpy(padded_str, $3);                        /* Copy the original string */
            memset(padded_str + str_len, pad_char, pad_len); /* Fill with pad_char */
            padded_str[total_length] = '\0';               /* Null-terminate */
            $$ = padded_str;
        }
        free(pad_str);
        free($3);
        free($7);
    }
    | TRIM '(' expr ')' {
        /* Trim leading and trailing whitespace from the input string. */
        char* trimmed_str = strdup($3);
        char* start = trimmed_str;
        char* end = trimmed_str + strlen(trimmed_str) - 1;

        /* Trim leading whitespace */
        while(isspace((unsigned char)*start)) start++;

        /* Trim trailing whitespace */
        while(end >= start && isspace((unsigned char)*end)) end--;
        *(end + 1) = '\0';  /* Null-terminate after the last non-space character */

        $$ = strdup(start);  /* Set the trimmed string as the function's result */
        free(trimmed_str);   /* Free the temporary string */
        free($3);            /* Free the memory allocated for the input string */
    }
    | FIND '(' expr ',' expr ')' {
        /* Find the index of the substring within the input string. */
        char* haystack = $3;  /* The string to search in */
        char* needle = $5;    /* The substring to find */
        char* pos = strstr(haystack, needle);  /* Find the substring */
        if(pos) {
            int index = pos - haystack;  /* Calculate the index */
            char buffer[20];
            sprintf(buffer, "%d", index);
            $$ = strdup(buffer);  /* Set the index as the function's result */
        } else {
            $$ = strdup("-1");  /* Return -1 if the substring is not found */
        }
        free($3);  /* Free the memory allocated for the haystack string */
        free($5);  /* Free the memory allocated for the needle string */
    }
    | REPLACE '(' expr ',' expr ',' expr ')' {
        /* Replace occurrences of $5 in $3 with $7 */
        char* source = $3;
        char* old_substr = $5;
        char* new_substr = $7;

        /* Prepare for replacement */
        int source_len = strlen(source);
        int old_len = strlen(old_substr);
        int new_len = strlen(new_substr);

        if (old_len == 0) {
            yyerror("Old substring for replace function cannot be empty");
            $$ = strdup(source);  /* Return the original string */
        } else {
            /* Count the number of occurrences of old_substr in source */
            int count = 0;
            char* pos = source;
            while ((pos = strstr(pos, old_substr)) != NULL) {
                count++;
                pos += old_len;
            }

            /* Calculate the maximum length of the result */
            int max_result_len = source_len + count * (new_len - old_len) + 1;

            char* result = malloc(max_result_len);
            result[0] = '\0';

            /* Now perform the replacement */
            pos = source;
            char* match;
            while ((match = strstr(pos, old_substr)) != NULL) {
                /* Copy part before match */
                strncat(result, pos, match - pos);
                /* Append new_substr */
                strcat(result, new_substr);
                /* Move position past the match */
                pos = match + old_len;
            }
            /* Append remaining part */
            strcat(result, pos);
            $$ = result;
        }
        free($3);
        free($5);
        free($7);
    }
    | SPLIT '(' expr ',' STRING_LITERAL ')' {
        /* Split $3 by the delimiter $5 and return a string with elements separated by spaces */
        char* source = $3;
        char* delim = $5;
        delim[strlen(delim)-1] = '\0';         /* Remove ending quote */
        char* delim_char = &delim[1];          /* Remove starting quote */

        /* Duplicate the source string to avoid modifying the original */
        char* temp_str = strdup(source);
        char* token;
        char* rest = temp_str;
        /* Allocate initial result string */
        char* result = malloc(1);
        result[0] = '\0';
        int result_size = 1;

        /* Split the string */
        while ((token = strtok_r(rest, delim_char, &rest))) {
            /* Append token and a space */
            result_size += strlen(token) + 1;
            result = realloc(result, result_size);
            strcat(result, token);
            strcat(result, " ");
        }
        if (strlen(result) > 0) {
            result[strlen(result)-1] = '\0'; /* Remove trailing space */
        }
        $$ = result;
        free(temp_str);
        free($3);
        free($5);
    }
    | JOIN '(' expr ',' STRING_LITERAL ')' {
        /* Join elements in $3 separated by spaces using separator $5 */
        char* source = $3;
        char* sep = $5;
        sep[strlen(sep)-1] = '\0';         /* Remove ending quote */
        char* sep_str = &sep[1];           /* Remove starting quote */

        /* Duplicate the source string */
        char* temp_str = strdup(source);
        char* token;
        char* rest = temp_str;

        /* Count tokens */
        int token_count = 0;
        char* temp_str_copy = strdup(source);  /* Copy for counting tokens */
        char* rest_copy = temp_str_copy;
        while ((token = strtok_r(rest_copy, " ", &rest_copy))) {
            token_count++;
        }
        free(temp_str_copy);

        /* Allocate array to store tokens */
        char** tokens = malloc(token_count * sizeof(char*));
        int idx = 0;
        rest = temp_str;  /* Reset rest pointer */
        while ((token = strtok_r(rest, " ", &rest))) {
            tokens[idx++] = strdup(token);
        }

        /* Calculate result size */
        int result_size = 1; /* For null terminator */
        for (int i = 0; i < idx; i++) {
            result_size += strlen(tokens[i]) + ((i < idx - 1) ? strlen(sep_str) : 0);
        }

        /* Build the result string */
        char* result = malloc(result_size);
        result[0] = '\0';
        for (int i = 0; i < idx; i++) {
            strcat(result, tokens[i]);
            if (i < idx - 1) {
                strcat(result, sep_str);
            }
            free(tokens[i]); /* Free each token */
        }
        $$ = result;

        /* Free allocated memory */
        free(temp_str);
        free(tokens);
        free($3);
        free($5);
    }
    | COUNT '(' expr ',' expr ')' {
        /* Count occurrences of $5 in $3 */
        char* source = $3;
        char* substr = $5;
        int count = 0;
        char* pos = source;
        int substr_len = strlen(substr);
        if (substr_len == 0) {
            yyerror("Substring for count function cannot be empty");
            $$ = strdup("0");
        } else {
            while ((pos = strstr(pos, substr)) != NULL) {
                count++;
                pos += substr_len;
            }
            char buffer[20];
            sprintf(buffer, "%d", count);
            $$ = strdup(buffer);
        }
        free($3);
        free($5);
    }
    ;

/* End of the grammar rules section. */
%%

/* Function to retrieve the value of a variable from the symbol table. */
char* get_var_value(char* name) {
    for(int i=0; i<var_count; i++){
        if(strcmp(vars[i].name, name) == 0){
            return vars[i].value;  /* Return the value if the name matches */
        }
    }
    return NULL;  /* Return NULL if the variable is not found */
}

/* Function to set the value of a variable in the symbol table. */
void set_var_value(char* name, char* value) {
    for(int i=0; i<var_count; i++){
        if(strcmp(vars[i].name, name) == 0){
            /* Update the value if the variable already exists. */
            free(vars[i].value);  /* Free the old value */
            vars[i].value = strdup(value);  /* Store the new value */
            return;
        }
    }
    if(var_count < MAX_VARS){
        /* Add a new variable if there is space in the symbol table. */
        vars[var_count].name = strdup(name);
        vars[var_count].value = strdup(value);
        var_count++;
    } else {
        yyerror("Variable limit reached");  /* Report an error if the table is full */
    }
}

/* Function to report parsing errors with line numbers. */
void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

/* The main function initializes the line number and starts the parsing process. */
int main(void){
    yylineno = 1;  /* Initialize the line number */
    yyparse();     /* Start parsing the input */
    /* After parsing, print all variables and their values. */
    printf("Output:\n");
    for(int i=0; i<var_count; i++){
        printf("%s = %s\n", vars[i].name, vars[i].value);
        /* Free the memory allocated for variable names and values. */
        free(vars[i].name);
        free(vars[i].value);
    }
    return 0;  /* Exit the program */
}
