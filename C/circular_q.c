#include<stdio.h>
#define N 10

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }

    else if(((rear+1) % N) == front)
    {
        printf("queue is full");
    }

    else
    {
        rear = (rear+1) % N;
        queue[rear] = x;
    }

}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("queue is empty");
    }

    else if(front == rear)
    {
        front = rear = -1;
    }

    else
    {
        printf("%d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("queue is empty");
    }

    else
    {
        while(i != rear)
        {
            printf("%d ", queue[i]);
            i = (i+1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("queue is empty");
    }

    else
    {
        printf("%d", queue[front]);
    }
}


void main()
{
    enqueue(2);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    enqueue(10);
    display();
}