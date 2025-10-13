#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.csv","w");
    // ------------------------------------------------------- Validation
    if (fp == NULL)
    {
        printf("Error accessing file\n");
        return;
    }

    // ------------------------------------------------------- priting to the file
    for (int i = 0 ; i < addressBook->contactCount; i++)
    {
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fp);

    return;
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.csv","r");
    // ------------------------------------------------------- Validation
    if (fp == NULL)
    {
        printf("Error accessing file\n");
        return;
    }

    // ------------------------------------------------------- scaning from the file
    for (int i = 0 ; ; i++)
    {   
        if ( fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email) != 3 )
        {
            break;
        }

        addressBook->contactCount++;
    }

    fclose(fp);

    return;
}
