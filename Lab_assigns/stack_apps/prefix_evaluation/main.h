#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//prototypes

void infix_prefix(char *infix, char *prefix);

int stack_precedence(char ch);

int infix_precedence(char ch);

void reverse(char *str);

void prefix_eval(char *prefix);

float evaluation(float f1, float f2, char operators);
#endif
