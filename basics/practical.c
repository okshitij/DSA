#include<stdio.h>

int covert();

struct time
{
    int hour;
    int minutes;
};

int main()
{
    convert();
}

int convert()
{
    struct time t1;
    printf("enter the starting time in hours and minutes:\n");
    scanf("%d %d", &t1.hour, &t1.minutes);

    if(t1.hour < 9 && t1.minutes < 60)
        printf("yes");

    else if(t1.hour == 9 && t1.minutes >= 0)
        printf("no");

    
}