#include <stdio.h>

struct timeStruct
{
    int hours;
    int minutes;
    int seconds;
};

int main(void)
{
    struct timeStruct time1 = {7, 5, 0};
    struct timeStruct time2 = {20, 59, 0};

    printf("Before copy:\n");
    printf("time1 = %02d:%02d:%02d\n", time1.hours, time1.minutes, time1.seconds);
    printf("time2 = %02d:%02d:%02d\n", time2.hours, time2.minutes, time2.seconds);

    time1 = time2;

    printf("\nAfter copy:\n");
    printf("time1 = %02d:%02d:%02d\n", time1.hours, time1.minutes, time1.seconds);
    printf("time2 = %02d:%02d:%02d\n", time2.hours, time2.minutes, time2.seconds);

    return 0;
}
