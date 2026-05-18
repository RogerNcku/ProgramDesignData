#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    long size;
    char *buffer;
    int i;

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

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    buffer = (char *)malloc(size + 1);

    if (buffer == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    fread(buffer, sizeof(char), size, fp);
    buffer[size] = '\0';

    fclose(fp);

    fp = fopen(argv[1], "w");

    if (fp == NULL)
    {
        printf("Cannot write file.\n");
        free(buffer);
        return 1;
    }

    for (i = 0; i < 3; i++)
    {
        fputs(buffer, fp);
    }

    fclose(fp);
    free(buffer);

    return 0;
}
