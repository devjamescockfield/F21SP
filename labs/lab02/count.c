#include <stdio.h>

/* Counts how many characters are in the `fin` file */
int count(FILE *fin)
{
    int chars = 0;

    while (1)
    {
        int ch;

        /* TODO: get the next character into ch */
        ch = getc(fin);
        /* TODO: if end of file was reached (ch == EOF), exit the loop */
        if (ch == EOF)
            break;
        /* TODO: increment chars */
        chars++;
    }

    return chars;
}

int main(int argc, char *argv[])
{
    FILE *fin;

    /* TODO: check that argc is correct */
    if (argc <= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    /* TODO: open file, using the filename from the 1st command argument */
    fin = fopen(argv[1], "r");
    /* TODO: check that the file was opened successfully (fin != NULL) */
    if (fin == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    /* TODO: call count with the opened file, and print the result */
    printf("Number of characters in %s: %d\n", argv[1], count(fin));
    /* TODO: close the file */
    fclose(fin);
    return 0;
}
