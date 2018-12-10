//
// Created by andrey.zavodov on 10.12.18.
//

#include <memory.h>
#include <stdlib.h>
#include "parser.h"

char* _get_block(char** code_ptr, char start_br, char end_br){

    int br = 0;
    char* block_start = NULL;
    char* block_end = NULL;
    char* code = *code_ptr;

    for (int i = 0; i < strlen(code); i++){
        if (code[i] == start_br) {
            br++;
            if (br == 1) {
                block_start = (code + i);
            }
        }
        if (code[i] == end_br && br > 0) {
            br--;
            if (br == 0) {
                block_end = (code + i);
                break;
            }
        }
    }

    size_t len = block_end - block_start + 1;
    char* new_string = (char*)malloc(len);

    if (strncpy(new_string, block_start, len)) {
        *code_ptr = block_end;
        return new_string;
    } else {
        return NULL;
    }
}

program parse_blocks(char* code){

    program pr;

    char* begin_block = strstr(code, "BEGIN");
    if (begin_block != NULL){
        code = begin_block;
        pr.begin_block = _get_block(& code, '{', '}');
    } else {
        pr.begin_block = NULL;
    }

    pr.main_block = _get_block(& code, '{', '}');

    char* end_block = strstr(code, "END");
    if (begin_block != NULL){
        code = end_block;
        pr.end_block = _get_block(& code, '{', '}');
    } else {
        pr.end_block = NULL;
    }

    return pr;

}
