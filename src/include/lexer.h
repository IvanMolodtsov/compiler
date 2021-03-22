#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include "stddef.h"

typedef struct Lexer
{
    size_t index;
    char* file;
    char current;

} lexer;

token* nextToken(lexer* l);

void next(lexer* l);


#endif