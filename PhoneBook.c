#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

int i;

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact(char *name, char *phone) {
    if (numContacts < MAX_CONTACTS) {
        strcpy(contacts[numContacts].name, name);
        strcpy(contacts[numContacts].phone, phone);
        numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Cannot add more contacts. Phonebook is full.\n");
    }
}

void searchContact(char *name) {
    int found = 0;
    for ( i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void updateContact(char *name, char *newPhone) {
    int found = 0;
    for ( i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            strcpy(contacts[i].phone, newPhone);
            printf("Contact updated successfully!\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact(char *name) {
	int j;
    int found = 0;
    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (j = i; j < numContacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].phone, contacts[j + 1].phone);
            }
            numContacts--;
            printf("Contact deleted successfully!\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(name, phone);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;
            case 3:
                printf("Enter name to update: ");
                scanf("%s", name);
                printf("Enter new phone: ");
                scanf("%s", phone);
                updateContact(name, phone);
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(name);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
