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
        printf("1. Add Employee \n");
        printf("2. Display Emplyee Details\n");
        printf("3. Update Employee \n");
        printf("4. Delete Employee \n");
        printf("5. Display All Employees By Department  \n");
        printf("6. Employee Report \n");
        printf("-1. End Program \n\n");
        
        printf("Choice: ");
        scanf("%d", &userChoice);
        
        struct report *reportTemp;
        reportTemp = (struct employee*)malloc(sizeof(struct report));
        
        char itDepartment[20] = "IT";
        char salesDepartment[20] = "Sales";
        char legalDepartment[20] = "Legal";
        char hrDepartment[20] = "HR";
        
        // Runs the appropriate function based on the users choice
        switch (userChoice) {
            case 1:
                addEmployee(head);
                userChoice = NULL;
                break;
                
            case 2:
                printf("Enter ID of employee you would like to display: ");
                scanf("%d", &userSearch);
                
                struct employee *temp;
                temp = searchEmployee(head, userSearch);
                if (temp) {
                    printf("\nID: %d\nName: %s %s\nEmail: %s\nAddress: %s, %s, %s\nDepartment: %s\nDate: %d/%d/%d\nSalary: %d\n", temp->id, temp->firstName, temp->lastName, temp->email, temp->empAddress.street, temp->empAddress.city, temp->empAddress.country, temp->department, temp->date.date, temp->date.month, temp->date.year, temp->salary);
                } else{
                    printf("Employee not found!\n");
                }
                
                // Reset variables
                userSearch = NULL;
                userChoice = NULL;
                break;
                
            case 3:
                printf("Enter ID of employee you would like to update: ");
                scanf("%d", &userSearch);
                
                int updateChoice;
                struct employee *updateTemp;
                updateTemp = searchEmployee(head, userSearch);
                
                printf("What would you like to update?\n");
                printf("1 = Address\n");
                printf("2 = Department\n");
                printf("3 = Salary\n");
                scanf("%d", &updateChoice);
                
                if (updateTemp) {
                    switch (updateChoice) {
                        case 1:
                            // Employee Address Below
                            // Street
                            printf("\nAddress: \n");
                            printf("Enter house number and street name (Use underscores instead of spaces!): ");
                            scanf("%s", &updateTemp->empAddress.street);
                            
                            // City
                            printf("Enter city/town: ");
                            scanf("%s", &updateTemp->empAddress.city);
                            
                            // Country
                            printf("Enter country: ");
                            scanf("%s", &updateTemp->empAddress.country);
                            break;
                        case 2:
                            // Department
                            printf("Enter department: (Either: Sales, IT, Legal or HR)");
                            scanf("%s", &updateTemp->department);
                            break;
                        case 3:
                            // Salary
                            printf("Enter Salary: ");
                            scanf("%d", &updateTemp->salary);
                            break;
                        default:
                            break;
                    }
                    writeToFile(head);
                    
                } else{
                    printf("Employee not found!\n");
                }
                
                updateChoice = NULL;
                userSearch = NULL;
                userChoice = NULL;
                break;
                
            case 4:
                printf("Enter id of employee you would like to delete: ");
                scanf("%d", &userSearch);
                deleteEmployee(&head, userSearch);
                writeToFile(head);
                // Reset variables
                userSearch = NULL;
                userChoice = NULL;
                break;
            case 8:
                sortList(head);
                break;
                
            case 5:
                printf("\n***** IT Department *****\n");
                reportTemp = displayByDepartment(head, itDepartment, 0);
                
                printf("\n\n***** Sales Department *****\n");
                reportTemp = displayByDepartment(head, salesDepartment, 0);
                
                printf("\n\n***** Legal Department *****\n");
                reportTemp = displayByDepartment(head, legalDepartment, 0);
                
                printf("\n\n***** HR Department *****\n");
                reportTemp = displayByDepartment(head, hrDepartment, 0);
                
                // Clears userChoice variable so the user can pick another option
                userChoice = NULL;
                break;
                
            case 6:
                printf("\n***** IT Department *****\n");
                reportTemp = displayByDepartment(head, itDepartment, 1);
                
                printf("\n\n***** Sales Department *****\n");
                reportTemp = displayByDepartment(head, salesDepartment, 1);
                
                printf("\n\n***** Legal Department *****\n");
                reportTemp = displayByDepartment(head, legalDepartment, 1);
                
                
                printf("\n\n***** HR Department *****\n");
                reportTemp = displayByDepartment(head, hrDepartment, 1);
                
                // Clears userChoice variable so the user can pick another option
                userChoice = NULL;
                break;
                
            default:
                break;
        }
    } while (userChoice != -1);
    // end of program
    
};