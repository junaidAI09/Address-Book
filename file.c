#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contacts.txt","w");
    if(fp == NULL)
    {
        printf("Failed to open file\n");
        return;
    }
    for(int i=0 ;i<addressBook->contactCount; i++){
        fprintf(fp, "%s,%s,%s\n",
             addressBook->contacts[i].name,
             addressBook->contacts[i].phone,
              addressBook->contacts[i].email);
    }
  fclose(fp);
  printf("------!Contacts Saved Successfully!------\n\n");
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp;

    fp = fopen("contacts.txt", "r");

    if(fp == NULL)
    {
        printf("No contacts file found.\n");
        return;
    }

    while(fscanf(fp, "%[^,],%[^,],%[^\n]\n",
                 addressBook->contacts[addressBook->contactCount].name,
                 addressBook->contacts[addressBook->contactCount].phone,
                 addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;

        if(addressBook->contactCount >= 100)
            break;
    }

    fclose(fp);

    //printf("%d contacts loaded successfully!\n",addressBook->contactCount);
}

  