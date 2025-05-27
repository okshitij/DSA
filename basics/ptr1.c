#include<stdio.h> //example of call by reference

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b;

    printf("enter two numbers:\n");
    scanf("%d %d", &a, &b);

    swap(&a, &b); //passing address of a and b to swap function
    printf("a = %d and b = %d", a, b);

    return 0;
}