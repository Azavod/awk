//
// Created by andrey.zavodov on 08.12.18.
//

#include <printf.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

void message(char *type, char *msg){
    char message[strlen(type) + strlen(msg) + 5];
    strcpy(message, type);
    strcat(message, " - ");
    strcat(message, msg);

    write(STDERR_FILENO, message, strlen(message));

    if (strcmp(type, "ERROR") == 0) {
        exit(EXIT_FAILURE);
    }
}
