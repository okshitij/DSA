#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front = 0, *rear = 0;

void enqueue()
{
    if(front == 0 && rear == 0)
    {
        front = malloc(sizeof(struct node));
        scanf("%d", &front -> data);
        front -> next = NULL;
        rear = front;
    }
    else
    {
        struct node *new;
        new = malloc(sizeof(struct node));
        scanf("%d", &new -> data);
        new -> next = NULL;
        rear -> next = new;
        rear = new;
    }
}

void dequeue()
{
    if(front == 0 && rear == 0)
        printf("empty ");
    else
    {
        struct node *temp = front;
        printf("%d ", front -> data);
        front = front -> next;
        free(temp);
    }
}

void display()
{
    if(front == 0 && rear == 0)
        printf("empty ");
    else
    {
        struct node *temp = front;
        while(temp != NULL)
        {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
}

void isempty()
{
    if(front == 0 && rear == 0)
        printf("empty ");
    else
        printf("not empty ");
}

void peek()
{
    if(front == 0 && rear == 0)
        printf("empty ");
    else
        printf("%d ", front -> data);
}

int main()
{
    int choice;
    while(1)
    {
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: isempty(); break;
            case 5: peek(); break;
            case 6: exit(0);
        }
    }
    return 0;
}