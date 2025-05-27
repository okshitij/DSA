#include<stdlib.h>
#include<stdio.h>

#define N 20

int stack[N];
int top = -1;

void push()
{
    char x;
    scanf("%c", &x);
    top++;
    stack[top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(' || x == ')')
        return 1;
    if(x == '[' || x == ']')
        return 1;
    if(x == '{' || x == '}')
        return 1;
    return 0;
}



int main()
{
    char paranthesis[N];


    return 0;
}