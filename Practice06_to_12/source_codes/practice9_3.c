#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s old_filename new_filename\n", argv[0]);
        return 1;
    }

    if (rename(argv[1], argv[2]) != 0)
    {
        printf("Rename failed.\n");
        return 1;
    }

    printf("Rename success.\n");

    return 0;
}
