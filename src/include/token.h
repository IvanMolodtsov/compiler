#ifndef TOKEN_H
#define TOKEN_H

#include "ptr.h"
#include "str.h"

typedef struct Token
{
    ptr* self;
    str* name;
} token;


#endif