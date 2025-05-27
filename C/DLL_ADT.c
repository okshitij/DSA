#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
} *head = NULL;

void insert_front()
{
  if(head == NULL)
  {
    head = malloc(sizeof(struct node));
    scanf("%d", &head -> data);
    head -> next = NULL;
    head -> prev = NULL;
  }
  else
  {
    struct node *n1;
    n1 = malloc(sizeof(struct node));
    scanf("%d", &n1 -> data);
    n1 -> next = head; // new node initial head la point karel
    n1 -> prev = NULL; // ha new node head honar mhanun tyacha prev null la point karel
    head -> prev = n1; // initial head new node la point karel
    head = n1; // new la head banavla 
  }
}

void insert_rear()
{
  if(head == NULL)
  {
    head = malloc(sizeof(struct node));
    scanf("%d", &head -> data);
    head -> next = NULL;
    head -> prev = NULL;
  }
  else
  {
    struct node *n1, *temp;
    temp = head;
    while(temp -> next != NULL)
      temp = temp -> next;
    n1 = malloc(sizeof(struct node));
    scanf("%d", &n1 -> data);
    n1 -> next = NULL;
    n1 -> prev = temp;
    temp -> next = n1;
  }
}

void insert_specific()
{
  int index, i = 1;
  scanf("%d", &index);
  struct node *temp, *n1;
  n1 = malloc(sizeof(struct node));
  scanf("%d", &n1 -> data);
  temp = head;
  while(temp -> data != index)
  {
    temp = temp -> next;
    i++;
  }
  n1 -> next = temp -> next;
  n1 -> prev = temp;
  if(temp -> next != NULL)        //imp
    temp -> next -> prev = n1;
  temp -> next = n1;
}

void delete_front()
{
  if(head == NULL)
    printf("empty ");
  else if(head -> next == NULL)
  {
    printf("%d ", head -> data);
    free(head);
    head = NULL;
  }
  else
  {
    struct node *n1;
    n1 = head;
    head = n1 -> next;
    head -> prev = NULL;
    printf("%d ", n1 -> data);
    free(n1);
  }
}

void delete_rear()
{
  if(head == NULL)
    printf("empty ");
  else if(head -> next == NULL)
  {
    printf("%d ", head -> data);
    free(head);
    head = NULL;
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
    temp = temp -> next;
  struct node *n1;
  n1 = temp -> next;
  temp -> next = n1 -> next;
  printf("%d ", n1 -> data);
  if(n1 -> next != NULL)          //imp
    n1 -> next -> prev = temp;
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
    while(temp -> next != NULL)
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
    struct node *temp;
    temp = head;
    while(temp -> next != NULL)
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