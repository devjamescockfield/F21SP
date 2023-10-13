/* Example broken program for Systems Programming seminar/lab 5.
 * Compile this with:
 *   gcc -std=c99 -Wall -g -o seminar04 seminar04.c
 *
 * This is intended to take a list of text files on the command line, and print
 * out the lines in each file backwards. There are (at least) 3 faults in it!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Line {
    // Pointer to the previous line, or NULL if this is the first line
    struct Line *prev;

    // Text of the line (this should be big enough for any line)
    char text[80];
};

void print_backwards(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Could not open '%s'\n", filename);
        exit(1);
    }

    // The linked list of lines we've read
    struct Line *lines = NULL;

    // Read the input
    for (;;) {
        // Allocate a new line
        struct Line *line = malloc(sizeof *line);

        if (fgets(line->text, 90, f) == NULL) {
            // End of file
            free(line);
            break;
        }

        // Append to the linked list
        line->prev = lines;
        lines = line;
    }

    // Print out the lines (backwards)
    struct Line *line = lines;
    do {
        fputs(line->text, stdout);
        line = line->prev;
    } while (line != NULL);

    fclose(f);
}

int main(int argc, char *argv[]) {
    // Print each file named on the command line
    for (int i = 1; i < argc; i++) {
        print_backwards(argv[i]);
    }

    return 0;
}
