#include <stdio.h>

int main(int argc, char *argv[])
{
    /* TODO: check the right number of arguments have been given */
    if (argc != 4)
    {
        printf("Usage: ./merge <input file 1> <input file 2> <output file>\n");
        return 1;
    }
    /* Open the two input files */
    FILE *fin1 = fopen(argv[1], "r");
    FILE *fin2 = fopen(argv[2], "r");
    /* Open the output file */
    FILE *fout = fopen(argv[3], "w");

    /* TODO: check all the files have been opened successfully */
    if (fin1 == NULL || fin2 == NULL || fout == NULL)
    {
        printf("Error opening files\n");
        fclose(fin1);
        fclose(fin2);
        fclose(fout);
        return 1;
    }
    /* Read the first value from both input files */
    int val1, val2;
    int scan1 = fscanf(fin1, "%i", &val1);
    int scan2 = fscanf(fin2, "%i", &val2);
    while (1)
    {
        if (scan1 == EOF)
        {
            /* End of file 1 */
            /* TODO: write val2 to the output file */
            /* TODO: copy the rest of file 2 into the output file */
            fprintf(fout, "%i ", val2);
            scan2 = fscanf(fin2, "%i ", &val2);
            if (scan2 == EOF)
                break;
        }
        else if (scan2 == EOF)
        {
            /* End of file 2 */
            /* TODO: write val1 to the output file */
            /* TODO: copy the rest of file 1 into the output file */
            fprintf(fout, "%i ", val1);
            scan1 = fscanf(fin1, "%i", &val1);
            if (scan1 == EOF)
                break;
        }
        else
        {
            if (val1 < val2)
            {
                /* val1 is smaller */
                /* TODO: write val1 to the output file */
                /* TODO: read the next value from file 1 (setting scan1) */
                fprintf(fout, "%i ", val1);
                scan1 = fscanf(fin1, "%i", &val1);
            }
            else
            {
                /* val2 is smaller, or the two values are equal */
                /* TODO: write val2 to the output file */
                /* TODO: read the next value from file 2 (setting scan2) */
                fprintf(fout, "%i ", val2);
                scan2 = fscanf(fin2, "%i", &val2);
            }
        }
    }
    /* Close the files */
    fclose(fin1);
    fclose(fin2);
    fclose(fout);

    return 0;
}
