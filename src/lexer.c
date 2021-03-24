#include "include/lexer.h"

void destroy_lexer(ptr* pointer) {
    lexer* l =(lexer*) pointer;
    del(l->src);
    free(l); 
}

lexer* new_lexer(file* src) {
    ptr* pointer = smalloc(sizeof(lexer),&destroy_lexer);
    lexer* l = pointer->to;
    l->self = *pointer;
    l->src = src;
    l->index = 0;
    l->current = next(src);
    return l;
}

token* nextToken(lexer* l) {
    return NULL;
}