#include "include/readFile.h"
#include <stdlib.h>

void destoryFile(any* p) {
    file* f= p->to;
    fclose(f->file_ref);
    free(f);
}

file* openFile(char* fileName) {
    any* pointer = smalloc(sizeof(file), &destoryFile);
    file* f = pointer->to;
    f->self = *pointer;
    f->file_ref = fopen(fileName, "r");

    return f;
}

char next(file* f) {
    return fgetc(f->file_ref);
}