#include <stdio.h>
#include<string.h>
#include<ctype.h>

int stack[50];
int top = -1;

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
{
    if(x == '(' || x == ')')
        return 1;
    if(x == '+' || x == '-')
        return 2;
    if(x == '*' || x == '/')
        return 3;
    if(x == '^')
        return 4;
    return 0;
}

void str_rev(char infix[])
{
    int i, j;
    char temp;
    for(i = 0, j = strlen(infix)-1; i<j; i++, j--)
    {
        temp = infix[i];
        infix[i] = infix[j];
        infix[j] = temp;
    }
}

void in_pre(char infix[], char prefix[])
{
    int i, j=0;
    char x;
    str_rev(infix);
    for(i = 0; i < strlen(infix); i++)
    {
        x = infix[i];
        if(isalnum(x))
        {    prefix[j] = x;
            j++;
        }
        else
        {
            if(x == ')')
                push(x);
            else if(x == '(')
            {
                while(stack[top] != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
            }
            else
            {
                if(priority(stack[top]) <= priority(x))
                    push(x);
                else
                {
                    while(priority(stack[top]) > priority(x))
                    {
                        prefix[j] = pop();
                        j++;
                    }
                    push(x);
                }
            }
        }
    }
    while(top != -1)
    {
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
}

int main()
{
    char infix[50], prefix[50];
    printf("enter your infix exp:\n");
    scanf("%s", infix);
    in_pre(infix, prefix);
    str_rev(prefix);
    printf("%s", prefix);
    return 0;

}
