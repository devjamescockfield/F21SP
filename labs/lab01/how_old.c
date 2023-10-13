#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int birth_year;
    int had_birthday;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int current_year = tm.tm_year + 1900;

    /* TODO: ask what year the user was born in */
    printf("What year where you born? ");
    scanf("%i", &birth_year);
    /* TODO: ask whether the user has had their birthday yet this year */
    printf("Have you had your birthday yet this year? (1 for yes, 0 for no) ");
    scanf("%i", &had_birthday);
    /* TODO: compute and display the user's age */
    if (had_birthday == 1) {
        printf("You are %i years old.\n", current_year - birth_year);
    } else {
        if (current_year - birth_year >= 0)
            printf("You are %i years old.\n", current_year - birth_year - 1);
        else
            printf("You are not born yet.\n");
    }

    return 0;
}
