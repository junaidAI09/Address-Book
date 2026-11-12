#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("                    CONTACT DIRECTORY\n");
    printf("------------------------------------------------------------\n");

    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");

    printf("------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-20s %-15s %-30s\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("------------------------------------------------------------\n\n");
}

void initialize(AddressBook *addressBook) {
    //populateAddressBook(addressBook);
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook) ;

  }

void saveAndExit(AddressBook *addressBook) {
   saveContactsToFile(addressBook);
   printf("Exiting the Application. Goodbye!\n");

}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("\nEnter Name: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

    char phone[20];
    while(1)
    {
    printf("Enter Phone Number: ");
    scanf(" %[^\n]",phone);
    int valid =1;
    if(strlen(phone)!=10)
    {
        valid=0;
    }
    for(int i=0;phone[i]!='\0';i++){
        if(phone[i]<'\0'||phone[i]>'9')
        {
            valid=0;
            break;
        }
    }
    if(valid)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
        break;
    }
    printf("Invalid Phone number! Enter a valid Phone Number.\n");
}


char email[50];
while(1){
    printf("Enter Email:");
    scanf(" %[^\n]",email);
    if(strstr(email, "@gmail.com")!= NULL)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].email,email);
        break;
    }
    printf("Invalid Email! Enter a valid Gmail address.\n");
}
    addressBook->contactCount++;
    printf("------!Contact created successfully!------\n\n");
}
    

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
    
    printf("\nSearch Contact by:\n");
    printf("[1] Name\n");
    printf("[2] Phone\n");
    printf("[3] Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: char name[50];
        printf("Enter name to search: ");
        scanf(" %[^\n]", name);
        for(int i=0; i<addressBook->contactCount; i++){
            if(strcmp(addressBook->contacts[i].name, name) == 0){
                printf("\nContact found!\n");
                printf("--------------------------------\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("--------------------------------\n\n");
                return;
            }
        }
        printf("Contact not found.\n\n");
        break;
        
        case 2: char phone[20];
        printf("Enter Phone Number to Search: ");
        scanf(" %[^\n]", phone);
        for(int i=0; i<addressBook->contactCount; i++){
            if(strcmp(addressBook->contacts[i].phone, phone) == 0){
                printf("\nContact found:\n");
                 printf("--------------------------------\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("--------------------------------\n\n");
                return;
            }
        }
        printf("Contact not found.\n\n");
        break;

        case 3: char email[50];
        printf("Enter Email to search: ");
        scanf(" %[^\n]", email);
        for(int i=0; i<addressBook->contactCount; i++){
            if(strcmp(addressBook->contacts[i].email, email) == 0){
                printf("\nContact found:\n");
                printf("--------------------------------\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("--------------------------------\n\n");
                return;
            }
        }   
        printf("Contact not found.\n\n");
        break;
    }
}

 void editContact(AddressBook *addressBook){
    /* Define the logic for Editcontact */
    int choice;
    int index = -1;

    printf("\nSearch contact to Edit by:\n");
    printf("[1] Name\n");
    printf("[2] Phone\n");
    printf("[3] Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:{
            char name[50];
            printf("Enter name to search: ");
            scanf(" %[^\n]", name);
             for(int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].name, name) == 0)
                {
                    index = i;
                    break;
                }
            }
            break;
        }
        case 2:{
            char phone[20];
            printf("Enter phone number to search: ");
            scanf(" %[^\n]", phone);
            for(int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].phone, phone) == 0)
                {
                    index = i;
                    break;
                }
            }
            break;
        }
         case 3:{
            char email[50];
            printf("Enter email to search: ");
            scanf(" %[^\n]", email);
            for(int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].email, email) == 0)
                {
                    index = i;
                    break;
                }
            }
            break;
        }
    }

    if(index == -1)
    {
        printf("Contact not found.\n\n");
        return;
    }
    printf("\nContact found!\n");
    printf("--------------------------------\n");
    printf("Name : %s\n", addressBook->contacts[index].name);
    printf("Phone: %s\n", addressBook->contacts[index].phone);
    printf("Email: %s\n", addressBook->contacts[index].email);
    printf("--------------------------------\n");

    printf("\nWhat would you like to edit?\n");
    printf("[1] Name\n");
    printf("[2] Phone\n");
    printf("[3] Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter new name: ");
            scanf(" %[^\n]", addressBook->contacts[index].name);
            break;
        case 2:
            printf("Enter new phone: ");
            scanf(" %[^\n]", addressBook->contacts[index].phone);
            break;
        case 3:
            printf("Enter new email: ");
            scanf(" %[^\n]", addressBook->contacts[index].email);
            break;
}
 printf("------!Contact updated successfully!------\n\n");
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int choice;
    int index = -1;

    printf("\nSearch contact to Delete by:\n");
    printf("[1] Name\n");
    printf("[2] Phone\n");
    printf("[3] Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:{
            char name[50];
            printf("Enter Name to search: ");
            scanf(" %[^\n]", name);
             for(int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].name, name) == 0)
                {
                    index = i;
                    break;
                }
            }
            break;
        }
        case 2:{
            char phone[20];
            printf("Enter Phone Number to search: ");
            scanf(" %[^\n]", phone);
            for(int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].phone, phone) == 0)
                {
                    index = i;
                    break;
                }
            }
            break;
        }
         case 3:{
            char email[50];
            printf("Enter Email to search: ");
            scanf(" %[^\n]", email);
            for(int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].email, email) == 0)
                {
                    index = i;
                    break;
                }
            }
            break;
        }
    }
if(index==-1){
    printf("Contact Not Found.\n\n");
    return ;
}
for(int i=index ; i < addressBook->contactCount-1 ; i++){
    addressBook->contacts[i]=addressBook->contacts[i+1];
}
addressBook->contactCount--;
printf("------!Contact Deleted Successfully!------\n\n");
}