#include<stdio.h> // CIRCULAR SLL
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*head = NULL;

void insert_front()
{
  if(head == NULL)
  {
    head = malloc(sizeof(struct node));
    scanf("%d", &head -> data);
    head -> next = head; // head should point to itself as it is the first node
  }
  else
  {
    struct node *new, *temp = head;
    new = malloc(sizeof(struct node));
    scanf("%d", &new -> data);
    new -> next = head; // connects two nodes here (new and the head node)
    while(temp -> next != head)
      temp = temp -> next;
    temp -> next = new; // last node new node la point karel
    head = new; // head node will be new node
  }
}

void insert_rear()
{
  if(head == NULL)
  {
    head = malloc(sizeof(struct node));
    scanf("%d", &head -> data);
    head -> next = head;
  }
  else
  {
    struct node *new, *temp = head;
    new = malloc(sizeof(struct node));
    scanf("%d", &new -> data);
    while(temp -> next != head)
      temp = temp -> next;
    temp -> next = new;
    new -> next = head; // new node joh last node zhalay toh head la point karel
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
  if(head == NULL)
    printf("empty ");
  else if(head -> next == head)
  {
    printf("%d ", head -> data);
    free(head);
    head = NULL;
  }
  else
  {
    struct node *new, *temp = head;
    new = head;
    head = new -> next;
    while(temp -> next != new)
      temp = temp -> next;
    temp -> next = head;
    printf("%d ", new -> data);
    free(new);
  }
}

void delete_rear()
{
  if(head == NULL)
    printf("empty ");
  else if(head -> next == head)
  {
    printf("%d", head -> data);
    free(head);
    head = NULL;
  }
  else
  {
    struct node *temp = head, *prev;
    while(temp -> next != head)
    {
      prev = temp;
      temp = temp -> next;
    }
    prev -> next = head;
    printf("%d ", temp -> data);
    free(temp);
  }
}

void delete_specific()
{
  int delete;
  scanf("%d", &delete);
  struct node *temp = head;
  while(temp -> data != delete)
    temp = temp -> next;
  struct node *n1;
  n1 = temp -> next;
  temp -> next = n1 -> next;
  printf("%d ", n1 -> data);
  free(n1);
}

void display()
{
  if(head == NULL)
    printf("empty ");
  else
  {
    struct node *temp = head;
    while(temp -> next != head)
    {
      printf("%d ", temp -> data);
      temp = temp -> next;
    }
    printf("%d ", temp -> data);
  }
}

void search()
{
  int n = 0;
  if(head == NULL)
    printf("empty ");
  else
  {
    int find, i = 1;
    scanf("%d", &find);
    struct node *temp = head;
    while(temp -> next != head)
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
    if(n == 0)
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