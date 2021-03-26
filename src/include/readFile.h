#ifndef READ_FILE_H
#define READ_FILE_H

#include "stdio.h"
#include "types/any.h"

typedef struct File {
    any self;
    FILE* file_ref;
} file;

file* openFile(char* fileName);

char next(file* f);

#endif