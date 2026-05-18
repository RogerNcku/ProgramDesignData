#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;
    int newWord = 1;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isspace(ch))
        {
            newWord = 1;
            putchar(ch);
        }
        else
        {
            if (newWord)
            {
                putchar(toupper(ch));
                newWord = 0;
            }
            else
            {
                putchar(ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
