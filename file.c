#include <stdio.h>
#include "file.h"

#define FILE_NAME "contacts.dat"

// Save the entire address book structure to a binary file
void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        printf("Error: Unable to open file for saving.\n");
        return ;
    }

    fwrite(addressBook, sizeof(AddressBook), 1, fp);
    fclose(fp);
    printf("Contacts saved successfully to '%s'.\n", FILE_NAME);
}

// Load the address book from a binary file if it exists
void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        // File does not exist or cannot be opened
        return;
    }

    fread(addressBook, sizeof(AddressBook), 1, fp);
    fclose(fp);
   
}
