//
// Created by andrey.zavodov on 14.12.18.
//

#include "functions.h"

int print(token** tok_ptr, program_state state){

    (*tok_ptr) = (*tok_ptr)->next;

    token* tok = *tok_ptr;

    write(STDOUT_FILENO, tok->token, strlen(tok->token));
    
    return 0;
}
