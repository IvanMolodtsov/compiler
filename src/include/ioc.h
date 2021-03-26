#ifndef IOC_H
#define IOC_H

#include "types/any.h"
#include "dependency.h"
#include "scope.h"
#include "types/string.h"
#include "types/array.h"


typedef struct ioc_container
{
    scope* current;
} ioc;

ioc IOC; 

void init_ioc();

void register_dependency(string* key, any* (*invoke)(any**));
any* resolve(string* key, array* params);


#endif