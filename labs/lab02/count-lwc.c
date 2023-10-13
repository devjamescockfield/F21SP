#include <stdio.h>

/* Counts how many characters, words, lines are in the `fin` file */
int count(FILE *fin, int *chars, int *words, int *lines)
{
    char c;

    *chars = 0;
    *words = 0;
    *lines = 1;

    do
    {
        c = fgetc(fin);

        // get number of characters
        *chars = *chars + 1;

        // get number of words

        if (c == ' ' || c == '\n' || c == '\t')
        {
            *words = *words + 1;
        }

        // get number of lines
        if (c == '\n')
        {
            *lines = *lines + 1;
        }

    } while (c != EOF);

    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fin;
    int chars;
    int words;
    int lines;
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
        count(fin, &chars, &words, &lines);
        printf("%d chars, %d words, %d lines\n", chars, words, lines);
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

            count(fin, &chars, &words, &lines);
            printf("%d chars, %d words, %d lines %s\n", chars, words, lines, argv[i]);
            total += chars;
            fclose(fin);
        }
    }

    printf("%d total chars\n", total);

    return 0;
}
