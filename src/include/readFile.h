#ifndef READ_FILE_H
#define READ_FILE_H

#include "stdio.h"
#include "ptr.h"

typedef struct File {
    ptr self;
    FILE* file_ref;
} file;

file* openFile(char* fileName);

char next(file* f);

#endif