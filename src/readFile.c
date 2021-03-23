#include "include/readFile.h"

void destroyFile(ptr* p) {
    file* f= p->to;
    fclose(f->file_ref);
    free(f);
}

file* openFile(char* fileName) {
    ptr* pointer = smalloc(sizeof(file), &destroyFile);
    file* f = pointer->to;
    f->self = *pointer;
    f->file_ref = fopen(fileName, "r");

    return f;
}

char next(file* f) {
    return fgetc(f->file_ref);
}