#ifndef TOKEN_H
#define TOKEN_H

#include "types/any.h"
#include "types/string.h"

typedef struct Token
{
    any* self;
    string* name;
} token;


#endif