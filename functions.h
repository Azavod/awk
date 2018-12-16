//
// Created by andrey.zavodov on 14.12.18.
//

#ifndef AWK_FUNCTIONS_H
#define AWK_FUNCTIONS_H

#include "interpreter.h"
#include "utils.h"

#include <string.h>
#include <unistd.h>
#include <memory.h>
#include <regex.h>

int print(token** token, program_state state);
int check_regex(char* record, char* pattern);

#endif //AWK_FUNCTIONS_H
