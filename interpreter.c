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
#include <assert.h>
#include "interpreter.h"
#include "utils.h"


char **str_split(const char *b_str, const char a_delim) {
    char a_str[strlen(b_str)];
    strcpy(a_str, b_str);
    char *tmp = a_str;

    char **result = 0;
    size_t count = 0;

    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result) {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


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
        state.FIELDS = str_split(state.RECORD, state.FS);

    }

    return 0;

}
