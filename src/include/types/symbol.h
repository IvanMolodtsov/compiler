#ifndef SYMBOL_H
#define SYMBOL_H

#include "any.h"
#include "stdbool.h"

typedef struct Symbol
{
    any self;
    char symbol;
} symbol;

symbol* new_symbol(char s);

bool compare_symbol(symbol* s1, symbol* s2);

#endif