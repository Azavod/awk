//
// Created by andrey.zavodov on 07.12.18.
//

#include <wchar.h>
#include <unistd.h>
#include <printf.h>
#include <sys/stat.h>
#include <stdio.h>
#include "interpreter.h"
#include "utils.h"

int do_awk(char* program, program_state state){

    state.NF = 0;
    state.NR = 0;
    state.FIELDS = NULL;
    state.RECORD = NULL;

    if (close(state.FILENO) < 0) {
        message("ERROR", "File cannot be read\n");
    }

    return 0;

}
