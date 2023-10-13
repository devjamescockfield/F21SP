#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *sfind(const char *s, int c)
{
    /* TODO: implement this function */
    int i = 0;
    for (i = 0;; i++)
    {
        if (s[i] == c)
        {
            return &s[i];
        }
        if (s[i] == '\0')
            break;
    }
    return NULL;
}

/* Test whether sfind works correctly.
 * Search for c in the string s, and check that the result is a pointer to
 * position pos in the string (or NULL, if pos is -1). */
void test_sfind(const char *s, int c, int pos)
{
    printf("Finding '%c' (character %d) in '%s'... ", c, c, s);

    const char *result = sfind(s, c);
    const char *expected = NULL;
    if (pos != -1)
    {
        expected = s + pos;
    }
    if (result == expected)
    {
        printf("OK\n");
    }
    else
    {
        printf("failed (expected offset %d)\n", pos);
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    // Some "normal" tests for sfind
    test_sfind("", 'x', -1);
    test_sfind("x", 'x', 0);
    test_sfind("xx", 'x', 0);
    test_sfind("x", 'y', -1);
    test_sfind("xy", 'y', 1);
    test_sfind("xxxxyxxxx", 'y', 4);
    test_sfind("xxxxyxxxxy", 'y', 4);
    test_sfind("yxxxyxxxx", 'y', 0);

    // It should be case-sensitive
    test_sfind("Heriot-Watt", 'w', -1);
    test_sfind("Heriot-Watt", 'W', 7);

    // Searching for \0 should match the \0 at the end of the string
    test_sfind("blah", '\0', 4);

    printf("All OK!\n");
    return 0;
}
