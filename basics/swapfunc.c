#include<stdio.h>

void swap();

void main()
{
    swap();
}

void swap()
{
    int a,b,c;
    printf("enter two num");
    scanf("%d %d", &a,&b);
    int temp = a;
    a = b;
    b = temp;
    printf("value of a is %d and value of b is %d", a,b);
}

