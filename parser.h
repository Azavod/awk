//
// Created by andrey.zavodov on 10.12.18.
//

#ifndef AWK_PARSER_H
#define AWK_PARSER_H

typedef struct {
    char* begin_block;
    char* main_block;
    char* end_block;
} program;

program parse_blocks(char* code);

#endif //AWK_PARSER_H
