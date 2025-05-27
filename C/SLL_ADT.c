#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;  // *next stores address of next node which is of datatype struct node
}*head = NULL;

void insert_front()
{
    if(head == NULL)
    {
        head = malloc(sizeof(struct node));  // head is a pointer to newly created node. it is not the new node here
        scanf("%d", &head -> data);
        head -> next = NULL;
    }
    else
    {
        struct node *new;
        new = malloc(sizeof(struct node)); 
        scanf("%d", &new -> data);
        new -> next = head; // head contains add. of initial front node mhanun connect karayla new chya next la head chi value assign keli
        head = new; // head ata new node la point karnar
    }
}

void insert_rear()
{
    if(head == NULL)
    {
        head = malloc(sizeof(struct node));
        scanf("%d", &head -> data);
        head -> next = NULL;
    }
    else
    {
        struct node *new, *temp;
        temp = head; // initially temp will be same as head
        while(temp -> next != NULL) // this loop is to traverse the list
            temp = temp -> next;
        new = malloc(sizeof(struct node));
        scanf("%d", &new -> data);
        temp -> next = new; //temp points to new node
        new -> next = NULL; // new node points to null
    }
}

void insert_specific()
{
    int index, i = 1; 
    scanf("%d", &index);
    struct node *temp, *n1;
    n1 = malloc(sizeof(struct node));
    temp = head; 
    while(i < index - 1)
    {
        temp = temp -> next;
        i++;
    }
    n1 -> next = temp -> next;
    temp -> next = n1;
    scanf("%d", &n1 -> data);
}

void delete_front()
{
    if(head ==  NULL)
        printf("empty ");
    else if(head -> next == NULL)
    {
        printf("%d ", head -> data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *new;
        new = head;
        head = new -> next;
        printf("%d ", new -> data);
        free(new);
    }
}

void delete_rear()
{
    if(head == NULL)
    {
        printf("empty ");
    }
    else if(head -> next == NULL)
    {
        printf("%d ", head -> data);
        free(head);
        head =  NULL;
    }
    else
    {
        struct node *temp, *prev;
        temp = head;
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

void delete_specific()
{
    int delete;
    scanf("%d", &delete);
    struct node *temp;
    temp = head;
    while(temp -> data != delete)
        temp = temp ->next;
    struct node *n1;
    n1 = temp -> next;
    printf("%d ", n1 -> data);
    temp -> next = n1 -> next;
    free(n1); 
}

void display()
{
    if(head == NULL)
        printf("empty ");
    else
    {
        struct node *temp;
        temp = head;
        while(temp -> next !=  NULL)
        {
        printf("%d ", temp -> data);
        temp = temp -> next;
        }
        printf("%d ", temp -> data);
    }
}

void search()
{
    int n = 0; // n is used as a flag here to check whether the element is found or not
    if(head == NULL)
        printf("empty ");
    else
    {
        int find, i = 1;
        scanf("%d", &find);
        struct node *temp;
        temp = head;
        while(temp != NULL)
        {
            if(temp -> data == find)
            {
                n++;
                printf("present at %d ", i);
                break;
            }
            temp = temp -> next;
            i++;
        }
        if(n == 0) // n=0 mhanje sapadla nahi
        printf("absent ");
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
            insert_specific(); break;
        case 4:
            delete_front(); break;
        case 5:
            delete_rear(); break;
        case 6:
            delete_specific(); break;
        case 7:
            display(); break;
        case 8:
            search(); break;
        case 9:
            exit(0);
        }
    }
    return 0;
}