// Copyright (c) 24 December 2020 Kaustav Ghosh

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// Creating Necessary Structures
struct token
{
    int row, column;
    char type[100];
    char lexeme[100];
};

struct symbol_table_entry
{
    int index;
    struct token token;
    int size;
};

struct global_symbol_table_data
{
    char function_name[10];
    int number_of_tokens;
};

// Creating Symbol Tables
struct global_symbol_table_data global_symbol_table[10];
struct symbol_table_entry local_symbol_table[10][100];

int function_number = -1;          // Denotes which Function and ALL tokens within that function
int local_symbol_table_index = -1; // Denotes the token INDEX within that function

// Functions for Symbol Table Handling
void insert_into_local_symbol_table(struct token *retToken, int dataType_size);
void insert_into_local_symbol_table_helper(struct token *retToken);
void display_local_symbol_tables();

int row = 1;
int column = 1;
int function_scope = 0;
int array_size = 1;

char ca, cb;
char buffer[100];
char dataType_buffer[100]; // For symbol Table Entry

bool contains_keyword_datatype = false;
bool isArray = false;

// Symbol Table Functions
void insert_into_local_symbol_table(struct token *retToken, int dataType_size)
{
    struct symbol_table_entry ste;

    for (int i = 0; i < global_symbol_table[function_number].number_of_tokens; i++)
    {
        if (strcmp(retToken->lexeme, local_symbol_table[function_number][i].token.lexeme) == 0)
            return;
        // if (strncmp(retToken->lexeme, local_symbol_table[function_number][i].token.lexeme, strlen(retToken->lexeme)) == 0)
        //     return;
    }

    local_symbol_table_index++;

    ste.token = *retToken;
    ste.index = local_symbol_table_index;
    ste.size = dataType_size;

    local_symbol_table[function_number][local_symbol_table_index] = ste;
    global_symbol_table[function_number].number_of_tokens++;
}

void insert_into_local_symbol_table_helper(struct token *retToken)
{
    if (strncmp(retToken->type, "function", strlen("function")) == 0)
    {
        insert_into_local_symbol_table(retToken, -1);
    }
    if (strncmp(retToken->type, "identifier", strlen("identifier")) == 0)
    {
        strcpy(retToken->type, dataType_buffer);

        if ((strcmp(dataType_buffer, "void") == 0))
            insert_into_local_symbol_table(retToken, 0 * array_size);
        if ((strcmp(dataType_buffer, "char") == 0 || (strcmp(dataType_buffer, "bool") == 0)))
            insert_into_local_symbol_table(retToken, 1 * array_size);
        if ((strcmp(dataType_buffer, "int") == 0 || (strcmp(dataType_buffer, "float") == 0)))
            insert_into_local_symbol_table(retToken, 4 * array_size);
        if ((strcmp(dataType_buffer, "long") == 0 || (strcmp(dataType_buffer, "double") == 0)))
            insert_into_local_symbol_table(retToken, 8 * array_size);

        if (array_size > 1)
            array_size = 1;
    }
}

void display_local_symbol_tables()
{
    for (int i = 0; i <= function_number; i++)
    {
        printf("\n\nSymbol Table for Function: %s\n\n", global_symbol_table[i].function_name);
        printf("\tIndex\tLexeme\tType\tSize\n");

        for (int j = 1; j <= global_symbol_table[i].number_of_tokens; j++)
        {
            printf("%9d%9s%9s%9d\n", local_symbol_table[i][j].index, local_symbol_table[i][j].token.lexeme,
                   local_symbol_table[i][j].token.type, local_symbol_table[i][j].size);
        }
    }
}

char keywords_table[][10] = {
    "auto", "break", "bool", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "false", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "true", "union", "unsigned", "void", "volatile", "while"};

char special_symbols[][3] = {
    "`", "~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", ">", "<",
    "+", "-", "=", "[", "]", "{", "}", "|", ";", ":", ",", ".", "?", "/", "\\"};

char arithmetic_operators[][3] = {
    "+", "-", "*", "/", "%"};

char increment_decrement_operators[][3] = {
    "++", "--"};

char assignment_operators[][3] = {
    "+=", "-=", "**", "/=", "%="};

char relational_operators[][3] = {
    "==", ">", "<", "!=", ">=", "<="};

char logical_operators[][3] = {
    "&&", "||", "!="};

char bitwise_operators[][3] = {
    "&", "|", "^", "~", "<<", ">>"};

char datatypes_table[][10] = {"int", "char", "float", "double", "struct", "bool", "void", "short", "long"};

char looping_keywords[][10] = {"for", "while"};

struct token *getNextToken(FILE *fp)
{
    // Dynamic Memory Allocation
    struct token *retToken = (struct token *)malloc(sizeof(struct token));

    while ((ca = fgetc(fp)) != EOF)
    {
        memset(buffer, '\0', sizeof(buffer));
        column++;

        // Eliminating Blank Spaces and Tabs
        if (ca == ' ' || ca == '\t')
        {
            while (ca == ' ' || ca == '\t')
            {
                if (ca == ' ')
                    column = column + 1;
                else if (ca == '\t')
                    column = column + 4;
                ca = fgetc(fp);

                if (feof(fp))
                    break;
            }
        }

        if (ca == '\n')
        {
            column = 0;
            row++;
        }

        // Eliminating Single and Multiline Comments
        if (ca == '/')
        {
            ca = fgetc(fp);
            column++;

            if (ca == '/')
            {
                while (ca != '\n')
                {
                    ca = fgetc(fp);
                    column++;
                }
                // column = 0;
                // row++;
            }
            else if (ca == '*')
            {
                do
                {
                    while (ca != '*')
                    {
                        ca = fgetc(fp);
                        column++;
                        if (ca == '\n')
                        {
                            column = 0;
                            row++;
                        }
                    }

                    ca = fgetc(fp);
                    column++;
                    if (ca == '\n')
                    {
                        column = 0;
                        row++;
                    }
                } while (ca != '/');
            }

            ungetc(ca, fp);
        }

        // Checking for String Literals
        if (ca == '"')
        {
            int i = 0;
            do
            {
                buffer[i++] = ca;
                ca = fgetc(fp);
                column++;
                if (feof(fp))
                    break;
            } while (ca != '"');
            // ungetc(ca, fp);

            strcpy(retToken->lexeme, buffer);
            strcpy(retToken->type, "string_literal");
            retToken->row = row;
            retToken->column = column;
            return retToken;
        }
        // Function Scoping
        if (ca == '{')
            function_scope++;
        else if (ca == '}')
            function_scope--;

        if (ca == ';')
        {
            contains_keyword_datatype = false;
            memset(dataType_buffer, '\0', sizeof(*dataType_buffer));
            // ungetc(ca, fp);
        }

        // Checking for Special Symbols
        char special_symbol_array[3];
        memset(special_symbol_array, '\0', sizeof(special_symbol_array));
        for (int i = 0; i < sizeof(special_symbols) / sizeof(special_symbols[0]); ++i)
        {
            if (ca == special_symbols[i][0])
            {
                special_symbol_array[0] = retToken->lexeme[0] = ca;
                special_symbol_array[1] = retToken->lexeme[1] = '\0';

                strcpy(retToken->type, "special_symbols");
                cb = fgetc(fp);
                column++;

                bool multiple_char_symbol = false;
                special_symbol_array[1] = cb;
                special_symbol_array[2] = '\0';

                // Finding the category of the special symbol
                for (int k = 0; k < sizeof(arithmetic_operators) / sizeof(arithmetic_operators[0]); ++k)
                {

                    if (strlen(arithmetic_operators[k]) == 2 && strncmp(special_symbol_array, arithmetic_operators[k], 2) == 0)
                    {
                        strcpy(retToken->type, "arithmetic_operators");
                        multiple_char_symbol = true;
                        break;
                    }
                    else if (strlen(arithmetic_operators[k]) == 1 && strncmp(special_symbol_array, arithmetic_operators[k], 1) == 0)
                    {
                        strcpy(retToken->type, "arithmetic_operators");
                        multiple_char_symbol = false;
                        break;
                    }
                }

                for (int k = 0; k < sizeof(increment_decrement_operators) / sizeof(increment_decrement_operators[0]); ++k)
                {

                    if (strlen(increment_decrement_operators[k]) == 2 && strncmp(special_symbol_array, increment_decrement_operators[k], 2) == 0)
                    {
                        strcpy(retToken->type, "increment_decrement_operators");
                        multiple_char_symbol = true;
                        break;
                    }
                    else if (strlen(increment_decrement_operators[k]) == 1 && strncmp(special_symbol_array, increment_decrement_operators[k], 1) == 0)
                    {
                        strcpy(retToken->type, "increment_decrement_operators");
                        multiple_char_symbol = false;
                        break;
                    }
                }

                for (int k = 0; k < sizeof(assignment_operators) / sizeof(assignment_operators[0]); ++k)
                {

                    if (strlen(assignment_operators[k]) == 2 && strncmp(special_symbol_array, assignment_operators[k], 2) == 0)
                    {
                        strcpy(retToken->type, "assignment_operators");
                        multiple_char_symbol = true;
                        break;
                    }
                    else if (strlen(assignment_operators[k]) == 1 && strncmp(special_symbol_array, assignment_operators[k], 1) == 0)
                    {
                        strcpy(retToken->type, "assignment_operators");
                        multiple_char_symbol = false;
                        break;
                    }
                }

                for (int k = 0; k < sizeof(relational_operators) / sizeof(relational_operators[0]); ++k)
                {

                    if (strlen(relational_operators[k]) == 2 && strncmp(special_symbol_array, relational_operators[k], 2) == 0)
                    {
                        strcpy(retToken->type, "relational_operators");
                        multiple_char_symbol = true;
                        break;
                    }
                    else if (strlen(relational_operators[k]) == 1 && strncmp(special_symbol_array, relational_operators[k], 1) == 0)
                    {
                        strcpy(retToken->type, "relational_operators");
                        multiple_char_symbol = false;
                        break;
                    }
                }

                for (int k = 0; k < sizeof(logical_operators) / sizeof(logical_operators[0]); ++k)
                {

                    if (strlen(logical_operators[k]) == 2 && strncmp(special_symbol_array, logical_operators[k], 2) == 0)
                    {
                        strcpy(retToken->type, "logical_operators");
                        multiple_char_symbol = true;
                        break;
                    }
                    else if (strlen(logical_operators[k]) == 1 && strncmp(special_symbol_array, logical_operators[k], 1) == 0)
                    {
                        strcpy(retToken->type, "logical_operators");
                        multiple_char_symbol = false;
                        break;
                    }
                }
                for (int k = 0; k < sizeof(bitwise_operators) / sizeof(bitwise_operators[0]); ++k)
                {

                    if (strlen(bitwise_operators[k]) == 2 && strncmp(special_symbol_array, bitwise_operators[k], 2) == 0)
                    {
                        strcpy(retToken->type, "bitwise_operators");
                        multiple_char_symbol = true;
                        break;
                    }
                    else if (strlen(bitwise_operators[k]) == 1 && strncmp(special_symbol_array, bitwise_operators[k], 1) == 0)
                    {
                        strcpy(retToken->type, "bitwise_operators");
                        multiple_char_symbol = false;
                        break;
                    }
                }

                // In-case the special symbol is not multiple characters,push the scanned character back into the file stream
                if (multiple_char_symbol == false)
                {
                    special_symbol_array[1] = '\0';
                    ungetc(cb, fp);
                    column--;
                }

                strcpy(retToken->lexeme, special_symbol_array);

                retToken->row = row;
                retToken->column = column;
                return retToken;
            }
        }

        // Checking for Keywords, Identifiers and Constants
        if (isalnum(ca))
        {
            int i = 0;
            memset(buffer, '\0', sizeof(buffer));

            while (ca != ' ' && ca != '\n' && ca != '\t')
            {
                // printf("\n SCANNED \t %c \n", ca);
                bool contains_special_symbol = false;
                for (int i = 0; i < sizeof(special_symbols) / sizeof(special_symbols[0]); ++i)
                {
                    // if(strstr(ca,special_symbols[i]) != NULL)
                    // if (strncmp(&ca, special_symbols[i], 1) == 0)
                    if (ca == special_symbols[i][0])
                    {
                        // printf("special symbol detected\t %c \n", ca);
                        ungetc(ca, fp);
                        contains_special_symbol = true;
                        break;
                    }
                }
                if (contains_special_symbol)
                    break;

                buffer[i++] = ca;

                ca = fgetc(fp);
                column++;
            }
            // Terminating the string
            buffer[i] = '\0';

            // ungetc(ca, fp);

            // Checking for alaphabet and digits in the scanned string
            int alphabet = 0;
            int digits = 0;
            for (int i = 0; i < strlen(buffer); ++i)
            {
                // Check for letters
                if (isalpha(buffer[i]) != 0)
                    alphabet++;

                // check for decimal digits
                else if (isdigit(buffer[i]) != 0)
                    digits++;
            }

            if (alphabet == 0 && digits != 0)
            {
                // int number = atoi(buffer);
                strcpy(retToken->lexeme, buffer);
                strcpy(retToken->type, "constant");
                retToken->row = row;
                retToken->column = column;
                return retToken;
            }

            else if ((alphabet != 0 && digits == 0) || (contains_keyword_datatype == true))
            {
                for (int i = 0; i < (sizeof(keywords_table) / sizeof(keywords_table[0])); ++i)
                {
                    // if(strncmp(buffer,keywords_table[i],strlen(keywords_table[i])) == 0)
                    if (strstr(buffer, keywords_table[i]) != NULL)
                    {
                        strcpy(retToken->lexeme, keywords_table[i]);
                        strcpy(retToken->type, "keyword");
                        retToken->row = row;
                        retToken->column = column;

                        /*****************************************
                        TODO: Type of the Keyword(int,char,float,.....)
                        *****************************************/
                        for (int j = 0; j < (sizeof(datatypes_table) / sizeof(datatypes_table[0])); ++j)
                        {
                            if (strncmp(buffer, datatypes_table[j], strlen(datatypes_table[j])) == 0)
                            {
                                contains_keyword_datatype = true;
                                strcpy(dataType_buffer, buffer);
                                memset(buffer, '\0', sizeof(buffer));
                                // strcpy(retToken->type, datatypes_table[j]); // Being specific
                            }
                        }

                        return retToken;
                    }
                }

                // If it is not a keyword obviously it cannot be datatype.Checking to see if it is an identifier
                strcpy(retToken->lexeme, buffer);
                strcpy(retToken->type, "identifier");
                retToken->row = row;
                retToken->column = column;

                // Checing for a function Defintion
                if (ca == '(')
                {
                    strcpy(retToken->type, "function");
                    if (!function_scope)
                    {
                        function_number++;
                        strcpy(global_symbol_table[function_number].function_name, buffer);
                        local_symbol_table_index = 0;
                    }
                }

                /*****************************************
                TODO: Type of the Identifier(variable(int,char,float...),function...)
                *****************************************/
                // printf("\nDEBUG 1\t contains key %d\n", contains_keyword_datatype);
                if (contains_keyword_datatype == true) // && strlen(dataType_buffer) > 0)
                {

                    ca = fgetc(fp);
                    while (ca == ' ' || ca == '\t')
                        ca = fgetc(fp);
                    ungetc(ca, fp);

                    //Variables
                    if (ca == '[')
                    {
                        isArray = true;
                        int position = ftell(fp);

                        array_size = 0;
                        while ((cb = fgetc(fp)) != ']')
                        {
                            // cb = fgetc(fp);
                            if (cb != '[' && cb != ']')
                                array_size = (array_size * 10) + (cb - '0');
                        }

                        fseek(fp, position, SEEK_SET);
                        // ungetc(cb, fp);
                    }
                    //Function
                    else if (ca == '(')
                    {
                        // ungetc(ca, fp);
                        // printf("\nDEBUG 2 : %c \n", ca);
                        if (!function_scope) // Function Definition
                        {
                            // printf("\nDEBUG 4 FUNC inserted %s\n", buffer);
                            // function_number++;
                            strcpy(global_symbol_table[function_number].function_name, buffer);
                            // global_symbol_table->number_of_tokens++;
                            local_symbol_table_index = 0;
                        }
                    }

                    else if (ca == ';')
                    {
                        contains_keyword_datatype = false;
                        // memset(dataType_buffer, '\0', sizeof(*dataType_buffer));
                        // ungetc(ca, fp);
                    }
                    return retToken;
                }
                return retToken;
            }
            // The only remaining condition (Can also make the condition "else")
            else if (alphabet != 0 && digits != 0)
            {
                strcpy(retToken->lexeme, buffer);
                strcpy(retToken->type, "identifier");
                retToken->row = row;
                retToken->column = column;
                return retToken;
            }
        }
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    // FILE *fp = fopen("input_file1.c", "r");
    // FILE *fp = fopen("../LAB 03/lab03_input1_all_operators.c", "r");
    FILE *fp = fopen("input_file2_multi_function.c", "r");

    freopen("lab04_symbol_table_output.txt", "w", stdout);

    if (fp == NULL)
    {
        printf("Cannot open file \n Exiting.. \n");
        exit(0);
    }

    struct token *retToken;
    while ((retToken = getNextToken(fp)) != NULL)
    {
        printf("FNO %d FSCOPE %d\t\t", function_number, function_scope);
        printf("< %d,%d,'%s',%s >\n", retToken->row, retToken->column, retToken->lexeme, retToken->type);

        insert_into_local_symbol_table_helper(retToken);
    }

    printf("\n*******************Finished Lexical analysis*******************\n");
    display_local_symbol_tables();
    printf("\n*******************Finished Symbol Table Entries*******************\n");

    return 0;
}