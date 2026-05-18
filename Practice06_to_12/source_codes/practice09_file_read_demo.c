#include <stdio.h>

int main(void)
{
    FILE *fp;
    char fileName[] = "my_file.txt";
    char content[] = "Once upon the time, there was a big gray wolf.";
    char line[200];

    fp = fopen(fileName, "w");

    if (fp == NULL)
    {
        printf("Cannot create file.\n");
        return 1;
    }

    fprintf(fp, "%s\n", content);

    fclose(fp);

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("File name: %s\n", fileName);
    printf("File content:\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}
