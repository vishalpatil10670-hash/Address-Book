#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < addressBook->contactCount; i++) {
        Contact *c = &addressBook->contacts[i];
        printf("%d. %s | %s | %s\n", i + 1, c->name, c->phone, c->email);
    }

    // TODO: Add sorting based on sortCriteria (e.g., by name, phone, etc.)
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);  // Optional: preload dummy data
     // Load from file if exists
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
    if (addressBook->contactCount >= MAX_CONTACTS) {
        printf("Address Book is full!\n");
        return;
    }

    Contact *c = &addressBook->contacts[addressBook->contactCount];

    printf("Enter name: ");
    fgets(c->name, sizeof(c->name), stdin);
    c->name[strcspn(c->name, "\n")] = 0;

    printf("Enter phone: ");
    fgets(c->phone, sizeof(c->phone), stdin);
    c->phone[strcspn(c->phone, "\n")] = 0;

    printf("Enter email: ");
    fgets(c->email, sizeof(c->email), stdin);
    c->email[strcspn(c->email, "\n")] = 0;

    addressBook->contactCount++;
    printf("Contact created successfully.\n");
}

void searchContact(AddressBook *addressBook) 
{
    char name[50];
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, name) == 0) {
            Contact *c = &addressBook->contacts[i];
            printf("Found: %s | %s | %s\n", c->name, c->phone, c->email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void editContact(AddressBook *addressBook)
{
    char name[50];
    printf("Enter name of contact to edit: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, name) == 0) {
            Contact *c = &addressBook->contacts[i];

            printf("Editing %s\n", c->name);
            printf("New phone: ");
            fgets(c->phone, sizeof(c->phone), stdin);
            c->phone[strcspn(c->phone, "\n")] = 0;

            printf("New email: ");
            fgets(c->email, sizeof(c->email), stdin);
            c->email[strcspn(c->email, "\n")] = 0;

            printf("Contact updated successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void deleteContact(AddressBook *addressBook)
{
    char name[50];
    printf("Enter name to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, name) == 0) {
            for (int j = i; j < addressBook->contactCount - 1; j++) {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->contactCount--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}
