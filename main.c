#include <stdio.h>
#include "contact.h"
#include "file.h"

int main() {
    int choice;
   AddressBook A1;
   initialize(&A1);
   printf("\n!Welcome to the Address Book Application!\n");
    do {
    printf("----Select an option----\n");
    printf("[1] Create Contact\n");
    printf("[2] Search Contacts\n");
    printf("[3] Edit Contact\n");
    printf("[4] Delete Contact\n");
    printf("[5] List All Contacts\n");
    printf("[6] Save Contacts to File\n");
    printf("[7] Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Selected Create Contact!\n");
            createContact(&A1);
            break;
        case 2:
            printf("Selected Search Contacts!\n");  
            searchContact(&A1);
        break;
        case 3:
            printf("Selected Edit Contact!\n");
            editContact(&A1);
            break;
        case 4:
            printf("Selected Delete Contact!\n");
            deleteContact(&A1);
            break;
        case 5: 
            printf("Selected List All Contacts!\n");
            listContacts(&A1);
            break;
        case 6:
            printf("Selected Save Contacts to File!\n");
            saveContactsToFile(&A1);
            break;
        case 7:
           // printf("Exiting the application. Goodbye!\n");
            saveAndExit(&A1);
            break;
        default:    
        printf("Invalid choice. Please try again.\n");
            break;
    }
    } while (choice != 7);
     return 0;
}   

