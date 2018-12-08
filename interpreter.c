//
// Created by andrey.zavodov on 07.12.18.
//

#include <wchar.h>
#include <unistd.h>
#include <printf.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "interpreter.h"
#include "utils.h"

int do_awk(char* program, program_state state){

    state.NF = 0;
    state.NR = 0;
    state.FIELDS = NULL;
    state.RECORD = NULL;

    struct stat fsbuf;
    if (fstat(state.FILENO, &fsbuf) < 0) {
        message("ERROR", "File cannot be read\n");
    }

    char *buf = (char*)calloc(1, 1);
    size_t buf_size = sizeof(*buf);

    for (size_t offset = 0; offset < fsbuf.st_size; ){

        char *record = (char*)calloc(1, 1);

        do{
            read(state.FILENO, buf, buf_size);
            offset += buf_size;
            record = (char*)realloc(record, strlen(record) + buf_size);
            strcat(record, buf);
        } while (buf[0] != state.RS && offset < fsbuf.st_size);

        if (buf[0] == state.RS){
            record[strlen(record) - 1] = '\0'; // remove separator
        }

        state.RECORD = record;
        state.NR++;

        free(record);
    }

    return 0;

}
