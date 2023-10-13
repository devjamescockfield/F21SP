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
    int total = 0;

    /* TODO: check that argc is correct */
    if (argc < 1)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (argc == 1)
    {
        fin = stdin;
        if (fin == NULL)
        {
            printf("Error opening file\n");
            return 1;
        }
        int chars = count(fin);
        printf("%d entered\n", chars);
        total += chars;
    }
    else if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            fin = fopen(argv[i], "r");
            if (fin == NULL)
            {
                printf("Error opening file %s\n", argv[i]);
                return 1;
            }
            int chars = count(fin);
            printf("%d %s\n", chars, argv[i]);
            total += chars;
            fclose(fin);
        }
    }

    printf("%d total\n", total);

    return 0;
}
