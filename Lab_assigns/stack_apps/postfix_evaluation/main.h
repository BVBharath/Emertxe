#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//prototypes

void infix_postfix(char *infix, char *postfix);

int stack_precedence(char ch);

int infix_precedence(char ch);

void postfix_eval(char *postfix);

float evaluation(float t1, float t2, char operators);
#endif
