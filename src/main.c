#include <stdio.h>
#include <string.h>

#include "commands/init.h"

int main(int argc, char *argv[]) {
        if (argc < 2) {
                fprintf(stderr, "Usage: tig <command> [args]\n");
        }

        if (strcmp(argv[1], "init") == 0) {
                init();
        }
}
