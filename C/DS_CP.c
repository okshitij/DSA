#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

// Structure for storing contact information
typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    struct Contact* next;
} Contact;

// Function to add a contact to the phone book
void addContact(Contact** phoneBook) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));

    printf("Enter name: ");
    fgets(newContact->name, MAX_NAME_LENGTH, stdin);
    newContact->name[strcspn(newContact->name, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(newContact->phone, MAX_PHONE_LENGTH, stdin);
    newContact->phone[strcspn(newContact->phone, "\n")] = '\0';

    newContact->next = *phoneBook;
    *phoneBook = newContact;

    // Append the new contact to the file
    FILE* file = fopen("contacts.txt", "a");
    if (file) {
        fprintf(file, "%s,%s\n", newContact->name, newContact->phone);
        fclose(file);
    }
}

// Function to delete a contact from the phone book
void deleteContact(Contact** phoneBook, const char* name) {
    Contact* current = *phoneBook;
    Contact* previous = NULL;

    while (current != NULL) {
        if (strcasecmp(current->name, name) == 0) {
            if (previous == NULL) {
                *phoneBook = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Contact deleted.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Contact not found.\n");
}

// Function to edit a contact in the phone book
void editContact(Contact* phoneBook, const char* name) {
    Contact* current = phoneBook;

    while (current != NULL) {
        if (strcasecmp(current->name, name) == 0) {
            printf("Enter new name: ");
            fgets(current->name, MAX_NAME_LENGTH, stdin);
            current->name[strcspn(current->name, "\n")] = '\0';

            printf("Enter new phone number: ");
            fgets(current->phone, MAX_PHONE_LENGTH, stdin);
            current->phone[strcspn(current->phone, "\n")] = '\0';

            printf("Contact updated.\n");
            return;
        }
        current = current->next;
    }

    printf("Contact not found.\n");
}

// Function to search for a contact in the phone book
void searchContact(Contact* phoneBook, const char* query) {
    printf("Search Results:\n");
    printf("---------------------\n");

    while (phoneBook != NULL) {
        if (strcasecmp(phoneBook->name, query) == 0 || strcasecmp(phoneBook->phone, query) == 0) {
            printf("Name: %s\n", phoneBook->name);
            printf("Phone: %s\n", phoneBook->phone);
            printf("---------------------\n");
        }
        phoneBook = phoneBook->next;
    }

    printf("End of search results.\n");
}

// Function to display all contacts in the phone book
void displayContacts(Contact* phoneBook) {
    if (phoneBook == NULL) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Contacts:\n");
    while (phoneBook != NULL) {
        printf("Name: %s\n", phoneBook->name);
        printf("Phone: %s\n", phoneBook->phone);
        printf("---------------------\n");
        phoneBook = phoneBook->next;
    }
}

// Function to load contacts from the file
void loadContacts(Contact** phoneBook) {
    FILE* file = fopen("contacts.txt", "r");
    if (file) {
        char line[MAX_NAME_LENGTH + MAX_PHONE_LENGTH + 2];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';
            char* token = strtok(line, ",");
            if (token != NULL) {
                Contact* newContact = (Contact*)malloc(sizeof(Contact));
                strncpy(newContact->name, token, MAX_NAME_LENGTH);
                token = strtok(NULL, ",");
                if (token != NULL) {
                    strncpy(newContact->phone, token, MAX_PHONE_LENGTH);
                    newContact->next = *phoneBook;
                    *phoneBook = newContact;
                }
            }
        }
        fclose(file);
    }
}

int main() {
    Contact* phoneBook = NULL;
    loadContacts(&phoneBook);

    int choice;
    char query[MAX_NAME_LENGTH];

    do {
        printf("Phone Book Directory\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                addContact(&phoneBook);
                break;
            case 2:
                printf("Enter name to delete: ");
                fgets(query, MAX_NAME_LENGTH, stdin);
                query[strcspn(query, "\n")] = '\0';
                deleteContact(&phoneBook, query);
                break;
            case 3:
                printf("Enter name to edit: ");
                fgets(query, MAX_NAME_LENGTH, stdin);
                query[strcspn(query, "\n")] = '\0';
                editContact(phoneBook, query);
                break;
            case 4:
                printf("Enter name or phone number to search: ");
                fgets(query, MAX_NAME_LENGTH, stdin);
                query[strcspn(query, "\n")] = '\0';
                searchContact(phoneBook, query);
                break;
            case 5:
                displayContacts(phoneBook);
                break;
            case 6:
                // Exiting the program
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 6);

    // Cleanup - free allocated memory
    while (phoneBook != NULL) {
        Contact* temp = phoneBook;
        phoneBook = phoneBook->next;
        free(temp);
    }

    return 0;
}