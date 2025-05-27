#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
}*head = NULL;

void insert_front()
{
  if(head == NULL)
  {
    head = malloc(sizeof(struct node));
    scanf("%d", &head -> data);
    head -> next = head;
    head -> prev = head;
  }
  else
  {
  	struct node *n1;
    n1 = malloc(sizeof(struct node));
    scanf("%d", &n1 -> data);
    n1 -> next = head;
    n1 -> prev = head -> prev;
    head -> prev -> next = n1; // n1 la head banavtoy hya 3 lines madhe
    head -> prev = n1;
    head = n1;
  }
}

void insert_rear()
{
  if(head == NULL)
  {
    head = malloc(sizeof(struct node));
    scanf("%d", &head -> data);
    head -> prev = head;
    head -> next = head;
  }
  else
  {
    struct node *n1, *temp = head;
    while(temp -> next != head)
      temp = temp -> next;
    n1 = malloc(sizeof(struct node));
    scanf("%d", &n1 -> data);
    n1 -> next = head; // last ani first node la link kela
    n1 -> prev = temp; // last node chya adhi cha node connect kela
    head -> prev = n1; // first ani last node link kela
    temp -> next = n1; // temp update kela
  }
}

void insert_specific()
{
  int index, new;
  scanf("%d", &index);
  scanf("%d", &new);
  struct node *temp = head, *n1;
  n1 = malloc(sizeof(struct node));
  n1 -> data = new;
  while(temp -> data != index)
  {
    temp = temp -> next;
  }
  n1 -> next = temp -> next;
  n1 -> prev = temp;
  if(temp -> next != head)   //imp
    temp -> next -> prev = n1; 
  temp -> next = n1;
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
    struct node *n1 = head;
    head = n1 -> next;
    head -> prev = n1 -> prev;
    head -> prev -> next = head;
    printf("%d ", n1 -> data);
    free(n1);
  }
}

void delete_rear()
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
    struct node *temp = head, *prev;
    while(temp -> next != head)
    {
      prev = temp;
      temp = temp -> next;
    }
    prev -> next = head;
    head -> prev = prev;
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
  printf("%d ", n1 -> data);
  temp -> next = n1 -> next;
  if(n1 -> next != head)
    n1-> next -> prev = temp;
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