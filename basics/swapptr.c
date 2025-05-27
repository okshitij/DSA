#include <stdio.h>
void swap(int **a, int **b) 
{    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{   int a,b;
    printf("enter two numbers a and b:");
    scanf("%d%d",&a,&b);
    int *ptr1 = &a, *ptr2 = &b;
    printf("Before swapping: a = %d, a = %d\n", a, b);
    swap(&ptr1, &ptr2);
    printf("After swapping: a = %d, b = %d\n", *ptr1, *ptr2);
    return 0;
}
