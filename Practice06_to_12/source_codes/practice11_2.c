#include <stdio.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct time createTime(int hours, int minutes, int seconds)
{
    struct time t;

    t.hours = hours;
    t.minutes = minutes;
    t.seconds = seconds;

    return t;
}

void showInfo(struct time t)
{
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

void updateInfo(struct time *t, int hours, int minutes, int seconds)
{
    t->hours = hours;
    t->minutes = minutes;
    t->seconds = seconds;
}

int main(void)
{
    struct time t1;

    t1 = createTime(7, 5, 0);

    printf("Original time:\n");
    showInfo(t1);

    updateInfo(&t1, 20, 59, 0);

    printf("Updated time:\n");
    showInfo(t1);

    return 0;
}
