#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front = 0;

void push()
{
    if(front == 0)
    {
        front = malloc(sizeof(struct node));
        scanf("%d", &front -> data);
        front -> next = NULL;
    }
    else
    {
        struct node *new, *temp = front;
        while(temp -> next != NULL)
            temp = temp -> next;
        new = malloc(sizeof(struct node));
        scanf("%d", &new -> data);
        temp -> next = new;
        new -> next = NULL;
    }
}

void pop()
{
    if(front == 0)
        printf("empty ");
    else if(front -> next == NULL)
    {
        printf("%d ", front -> data);
        free(front);
        front =  0;
    }
    else
    {
        struct node *temp, *prev;
        temp = front;
        while(temp -> next != NULL)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        printf("%d ", temp -> data);
        free(temp);
    }
}

void isempty()
{
    if(front == 0)
        printf("empty ");
    else
        printf("not empty ");
}

void display()
{
    if(front == 0)
        printf("empty ");
    else
    {
        struct node *temp;
        temp = front;
        while(temp -> next !=  NULL)
        {
        printf("%d ", temp -> data);
        temp = temp -> next;
        }
        printf("%d ", temp -> data);
    }
}

void peek()
{
    struct node *temp = front;
    while(temp -> next != NULL)
        temp = temp -> next;
    printf("%d ", temp -> data);
}

int main()
{
    int choice;
    while(1)
    {
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: isempty(); break;
            case 4: display(); break;
            case 5: peek(); break;
            case 6: exit(0);
        }
    }
    return 0;
}