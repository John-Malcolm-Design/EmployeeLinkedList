//
//  menu.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Displays the various choices the user has for manipulating the Linked List

// Used for switch statement & searching the list
int userChoice = NULL;
int userSearch = NULL;

void menu(){
    
    // Node initialization. Nodes to be included in the Linked List
    struct employee *head = NULL;
    struct employee *billy = NULL;
    
    // Allocated memory for both the first node(the one that head points to!) and the "billy" Node.
    head = (struct employee*)malloc(sizeof(struct employee));
    billy = (struct employee*)malloc(sizeof(struct employee));
    
    // Initialize data and next properties of the first Node.
    // Accesed via head pointer
    head->id = 0001;
    strcpy( head->firstName, "John Malcolm" );
    strcpy( head->lastName, "Anderson" );
    strcpy( head->email, "hi@johnmalcolmdesign.com" );
    strcpy( head->empAddress.street, "132 Ros Caoin, Roscam" );
    strcpy( head->empAddress.city, "Galway" );
    strcpy( head->empAddress.country, "Ireland" );
    strcpy( head->department, "IT" );
    head->date = 20042015;
    head->salary = 60000;
    head->next = billy;
    
    // Initialize data and next properties of the billy Node.
    billy->id = 0002;
    strcpy( billy->firstName, "Charles" );
    strcpy( billy->lastName, "Mahony" );
    strcpy( billy->email, "charlieboy12@yahoo.com" );
    strcpy( billy->empAddress.street, "12 Newcastle Rd" );
    strcpy( billy->empAddress.city, "Galway" );
    strcpy( billy->empAddress.country, "Ireland");
    strcpy( billy->department, "Sales");
    billy->date = 12042019;
    billy->salary = 50000;
    billy->next= NULL;
    
    do {
        // Displays the various choices the user has for manipulating the Linked List
        
        printf("\n** Please chose from the options below below **\n");
        printf("1. Print Employees \n");
        printf("2. Add Employee to End \n");
        printf("3. Add Employees to Start \n");
        printf("4. Search List for Employees \n");
        printf("5. Search List and Return Employees \n");
        printf("6. Delete Employee From Start \n");
        printf("7. Delete Employee From End \n");
        printf("8. Sort Employees List \n");
        printf("-1. End Program \n\n");
        
        printf("Choice: ");
        scanf("%d", &userChoice);
        
        // Runs the appropriate function based on the users choice
        switch (userChoice) {
            case 1:
                printNodes(head);
                // Clears userChoice variable so the user can pick another option
                userChoice = NULL;
                break;
            case 2:
                addToEnd(head);
                userChoice = NULL;
                break;
            case 3:
                addToStart(&head);
                userChoice = NULL;
                break;
            case 4:
                printf("Enter number to search list for: ");
                scanf("%d", &userSearch);
                searchList(head, userSearch);
                // Reset variables
                userSearch = NULL;
                userChoice = NULL;
                break;
            case 5:
                printf("Enter number to search list for: ");
                scanf("%d", &userSearch);
                
                struct employee *search;
                search = searchListReturn(head, userSearch);
                if (search) {
                    printf("Data Found at memory address: %x\n", search);
                    printf("Data Found: %d", search->id);
                } else{
                    printf("DATA NOT FOUND!\n");
                }
                
                // Reset variables
                userSearch = NULL;
                userChoice = NULL;
                break;
            case 6:
                deleteFromStart(&head);
                break;
            case 7:
                deleteFromEnd(head);
                break;
            case 8:
                sortList(head);
                break;
            default:
                break;
        }
    } while (userChoice != -1);
    // end of program

};