#include<stdio.h>

void main()
{
    int m = 30;
    float fx = 30.6;
    char cht = 'z';
    
    int *ptr1;
    float *ptr2;
    char *ptr3;

    ptr1 = &m; //stores the address of m in pointer 1
    ptr2 = &fx;
    ptr3 = &cht;

    printf("m = %d\n", m);
    printf("fx = %f\n", fx);
    printf("cht = %c\n", cht);
    
}