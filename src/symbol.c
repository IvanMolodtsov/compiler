#include "include/types/symbol.h"

void destroy_symbol(ptr* pointer) {
    symbol* s = pointer->to;
    free(s);
}

symbol* new_symbol(char s) {
    ptr* pointer = smalloc(sizeof(symbol), &destroy_symbol);
    symbol* sym = pointer->to;
    sym->self = *pointer;
    sym->symbol = s;
    return s;
}

bool compare_symbol(symbol* s1, symbol* s2) {
    if (s1->symbol != s2->symbol) {
        return false;
    } else {
        return true;
    }
}