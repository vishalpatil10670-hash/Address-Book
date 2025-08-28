#include "contact.h"

// Dummy contact data (address removed)
static Contact dummyContacts[] = {
    {"", "1234567890", "anii@example.com"},
    {"Omkar", "0987654321", "omkar@example.com"},
    {"Aftaf", "1112223333", "aftaf@company.com"},
    {"Swapanil", "4445556666", "swapna@company.com"},
    {"Abhijeet", "7778889999", "abz@example.com"},
    {"Vaibhav", "6665554444", "vaibhav@example.com"},
    {"Rohit", "3334445555", "rp@example.com"},
    {"Abhishak", "2223334444", "abhi@example.com"},
    {"Pratik", "5556667777", "pratik@example.com"},
    {"Mohit", "8889990000", "mohit@example.com"}
};

void populateAddressBook(AddressBook* addressBook)
{
    int numDummyContacts = sizeof(dummyContacts) / sizeof(dummyContacts[0]);
    for (int i = 0; i < numDummyContacts && addressBook->contactCount < MAX_CONTACTS; ++i) {
        addressBook->contacts[addressBook->contactCount++] = dummyContacts[i];
    }
}
