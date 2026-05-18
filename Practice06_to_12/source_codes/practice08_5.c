#include <stdio.h>

int main(void)
{
    char s[] = "Hsjodi";
    char *p;

    for (p = s; *p != '\0'; p++)
    {
        --*p;
    }

    puts(s);

    return 0;
}
