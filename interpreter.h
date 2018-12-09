//
// Created by andrey.zavodov on 07.12.18.
//

#ifndef AWK_INTERPRETER_H
#define AWK_INTERPRETER_H

typedef struct {
    int FILENO;
    char FS;        // fields separator
    char RS;        // rows separator
    size_t NF;         // number of fields
    size_t NR;         // number of rows
    char OFS;       // output fields separator
    char ORS;       // output rows separator
    char *RECORD;   // current record
    char **FIELDS;  // fields in current record
} program_state;

int do_awk(char* program, program_state state);

#endif //AWK_INTERPRETER_H
