#include <stdio.h>
#include <string.h>

void create_txt_extension(char *file_name)
{
    int i;
    int has_extension = 0;

    for (i = 0; file_name[i] != '\0'; i++)
    {
        if (file_name[i] == '.')
        {
            has_extension = 1;
            break;
        }
    }

    if (!has_extension)
    {
        strcat(file_name, ".txt");
    }
}

int main(void)
{
    char file1[50] = "output";
    char file2[50] = "result.txt";

    create_txt_extension(file1);
    create_txt_extension(file2);

    printf("file1 = %s\n", file1);
    printf("file2 = %s\n", file2);

    return 0;
}
