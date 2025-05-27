#include<stdio.h> // doubly ended queue ADT
#include<stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void insert_front()
{
  int x;
  if((front == 0 && rear == N-1) || front == rear+1)
    printf("full ");
  else
  {
    scanf("%d", &x);
    if(front == -1)
      front = rear = 0;
  	else if(front == 0)
      front = N-1;
  	else
      front--;
  	queue[front] = x;
  }
}

void insert_rear()
{
  int x;
  if((front == 0 && rear == N-1) || front ==rear+1)
    printf("full ");
  else
  {
    scanf("%d", &x);
    if(front == -1)
      front = rear = 0;
  	else if(rear ==N-1)
      rear = 0;
  	else
      rear++;
  	queue[rear] = x;
  }
}

void delete_front()
{
  if(front == -1)
    printf("empty ");
  else
  {
    printf("%d ", queue[front]);
    if(front == rear)
      front = rear = -1;
  	else if(front == N-1)
      front = 0;
  	else
      front = (front + 1) % N; 
  }
}

void delete_rear()
{
  if(front == -1)
    printf("empty ");
  else
  {
    printf("%d ", queue[rear]);
    if(front == rear)
      front = rear = -1;
  	else if(rear == 0)
      rear = N-1;
  	else
      rear = (rear - 1 + N) % N;
  }
}

void display()
{
  if(front == -1)
    printf("empty ");
  else if(front <= rear)
  {
    for(int i = front; i <= rear; i++)
      printf("%d ", queue[i]);
  }
  else
  {
    for(int i = front; i<N; i++)
      printf("%d ", queue[i]);
    for(int i = 0; i<=rear; i++)
      printf("%d ", queue[i]);
  }
}

int main()
{
  int choice;
  while(1)
  {
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
        insert_front(); break;
      case 2:
        insert_rear(); break;
      case 3:
        delete_front(); break;
      case 4:
        delete_rear(); break;
      case 5:
        display(); break;
      case 6:
        exit(0);
    }
  }
  return 0;
}