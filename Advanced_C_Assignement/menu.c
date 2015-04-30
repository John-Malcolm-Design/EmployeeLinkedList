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

void menu(struct employee* head){
    
    do {
        // Displays the various choices the user has for manipulating the Linked List
        
        printf("\n** Please chose from the options below below **\n");
        printf("1. Print Employees \n");
        printf("2. Add Employee \n");
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