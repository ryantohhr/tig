#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands/init.h"

int main(int argc, char *argv[]) {
        if (argc < 2) {
                fprintf(stderr, "Usage: tig <command> [args]\n");
                exit(EXIT_FAILURE);
        }

        if (strcmp(argv[1], "init") == 0) {
                init();
        }
}
