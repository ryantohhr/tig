#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void init() {
        struct stat st;
        FILE *head_file;

        if (stat(".tig", &st) == 0 && S_ISDIR(st.st_mode)) {
                fprintf(stderr, "fatal: existing Tig repository detected\n");
                exit(EXIT_FAILURE);
        }

        if (mkdir(".tig", 0755) == -1) {
                fprintf(stderr, "Failed to create .tig directory: %s\n",
                        strerror(errno));
                exit(EXIT_FAILURE);
        }
        if (mkdir(".tig/objects", 0755) == -1) {
                fprintf(stderr, "Failed to create objects directory: %s\n",
                        strerror(errno));
                exit(EXIT_FAILURE);
        }
        if (mkdir(".tig/refs", 0755) == -1) {
                fprintf(stderr, "Failed to create refs directory: %s\n",
                        strerror(errno));
                exit(EXIT_FAILURE);
        }
        if (mkdir(".tig/refs/heads", 0755) == -1) {
                fprintf(stderr, "Failed to create refs/heads directory: %s\n",
                        strerror(errno));
                exit(EXIT_FAILURE);
        }

        head_file = fopen(".tig/HEAD", "w");
        if (!head_file) {
                fprintf(stderr, "Failed to create .tig/HEAD file: %s\n",
                        strerror(errno));
                exit(1);
        }
        fputs("ref: refs/heads/main\n", head_file);
        fclose(head_file);
}
