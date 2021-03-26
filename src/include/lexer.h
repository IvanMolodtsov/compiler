#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include "stddef.h"
#include "readFile.h"

typedef struct Lexer
{
    any self;
    size_t index;
    file* src;
    char current;

} lexer;

lexer* new_lexer(file* src);

token* nextToken(lexer* l);

#endif