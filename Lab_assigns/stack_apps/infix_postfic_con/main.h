#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>

//prototypes

void infix_postfix(char *infix, char *postfix);

int stack_precedence(char ch);

int infix_precedence(char ch);
#endif
