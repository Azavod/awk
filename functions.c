//
// Created by andrey.zavodov on 14.12.18.
//

#include "functions.h"

int print(token** tok_ptr, program_state state){

    (*tok_ptr) = (*tok_ptr)->next;
    token* tok = *tok_ptr;

    while (tok->token && strcmp(tok->token, "}") != 0 && !strstr(tok->separator, ";")) {
        write(STDOUT_FILENO, tok->token, strlen(tok->token));
        if (strstr(tok->separator, ",")){
            write(STDOUT_FILENO, " ", strlen(" "));
        }
        (*tok_ptr) = (*tok_ptr)->next;
        tok = *tok_ptr;
    }

    write(STDOUT_FILENO, &state.ORS, strlen(&state.ORS));

    return 0;
}
