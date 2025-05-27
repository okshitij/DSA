#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 20

int stack[N];
int top = -1;

void push();
void pop();
void peek();
void isempty();
void isfull();

int main()
{
  int choice;
  while(1)
  {
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: push();  break;
      case 2: pop(); break;
      case 3: peek(); break;
      case 5: isempty(); break;
      case 4: isfull(); break;
      case 6: exit(0);
    }
  }
  
  return 0;
}

void push()
{
  int x;
  scanf("%d", &x);
  top += 1;
  stack[top] = x;
}

void pop()
{
  int x = stack[top];
  printf("%d ",stack[top]);
  top -= 1;
}

void peek()
{
  printf("%d ",stack[top]);
}

void isempty()
{
  if(top == -1)
    printf("true ");
  else
    printf("false ");
}

void isfull()
{
  if(top == N-1)
    printf("true ");
  else
    printf("false ");
}
