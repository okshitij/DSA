#include<stdio.h> //infix to postfix part 2 :)
#include<ctype.h>

char stack[50];
int top = -1;

void push(char a);
char pop();
int prior(char a);

int main()
{
  char str[30], y;
  fgets(str, 30, stdin);
  char *x = str;
  
  while(*x != '\0')
  {
    if(isalnum(*x))
      printf("%c", *x);
    else if(*x == '(')
      push(*x);
    else if(*x == ')')
    {
      while((y = pop()) != '(')
        printf("%c", y);
    }
    
    else
    {
      while(top != -1 && prior(stack[top]) >= prior(*x))
        printf("%c", pop());
      push(*x);
    }
    x++;
  }
  while(top != -1)
  {
    printf("%c", pop());
  }
  return 0;
}

void push(char a)
{
  stack[++top] = a;
}

char pop()
{
  if(top == -1)
    return -1;
  else
    return stack[top--];
}

int prior(char a)
{
  if(a == '(')
    return 0;
  else if(a == '+' || a == '-')
    return 1;
  else if(a == '*' || a == '/')
    return 2;
  
  return 0;
}
