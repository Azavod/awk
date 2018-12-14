//
// Created by andrey.zavodov on 14.12.18.
//

#include "functions.h"

int print(token** tok_ptr, program_state state){

    (*tok_ptr) = (*tok_ptr)->next;
    token* tok = *tok_ptr;

    while (tok->token && strcmp(tok->token, "}") != 0 && tok->separator != ';') {
        write(STDOUT_FILENO, tok->token, strlen(tok->token));
        if (tok->separator == ','){
            write(STDOUT_FILENO, " ", strlen(" "));
        }
        (*tok_ptr) = (*tok_ptr)->next;
        tok = *tok_ptr;
    }

    return 0;
}
