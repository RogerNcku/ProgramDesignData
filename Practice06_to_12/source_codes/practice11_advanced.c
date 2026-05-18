#include <stdio.h>
#include <stdlib.h>

struct student
{
    char firstName[20];
    char lastName[20];
    int mathGrade;
    int csGrade;
    int englishGrade;
};

int main(void)
{
    int n = 3;
    int i;

    struct student *s;

    s = (struct student *)calloc(n, sizeof(struct student));

    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    sprintf(s[0].firstName, "Tim");
    sprintf(s[0].lastName, "Robert");
    s[0].mathGrade = 60;
    s[0].csGrade = 45;
    s[0].englishGrade = 82;

    sprintf(s[1].firstName, "Mary");
    sprintf(s[1].lastName, "Hunter");
    s[1].mathGrade = 61;
    s[1].csGrade = 82;
    s[1].englishGrade = 50;

    sprintf(s[2].firstName, "John");
    sprintf(s[2].lastName, "Michael");
    s[2].mathGrade = 70;
    s[2].csGrade = 58;
    s[2].englishGrade = 85;

    for (i = 0; i < n; i++)
    {
        printf("%s %s\n", s[i].firstName, s[i].lastName);
        printf("Math: %d\n", s[i].mathGrade);
        printf("CS: %d\n", s[i].csGrade);
        printf("English: %d\n\n", s[i].englishGrade);
    }

    free(s);

    return 0;
}
