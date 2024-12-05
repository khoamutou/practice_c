#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int first_number, int second_number);
int sub(int first_number, int second_number);
int mul(int first_number, int second_number);
int did(int first_number, int second_number);

int main(int argc, char *argv[])
{
    int (*cal)(int, int);
    int number0, number1;
    char *endptr;

    // printf("%d\n", argc);
    // for (int i = 0; i < argc; i++)
    // {
    //     printf("%s\n", argv[i]);
    // }

    if (argc != 7)
    {
        printf("Invalid argument is not enough!!!\n");
        return 0;
    }

    if ((strcmp(argv[1], argv[3]) == 0) && (strcmp(argv[3], argv[5]) == 0))
    {
        printf("Three arguments are the same!!!\n");
        return 0;
    }

    if ((strcmp(argv[1], argv[3]) == 0) || (strcmp(argv[1], argv[5]) == 0) || (strcmp(argv[3], argv[5]) == 0))
    {
        printf("There are at least two arguments are the same!!!\n");
        return 0;
    }

    for (int i = 1; i <= 5; i= i + 2)
    {
        if (strcmp(argv[i], "-n0") == 0)
        {
            number0 = strtol(argv[i + 1], &endptr, 10);

            if (endptr == argv[i + 1])
            {
                printf("No digit found for first number\n");
                return 0;
            }
            else if (*endptr != '\0')
            {
                printf("Invalid character for first number: %c\n", *endptr);
                return 0;
            }
        }
        else if (strcmp(argv[i], "-n1") == 0)
        {
            number1 = strtol(argv[i + 1], &endptr, 10);

            if (endptr == argv[i + 1])
            {
                printf("No digit found for second number\n");
                return 0;
            }
            else if (*endptr != '\0')
            {
                printf("Invalid character for second number: %c\n", *endptr);
                return 0;
            }
        }
        else if (strcmp(argv[i], "-o") == 0)
        {
            if ((strcmp(argv[i + 1], "add") == 0) || (strcmp(argv[i + 1], "+") == 0))
            {
                cal = &add;
            }

            else if ((strcmp(argv[i + 1], "sub") == 0) || (strcmp(argv[i + 1], "-") == 0))
            {
                cal = &sub;
            }

            else if ((strcmp(argv[i + 1], "mul") == 0) || (strcmp(argv[i + 1], "*") == 0))
            {
                cal = &mul;
            }

            else if ((strcmp(argv[i + 1], "did") == 0) || (strcmp(argv[i + 1], "/") == 0))
            {
                cal = &did;
            }

            else
            {
                printf("Invalid calculation!!!\n");
                return 0;
            }
        }

        else
        {
            printf("Invalid argument!!!\n");
            return 0;
        }
    }

    printf("%d\n", (*cal) (number0, number1));

    return 0;
}

int add(int first_number, int second_number)
{
    return first_number + second_number;
}

int sub(int first_number, int second_number)
{
    return first_number - second_number;
}

int mul(int first_number, int second_number)
{
    return first_number * second_number;
}

int did(int first_number, int second_number)
{
    return first_number / second_number;
}

