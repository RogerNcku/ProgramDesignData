#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct time createTime(int h, int m, int s)
{
    struct time t;

    t.hours = h;
    t.minutes = m;
    t.seconds = s;

    return t;
}

void showInfo(struct time t)
{
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

struct time deltaTime(struct time t1, struct time t2)
{
    struct time result;
    int total1, total2, diff;

    total1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    total2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    diff = abs(total1 - total2);

    result.hours = diff / 3600;
    diff %= 3600;

    result.minutes = diff / 60;
    result.seconds = diff % 60;

    return result;
}

int main(void)
{
    struct time t1, t2, diff;

    t1 = createTime(20, 59, 0);
    t2 = createTime(7, 5, 0);

    printf("Time 1: ");
    showInfo(t1);

    printf("Time 2: ");
    showInfo(t2);

    diff = deltaTime(t1, t2);

    printf("Difference: ");
    showInfo(diff);

    return 0;
}
