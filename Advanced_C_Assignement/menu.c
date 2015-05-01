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

// Menu for user choice of various programs
// Includes switch statement that handles the users choice
void menu(struct employee* head){
    
    do {
        // Displays the various choices the employee program
        printf("\n** Please chose from the options below below **\n");
        printf("1. Add Employee \n");
        printf("2. Display Emplyee Details\n");
        printf("3. Update Employee \n");
        printf("4. Delete Employee \n");
        printf("5. Display All Employees By Department  \n");
        printf("6. Employee Report \n");
        printf("-1. End Program \n\n");
        
        // Gets the choice from the user
        printf("Choice: ");
        scanf("%d", &userChoice);
        
        // Initializes up report structure used below
        struct report *reportTemp;
        reportTemp = (struct report*)malloc(sizeof(struct report));
        
        // Initializes varaiables for the various departments
        char itDepartment[20] = "IT";
        char salesDepartment[20] = "Sales";
        char legalDepartment[20] = "Legal";
        char hrDepartment[20] = "HR";
        
        // Runs the appropriate function based on the users choice
        
        switch (userChoice) {
                
            // Add Employee
            case 1:
                addEmployee(head);
                userChoice = NULL;
                break;
                
            // Display Employee
            case 2:
                
                // Prompts user to enter ID of employee
                printf("Enter ID of employee you would like to display: ");
                scanf("%d", &userSearch);
                
                // Initializes Struct
                struct employee *temp;
                
                // Searches for emplyee
                temp = searchEmployee(head, userSearch);
                
                // If employee found prints to screen else prints 'Employee not found!'
                if (temp) {
                    printf("\nID: %d\nName: %s %s\nEmail: %s\nAddress: %s, %s, %s\nDepartment: %s\nDate: %d/%d/%d\nSalary: %d\n", temp->id, temp->firstName, temp->lastName, temp->email, temp->empAddress.street, temp->empAddress.city, temp->empAddress.country, temp->department, temp->date.date, temp->date.month, temp->date.year, temp->salary);
                } else{
                    printf("Employee not found!\n");
                }
                
                // Resets variables
                userSearch = NULL;
                userChoice = NULL;
                break;
                
            // Update Employee
            case 3:
                
                // Prompts user to enter ID of employee
                printf("Enter ID of employee you would like to update: ");
                scanf("%d", &userSearch);
                
                // Initialize choice varaible and employee LinkedList
                int updateChoice;
                struct employee *updateTemp;
                
                // Searches for employee
                updateTemp = searchEmployee(head, userSearch);
                
                // If found updates emplyees details
                if (updateTemp) {
                    
                    printf("What would you like to update?\n");
                    printf("1 = Address\n");
                    printf("2 = Department\n");
                    printf("3 = Salary\n");
                    scanf("%d", &updateChoice);
                    
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
                    
                    // Writes employee LinkedList to file
                    writeToFile(head);
                    
                } else{
                    printf("Employee not found!\n");
                }
                
                // Resets variables
                updateChoice = NULL;
                userSearch = NULL;
                userChoice = NULL;
                break;
            
            // Delete Employee
            case 4:
                
                // Initialize choice varaible and employee LinkedList
                printf("Enter id of employee you would like to delete: ");
                scanf("%d", &userSearch);
                
                // Calls delete employee function
                deleteEmployee(&head, userSearch);
                
                // Writes employee LinkedList to file
                writeToFile(head);
                
                // Reset variables
                userSearch = NULL;
                userChoice = NULL;
                break;
             
            // Display all by deparment
            case 5:
                
                // Prints IT Department
                printf("\n***** IT Department *****\n");
                
                // Calls report function for IT department
                reportTemp = displayByDepartment(head, itDepartment, 0);
                
                // Prints Sales Department
                printf("\n\n***** Sales Department *****\n");
                
                // Calls report function for Sales department
                reportTemp = displayByDepartment(head, salesDepartment, 0);
                
                // Prints Legal Department
                printf("\n\n***** Legal Department *****\n");
                
                // Calls report function for Legal department
                reportTemp = displayByDepartment(head, legalDepartment, 0);
                
                // Prints HR Department
                printf("\n\n***** HR Department *****\n");
                
                // Calls report function for HR department
                reportTemp = displayByDepartment(head, hrDepartment, 0);
                
                // Clears userChoice variable so the user can pick another option
                userChoice = NULL;
                break;
                
            // Employee Report
            case 6:
                printf("\n EMPLOYEE REPORT BELOW\n\n");
                
                // File Pointer
                FILE *fpReportWrite;
                
                // Open File for Writing
                fpReportWrite = fopen("/Users/johnmalcolm/Documents/C : C++/Advanced_C_Assignement/report.txt", "w+");
                
                // Writes heading to report file
                fprintf(fpReportWrite, "REPORT DOCUMENT\n\n");
                
                // Closes report file
                fclose(fpReportWrite);
                
                // Calls report function for each department
                reportTemp = displayByDepartment(head, itDepartment, 1);
                reportTemp = displayByDepartment(head, salesDepartment, 1);
                reportTemp = displayByDepartment(head, legalDepartment, 1);
                reportTemp = displayByDepartment(head, hrDepartment, 1);
                
                // Clears userChoice variable so the user can pick another option
                userChoice = NULL;
                break;
                
            default:
                break;
        }
    
    // Keeps displaying menu until user enters -1
    } while (userChoice != -1);
};