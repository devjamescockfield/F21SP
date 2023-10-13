#include <stdio.h>
#include <getopt.h>

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

int main(int argc, char **argv)
{
    FILE *fin;
    int chars, words, lines, totalChars, totalWords, totalLines;
    int option_index = 0;

    int isChar = 0;
    int isWord = 0;
    int isLine = 0;

    totalChars = 0;
    totalWords = 0;
    totalLines = 0;

    while ((option_index = getopt(argc, argv, "cwl")) != -1)
    {
        switch (option_index)
        {
        case 'c':
            isChar = 1;
            break;
        case 'w':
            isWord = 1;
            break;
        case 'l':
            isLine = 1;
            break;
        default:
            break;
        }
    }

    if (argc < 2)
    {
        printf("Usage: %s [option] <filename>\n", argv[0]);
        return 1;
    }

    if (argc == 1 || (argc == 2 && option_index >= 0))
    {
        fin = stdin;
        if (fin == NULL)
        {
            printf("Error opening file\n");
            return 1;
        }

        count(fin, &chars, &words, &lines);

        if (isChar)
            printf("%d chars\n", chars);
        else if (isWord)
            printf("%d words\n", words);
        else if (isLine)
            printf("%d lines\n", lines);
        else
            printf("%d chars, %d words, %d lines\n", chars, words, lines);

        totalChars = totalChars + chars;
        totalWords = totalWords + words;
        totalLines = totalLines + lines;
    }
    else if (argc > 2)
    {
        int j;

        if (option_index < 0)
            j = 1;
        else
            j = 2;

        printf("index %d\n", option_index);
        printf("j %d\n", j);

        for (int i = j; i < argc; i++)
        {
            fin = fopen(argv[i], "r");
            if (fin == NULL)
            {
                printf("Error opening file %s\n", argv[i]);
                return 1;
            }

            count(fin, &chars, &words, &lines);

            if (isChar)
                printf("%d chars %s\n", chars, argv[i]);
            else if (isWord)
                printf("%d words %s\n", words, argv[i]);
            else if (isLine)
                printf("%d lines %s\n", lines, argv[i]);
            else
                printf("%d chars, %d words, %d lines %s\n", chars, words, lines, argv[i]);
            totalChars = totalChars + chars;
            totalWords = totalWords + words;
            totalLines = totalLines + lines;

            fclose(fin);
        }
    }

    if (isChar)
        printf("%d total chars\n", totalChars);
    else if (isWord)
        printf("%d total words\n", totalWords);
    else if (isLine)
        printf("%d total lines\n", totalLines);
    else
        printf("%d chars, %d words, %d lines totals\n", totalChars, totalWords, totalLines);

    return 0;
}
