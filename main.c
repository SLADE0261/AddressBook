#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createContact(&addressBook);
            break;
        case 2:
            printf("Select search criteria:\n");
            printf("1. search by name\n");
            printf("2. search by phone\n");
            printf("3. search by email\n");
            printf("Enter your choice: ");

            int searchChoice = 4;
            scanf(" %d", &searchChoice);

            // validation for input is between 1 to 3
            while (searchChoice > 3)
            {
                printf("Invalid input. Please re-enter a number.\n");
                printf("Enter your choice: ");
                scanf(" %d", &searchChoice);
            }

            int i = 0;            // unused - dummy variable
            int found_arr[10000]; // unused - dummy variable
            searchContact(&addressBook, searchChoice, 0, found_arr, &i);
            break;
        case 3:
            printf("Select search criteria:\n");
            printf("1. search by name\n");
            printf("2. search by phone\n");
            printf("3. search by email\n");
            printf("Enter your choice: ");
            int editSearchChoice;
            scanf("%d", &editSearchChoice);

            // validation for input is between 1 to 3
            while (editSearchChoice > 3)
            {
                printf("Invalid input. Please re-enter a number.\n");
                printf("Enter your choice: ");
                scanf(" %d", &editSearchChoice);
            }

            editContact(&addressBook, editSearchChoice);
            break;
        case 4:
            printf("Select search criteria:\n");
            printf("1. search by name\n");
            printf("2. search by phone\n");
            printf("3. search by email\n");
            printf("Enter your choice: ");
            int deleteSearchChoice;
            scanf("%d", &deleteSearchChoice);

            // validation for input is between 1 to 3
            while (deleteSearchChoice > 3)
            {
                printf("Invalid input. Please re-enter a number.\n");
                printf("Enter your choice: ");
                scanf(" %d", &deleteSearchChoice);
            }

            deleteContact(&addressBook, deleteSearchChoice);
            break;
        case 5:
            printf("Select sort criteria:\n");
            printf("1. Sort by name\n");
            printf("2. Sort by phone\n");
            printf("3. Sort by email\n");
            printf("Enter your choice: ");
            int sortChoice;
            scanf("%d", &sortChoice);

            // validation for input is between 1 to 3
            while (sortChoice > 3)
            {
                printf("Invalid input. Please re-enter a number.\n");
                printf("Enter your choice: ");
                scanf(" %d", &sortChoice);
            }

            listContacts(&addressBook, sortChoice);
            break;
        case 6:
            printf("Saving and Exiting...\n");
            saveContactsToFile(&addressBook);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}