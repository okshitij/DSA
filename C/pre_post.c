#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[50];
int top = -1;

int main()
{
    char exp[50];
    printf("enter the prefix expression:\n");
    fgets(exp, 50, stdin);

}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
[
    if(a =='')
        return 0;
    if(a == '')
        return 1;
    
]