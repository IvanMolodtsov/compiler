#ifndef IOC_H
#define IOC_H

#include "ptr.h"
#include "dependency.h"
#include "scope.h"


typedef struct ioc_container
{
    scope* current;
} ioc;

ioc IOC; 

void init_ioc();

void register_dependency(char* key, ptr* (*invoke)(ptr**));
ptr* resolve(char* key, ptr** params);


#endif