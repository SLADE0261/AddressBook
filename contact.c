#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

#include <ctype.h>

// Validation Functions -------------------------------------------------------------------------------------(||||||||||||)
int val_name(char temp_name[])
{
    int name_flag_1 = 0;
    int i = 0;

    // Validation - Name - check if alphabet or space
    while (temp_name[i] != '\0')
    {
        if (isalpha(temp_name[i]) || isspace(temp_name[i]))
        {
            name_flag_1 = 1;
        }
        else
        {
            name_flag_1 = 0;
            break;
        }
        i++;
    }

    if (name_flag_1 == 0)
    {
        printf("\nERROR! Plese re-enter the Name.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int val_phone(char temp_phone[], AddressBook *addressBook, int val_1, int val_2, int val_3)
{
    int phone_flag_1 = 0;
    int phone_flag_2 = 0;
    int phone_flag_3 = 0;

    if (val_1 == 0)
        phone_flag_1 = 1;
    if (val_2 == 0)
        phone_flag_2 = 1;
    if (val_3 == 0)
        phone_flag_3 = 1;

    // Validation - Phone
    // Validation - Phone - check if numbers
    if (val_1 == 1)
    {
        int i = 0;
        while (temp_phone[i] != '\0')
        {
            if ('0' <= temp_phone[i] && temp_phone[i] <= '9')
            {
                phone_flag_1 = 1;
            }
            else
            {
                phone_flag_1 = 0;
                break;
            }
            i++;
        }
    }

    // Validation - Phone - check if length is 10
    if (val_2 == 1)
    {
        if (strlen(temp_phone) == 10)
        {
            phone_flag_2 = 1;
        }
    }

    // Validation - Phone - check if unique
    if (val_2 == 1)
    {
        int i = 0;
        for (i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(temp_phone, addressBook->contacts[i].phone) == 0)
            {
                phone_flag_3 = 0;
                break;
            }
            else
            {
                phone_flag_3 = 1;
            }
        }
    }

    if (phone_flag_1 == 0)
    {
        printf("\nERROR! Input is not a number.\n");
        printf("Please re-enter the Phone.\n");
        return 0;
    }
    else if (phone_flag_2 == 0)
    {
        printf("\nERROR! Input is not 10 digits long.\n");
        printf("Please re-enter the Phone.\n");
        return 0;
    }
    else if (phone_flag_3 == 0)
    {
        printf("\nERROR! Input is not unique.\n");
        printf("Please re-enter the Phone.\n");
        return 0;
    }
    // else if (phone_flag_1 == 0 || phone_flag_2 == 0 || phone_flag_3 == 0)
    // {
    //     printf("ERROR! Please re-enter the Phone.\n");
    //     return 0;
    // }
    else
    {
        return 1;
    }
}

int val_email(char temp_email[], int val_1, int val_2)
{
    int email_flag_1 = 0;
    int email_flag_2 = 0;

    if (val_1 == 0)
        email_flag_1 = 1;
    if (val_2 == 0)
        email_flag_2 = 1;

    // Validation - Name
    // Validation - Name - alphabets and special characer
    if (val_1 == 1)
    {
        int i = 0;
        while (temp_email[i] != '\0')
        {
            if ((20 <= temp_email[i] && temp_email[i] <= 'Z') || ('a' <= temp_email[i] && temp_email[i] <= 'z'))
                email_flag_1 = 1;
            i++;
        }
    }

    // Validation - Name - check for ".com" at the end
    if (val_2 == 1)
    {
        char domain[] = ".com";
        int j = 1;
        int i = strlen(temp_email) - 3;
        while (temp_email[i])
        {
            if (temp_email[i] == domain[j++])
            {
                email_flag_2 = 1;
            }
            else
            {
                email_flag_2 = 0;
                break;
            }
            i++;
        }
    }

    if (email_flag_1 == 0)
    {
        printf("\nERROR! Input contain non alphabets or non special characters.\n");
        printf("Plese re-enter the Email.\n");
        return 0;
    }
    else if (email_flag_2 == 0)
    {
        printf("\nERROR! Input does not contain '.com' at the end.\n");
        printf("ERROR! Plese re-enter the Email.\n");
        return 0;
    }
    // if (email_flag_1 == 0 || email_flag_2 == 0)
    // {
    //     printf("ERROR! Plese re-enter the Email.\n");
    //     return 0;
    // }
    else
    {
        return 1;
    }

    // printf("Flag 1 is --------->[ %d ]\n",email_flag_1);
    // printf("Flag 2 is --------->[ %d ]\n",email_flag_2);
}
// Validation Functions -------------------------------------------------------------------------------------(||||||||||||)

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
    // Getting - Name ------------------------------------------------------------------------------------ (Name)
    char temp_name[50];
    int name_flag = 0;
    while (name_flag == 0)
    {
        printf("Name:");
        scanf(" %[^\n]", temp_name);
        name_flag = val_name(temp_name);
    }

    // Getting - Phone No. ------------------------------------------------------------------------------ (Phone)
    char temp_phone[11];
    int phone_flag = 0;

    while (phone_flag == 0 || phone_flag == 2)
    {
        printf("Phone:");
        scanf(" %[^\n]", temp_phone);
        phone_flag = val_phone(temp_phone, addressBook, 1, 1, 1);
    }

    // Getting - Email ------------------------------------------------------------------------------------ (Email)
    char temp_email[50];
    int email_flag = 0;

    while (email_flag == 0)
    {
        printf("Email:");
        scanf(" %[^\n]", temp_email);
        email_flag = val_email(temp_email, 1, 1);
    }

    // Saving - Name , Phone , Email
    strcpy(addressBook->contacts[(addressBook->contactCount)].name, temp_name);
    strcpy(addressBook->contacts[(addressBook->contactCount)].phone, temp_phone);
    strcpy(addressBook->contacts[(addressBook->contactCount)].email, temp_email);
    addressBook->contactCount++;
    printf("Contact added successfully.\n");
}

void searchContact(AddressBook *addressBook, int searchCriteria, int out_key, int found_arr[], int *found_count)
{
    if (out_key != 1)
    {
        *found_count = 0;
    }

    // Search by Name ------------------------------------------------------------------------------------ (Name)
    if (searchCriteria == 1)
    {
        char temp_name[50];
        int name_flag = 0;
        while (name_flag == 0)
        {
            printf("Name:");
            scanf(" %[^\n]", temp_name);
            name_flag = val_name(temp_name);
        }

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasestr(addressBook->contacts[i].name, temp_name) != NULL)
            {
                found_arr[(*found_count)++] = i;
            }
        }
    }

    // Search by Phone ------------------------------------------------------------------------------------ (Phone)
    else if (searchCriteria == 2)
    {
        char temp_phone[50];
        int phone_flag = 0;
        while (phone_flag == 0)
        {
            printf("Phone:");
            scanf(" %[^\n]", temp_phone);
            phone_flag = val_phone(temp_phone, addressBook, 1, 0, 0);
        }

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strstr(addressBook->contacts[i].phone, temp_phone) != NULL)
            {
                found_arr[(*found_count)++] = i;
            }
        }
    }

    // Search by Email ------------------------------------------------------------------------------------ (Email)
    else if (searchCriteria == 3)
    {
        char temp_email[50];
        int email_flag = 0;

        while (email_flag == 0)
        {
            printf("Email:");
            scanf(" %[^\n]", temp_email);
            email_flag = val_email(temp_email, 1, 0);
        }

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strstr(addressBook->contacts[i].email, temp_email) != NULL)
            {
                found_arr[(*found_count)++] = i;
            }
        }
    }

    // Return for Delete and Edit funcitons
    if (out_key == 1)
    {
        return;
    }

    // List Contacts - if not returned
    else if (*found_count)
    {
        printf("\n");
        printf("Contacts\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Number\t\tName\t\t\tPhone\t\t\tEmail\n");
        printf("-----------------------------------------------------------------------------\n");
        for (int i = 0; i < *found_count; i++)
        {
            printf("%-5d\t\t%-15s\t\t%-15s\t\t%-15s\n", i, addressBook->contacts[found_arr[i]].name, addressBook->contacts[found_arr[i]].phone, addressBook->contacts[found_arr[i]].email);
        }
        printf("-----------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\nNo contacts found with that information.\n");
    }
}

void editContact(AddressBook *addressBook, int searchCriteria)
{
    int found_arr[addressBook->contactCount];
    int found_count = 0;

    // Calling Search Function
    searchContact(addressBook, searchCriteria, 1, found_arr, &found_count);

    // Listing found contacts
    if (found_count)
    {
        printf("\n");
        printf("Contacts\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Number\t\tName\t\t\tPhone\t\t\tEmail\n");
        printf("-----------------------------------------------------------------------------\n");
        for (int i = 0; i < found_count; i++)
        {
            printf("%-5d\t\t%-15s\t\t%-15s\t\t%-15s\n", i, addressBook->contacts[found_arr[i]].name, addressBook->contacts[found_arr[i]].phone, addressBook->contacts[found_arr[i]].email);
        }
        printf("-----------------------------------------------------------------------------\n");

        // User Input - Index of contact
        int user_choise_1 = found_count;
        while (user_choise_1 >= found_count)
        {
            printf("Choose the number to edit that contact: ");
            scanf("%d", &user_choise_1);
        }

        printf("Select edit criteria:\n");
        printf("1. Edit by name\n");
        printf("2. Edit by phone\n");
        printf("3. Edit by email\n");
        printf("Enter your choice: ");

        // User Input - What to Edit
        int user_choise_2 = 0;
        while (user_choise_2 == 0)
            scanf("%d", &user_choise_2);

        // Edit Name ------------------------------------------------------------------------------------ (Name)
        if (user_choise_2 == 1)
        {
            char usr_name[50];
            int name_flag = 0;
            while (name_flag == 0)
            {
                printf("Enter new name: ");
                scanf(" %[^\n]", usr_name);
                name_flag = val_name(usr_name);
            }

            strcpy(addressBook->contacts[found_arr[user_choise_1]].name, usr_name);

            printf("Name changed successfully.\n");
        }
        // Edit Phone ------------------------------------------------------------------------------------ (Phone)
        else if (user_choise_2 == 2)
        {
            char usr_phone[11];
            int phone_flag = 0;
            while (phone_flag == 0)
            {
                printf("Enter new phone: ");
                scanf(" %[^\n]", usr_phone);
                phone_flag = val_phone(usr_phone, addressBook, 1, 1, 1);
            }

            strcpy(addressBook->contacts[found_arr[user_choise_1]].phone, usr_phone);

            printf("Phone changed successfully.\n");
        }
        // Edit Email ------------------------------------------------------------------------------------ (Email)
        else if (user_choise_2 == 3)
        {
            char usr_email[50];
            int email_flag = 0;
            while (email_flag == 0)
            {
                printf("Enter new email: ");
                scanf(" %[^\n]", usr_email);
                email_flag = val_email(usr_email, 1, 1);
            }

            strcpy(addressBook->contacts[found_arr[user_choise_1]].email, usr_email);

            printf("\nEmail changed successfully.\n");
        }
    }
    else
    {
        printf("\nNo contacts found with provided information.\n");
    }
}

void deleteContact(AddressBook *addressBook, int searchCriteria)
{
    int found_arr[addressBook->contactCount];
    int found_count = 0;

    // Calling Search Function
    searchContact(addressBook, searchCriteria, 1, found_arr, &found_count);

    // Listing found contacts
    if (found_count)
    {
        printf("\n");
        printf("Contacts\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Number\t\tName\t\t\tPhone\t\t\tEmail\n");
        printf("-----------------------------------------------------------------------------\n");
        for (int i = 0; i < found_count; i++)
        {
            printf("%-5d\t\t%-15s\t\t%-15s\t\t%-15s\n", i, addressBook->contacts[found_arr[i]].name, addressBook->contacts[found_arr[i]].phone, addressBook->contacts[found_arr[i]].email);
        }
        printf("-----------------------------------------------------------------------------\n");

        // User Input - Index of contact
        int del_choise = found_count;
        while (del_choise >= found_count)
        {
            printf("Choose the number to delete that contact: ");
            scanf("%d", &del_choise);
        }

        char confirmation_str[4] = "YYY";

        // Error Message - if not 'YES'
        while (strstr("YES", confirmation_str) == NULL)
        {
            printf("\n⚠︎ ⚠︎ ⚠︎\nAre you sure you want to delete contact no.%d\nType 'YES' to confirm:", del_choise);
            scanf(" %[^\n]", confirmation_str);
        }

        // Delete contact
        for (int i = found_arr[del_choise]; i < addressBook->contactCount; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        addressBook->contactCount--;

        printf("\nThe contact deleted successfully.\n");
    }
    else
    {
        printf("\nNo contacts found with provided information.\n");
    }
}

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    printf("\n");
    printf("Contacts\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("Name\t\t\tPhone\t\t\tEmail\n");
    printf("-----------------------------------------------------------------------------\n");

    if (sortCriteria == 1)
    {
        int i, j, smallest;
        char temp[50];

        for (i = 0; i < addressBook->contactCount; i++)
        {
            smallest = i;

            // Find the smallest element in the remaining unsorted part
            for (j = i + 1; j < addressBook->contactCount; j++)
            {
                if (addressBook->contacts[j].name[0] < addressBook->contacts[smallest].name[0])
                {
                    smallest = j;
                }
            }

            // have to swap all members of structure
            Contact temp = addressBook->contacts[i];
            addressBook->contacts[i] = addressBook->contacts[smallest];
            addressBook->contacts[smallest] = temp;

            printf("%-15s\t\t%-15s\t\t%-15s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
    }

    else if (sortCriteria == 2)
    {
        int i, j, smallest;
        char temp[50];

        for (i = 0; i < addressBook->contactCount; i++)
        {
            smallest = i;

            // Find the smallest element in the remaining unsorted part
            for (j = i + 1; j < addressBook->contactCount; j++)
            {
                if (addressBook->contacts[j].phone[0] < addressBook->contacts[smallest].phone[0])
                {
                    smallest = j;
                }
            }

            // have to swap all members of structure
            Contact temp = addressBook->contacts[i];
            addressBook->contacts[i] = addressBook->contacts[smallest];
            addressBook->contacts[smallest] = temp;

            printf("%-15s\t\t%-15s\t\t%-15s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
    }

    else if (sortCriteria == 3)
    {
        int i, j, smallest;
        char temp[50];

        for (i = 0; i < addressBook->contactCount; i++)
        {
            smallest = i;

            // Find the smallest element in the remaining unsorted part
            for (j = i + 1; j < addressBook->contactCount; j++)
            {
                if (addressBook->contacts[j].email[0] < addressBook->contacts[smallest].email[0])
                {
                    smallest = j;
                }
            }

            // have to swap all members of structure
            Contact temp = addressBook->contacts[i];
            addressBook->contacts[i] = addressBook->contacts[smallest];
            addressBook->contacts[smallest] = temp;

            printf("%-15s\t\t%-15s\t\t%-15s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
    }

    printf("-----------------------------------------------------------------------------\n");
}