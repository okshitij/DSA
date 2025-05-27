#include<stdio.h>
int main()
{
    int x;
    printf("enter the number\n");
    scanf("%d", &x);
    int r = factorial(x);
    printf("%d", r);
    return 0;
}

int factorial(int x)
{
    int fact = 1;
    for(int i = 1; i <= x; i++)
        fact = fact*i;

    return fact;
}