#include "include/lexer.h"

void destory_lexer(any* pointer) {
    lexer* l =(lexer*) pointer;
    del(l->src);
    free(l); 
}

lexer* new_lexer(file* src) {
    any* pointer = smalloc(sizeof(lexer),&destory_lexer);
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