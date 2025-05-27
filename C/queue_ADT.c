#include<stdio.h>
#include<stdlib.h>
#define N 4

int queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
  int x;
  if(front==-1&&rear==-1)
  {
    scanf("%d",&x);
    front=0;
    rear++;
    queue[rear] = x;
  }
   else if(rear==N-1)
  {
    printf("full ");
  }
   else
  {
    rear++;
    scanf("%d",&x);
    queue[rear] = x;
  }
       
}

void dequeue()
{
  if(front == -1 && rear == -1)
    printf("empty ");
  else if(front == rear)
  {
   	printf("%d ",queue[front]);
    front = rear = -1;
  }
  else
  {
    printf("%d ",queue[front]);
    front++;
  }
}


void display()
{
  int i = front;
  if(front == -1 && rear == -1)
    printf("empty ");
  else
  {
    while(i != rear)
    {
      printf("%d ", queue[i]);
      i++;
    }
    printf("%d ", queue[rear]);
  }
}

void isfull()
{
  if(rear == N-1)
    printf("full ");
}

void isempty()
{
  if(front == -1 && rear == -1)
    printf("empty ");
}

int main()
{
  int choice;
  
  while(1)
  {
  scanf("%d ",&choice);
  switch(choice)
  {
    case 1:
      enqueue(); break;
    case 2:
      dequeue(); break;
    case 3:
      display(); break;
    case 4:
      isfull(); break;
    case 5:
      isempty(); break;
    case 6:
      exit(0);
  }
  }
  return 0;
}