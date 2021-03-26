#include "include/types/symbol.h"
#include <stdlib.h>

void destory_symbol(any* pointer) {
    symbol* s = pointer->to;
    free(s);
}

symbol* new_symbol(char s) {
    any* pointer = smalloc(sizeof(symbol), &destory_symbol);
    symbol* sym = pointer->to;
    sym->self = *pointer;
    sym->symbol = s;
    return sym;
}

bool compare_symbol(symbol* s1, symbol* s2) {
    if (s1->symbol != s2->symbol) {
        return false;
    } else {
        return true;
    }
}