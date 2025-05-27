#include<stdio.h>
int add(int a,int b)
{    return a+b;    }
int subtract(int a,int b)
{    return a-b;    }
int multiply(int a,int b)
{    return a*b;    }
int divide(int a,int b)
{    return a/b;    }

int main()
{
    int a,b;
    printf("enter the value of a\n");
    scanf("%d",&a);
    printf("enter the value of b\n");
    scanf("%d",&b);

    int (*add_ptr)(int,int) = &add;
    int (*subtract_ptr)(int,int) = &subtract;
    int (*multiply_ptr)(int,int) = &multiply;
    int (*divide_ptr)(int,int) = &divide;

    printf("addition: %d\n",(*add_ptr)(a,b));
    printf("subtraction: %d\n",(*subtract_ptr)(a,b));
    printf("multiplication: %d\n",(*multiply_ptr)(a,b));
    printf("division: %d\n",(*divide_ptr)(a,b));
}