#include<stdio.h>
#include<string.h>

char stack[20];
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

int main()
{
  char str[20];
  fgets(str, 20, stdin);
  char *x = str;
  
  while(*x != '\0')
  {
	  push(*x);
    x++;
  }
  
  int i = 0;
  while(top != -1)
  {
    str[i++] = pop();
  }
  
  puts(str);
  
  return 0;
  
}
