//
// Created by andrey.zavodov on 10.12.18.
//

#ifndef AWK_PARSER_H
#define AWK_PARSER_H

#include "interpreter.h"

typedef struct {
    token* begin_block;
    token* main_block;
    token* end_block;
} program;

program parse_blocks(char* code);
void free_structure(token* tok);

#endif //AWK_PARSER_H
