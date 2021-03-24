#ifndef IOC_H
#define IOC_H

#include "ptr.h"
#include "dependency.h"
#include "scope.h"
#include "str.h"
#include "array.h"


typedef struct ioc_container
{
    scope* current;
} ioc;

ioc IOC; 

void init_ioc();

void register_dependency(str* key, ptr* (*invoke)(ptr**));
ptr* resolve(str* key, array* params);


#endif