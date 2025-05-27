#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PhoneBookEntry
{
    char name[50];
    char phone[15];
    struct PhoneBookEntry *prev;
    struct PhoneBookEntry *next;
} PhoneBookEntry;

PhoneBookEntry *head = NULL;
PhoneBookEntry *tail = NULL;

void addEntry();
void deleteEntry();
void searchEntry();
void printList();

int main()
{
    int choice;
    while(1)
    {
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addEntry(); break;
            case 2:
                deleteEntry(); break;
            case 3:
                searchEntry(); break;
            case 4:
                printList(); break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n"); break;

        }
    }

    return 0;
}

void addEntry()
{
    PhoneBookEntry *newEntry = (PhoneBookEntry*) malloc(sizeof(PhoneBookEntry));
    printf("\nEnter the name: ");
    scanf("%s", newEntry -> name);
    printf("Enter the phone number: ");
    scanf("%s", newEntry -> phone);
    newEntry -> prev = NULL;
    newEntry -> next = NULL;
    if(head == NULL)
    {
        head = newEntry;
        tail = newEntry;
    }
    else
    {
        tail -> next = newEntry;
        newEntry -> prev = tail;
        tail = newEntry;
    }

    printf("Entry added successfully\n");
}

void deleteEntry()
{
    char name[50];
    printf("\nEnter the name to be deleted: ");
    scanf("%s", name);
    PhoneBookEntry *current = head;
    while(current != NULL)
    {
        if(strcmp(current -> name, name) == 0)
        {
            if(current == head)
            {
                head = current -> next;
                if(head != NULL)
                {
                    head -> prev = NULL;
                }
            }
            else if(current == tail)
            {
                tail = current -> prev;
                tail -> next = NULL;
            }
            else
            {
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;

            }
            free(current);
            printf("Entry deleted successfully\n");
            return;
        }
        current = current -> next;
    }
    printf("Entry not found\n");
}


void searchEntry()
{
    char name[50];
    printf("\nEnter the name to be searched: ");
    scanf("%s", name);
    PhoneBookEntry *current = head;
    while(current != NULL)
    {
        if(strcmp(current -> name, name) == 0)
        {
            printf("Name: %s\n", current -> name);
            printf("Phone no: %s\n", current -> phone);
            return;
        }
        current = current -> next;
    }
    printf("Entry not found\n");
}

void printList()
{
    if(head == NULL)
    {
        printf("PhoneBook is empty\n");
        return;
    }
    // Count the number of entries in the phonebook
    int count = 0;
    PhoneBookEntry *current = head;
    while(current != NULL)
    {
        count++;
        current = current -> next;
    }
    // Store the names of all the entries in an array
    char names[count][50];
    int i = 0;
    current = head;
    while(current != NULL)
    {
        strcpy(names[i], current -> name);
        i++;
        current = current -> next;
    }
    // Sort the array of names in alphabetical order
    for(int i=0; i<count-1; i++)
    {
        for(int j=i+1; j<count; j++)
        {
            if(strcmp(names[i], names[j]) > 0)
            {
                char temp[50];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
    // Print the entries in alphabetical order
    printf("PhoneBook entries: \n");
    for(int i=0; i<count; i++)
    {
        current = head;
        while(current != NULL)
        {
            if(strcmp(current -> name, names[i]) == 0)
            {
                printf("Name: %s\n", current -> name);
                printf("Phone: %s\n", current -> phone);
                break;
            }
            current = current -> next;
        }
    }
}
