#include<stdio.h>
int stack[100],top=-1;

void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    return stack[top--];
}

void main()
{
    int num,rem;
    printf("Enter decimal no.:");
    scanf("%d",&num);
    while(num!=0)
    {
        rem=(num%2);
        push(rem);
        num=num/2;
    }
    printf("Binary equivalent:");
    while(top!=-1)
    {
        printf("%d",pop());
    }
}