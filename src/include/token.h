#ifndef TOKEN_H
#define TOKEN_H

#include "types/ptr.h"
#include "types/str.h"

typedef struct Token
{
    ptr* self;
    str* name;
} token;


#endif