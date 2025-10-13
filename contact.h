#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct
{
    char name[50];
    char phone[11];
    char email[50];
} Contact;

typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook, int searchCriteria, int out_key, int found_arr[], int *found_count);
void editContact(AddressBook *addressBook, int searchChoice);
void deleteContact(AddressBook *addressBook, int searchCriteria);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

// Validation Functions
int val_name(char temp_name[]);
int val_phone(char temp_phone[], AddressBook *addressBook, int val_1, int val_2, int val_3);
int val_email(char temp_email[], int val_1, int val_2);

#endif
