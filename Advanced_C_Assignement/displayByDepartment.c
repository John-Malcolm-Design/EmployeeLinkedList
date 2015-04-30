//
//  displayByDepartment.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Prints all Nodes to screen
struct report* displayByDepartment(struct employee* head, char departmentParam[20], int report){
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Creates a pointer to a new node
    struct employee *temp;
    struct report *reportTemp;
    
    // Allocate and assign memory for the new node
    temp = (struct employee*)malloc(sizeof(struct employee));
    
    // Allocate and assign memory for the new node
    reportTemp = (struct report*)malloc(sizeof(struct report));
    
    reportTemp->numberOfEmployees = 0;
    reportTemp->financialOutlay = 0;
    reportTemp->totalBonus = 0;
    reportTemp->totalSalary = 0;
    
    // Assigns contents of head to temp
    temp = head;

    strcpy(reportTemp->departmentName, departmentParam);
    
    // This while loop will traverse the LinkedList using the next pointer and print out the 'data'
    while( temp->next!= NULL ) {
        if ((strcmp(temp->department, departmentParam)) == 0) {
            
            if (report != 1) {
                // Print the data for the temp node
                printf("\nID: %d\nName: %s %s\nEmail: %s\nAddress: %s, %s, %s\nDepartment: %s\nDate: %d/%d/%d\nSalary: %d\n", temp->id, temp->firstName, temp->lastName, temp->email, temp->empAddress.street, temp->empAddress.city, temp->empAddress.country, temp->department, temp->date.date, temp->date.month, temp->date.year, temp->salary);
            }
            
            reportTemp->totalSalary = reportTemp->totalSalary + temp->salary;
            reportTemp->numberOfEmployees = reportTemp->numberOfEmployees + 1;
            
            int i = (t->tm_year + 1900 - temp->date.year);
            
            if (i > 10) {
                reportTemp->totalBonus = reportTemp->totalBonus + (temp->salary * 0.05);
            } else if (i > 5){
                reportTemp->totalBonus = reportTemp->totalBonus + (temp->salary * 0.04);
            } else {
                reportTemp->totalBonus = reportTemp->totalBonus + (temp->salary * 0.03);
            }
            
        }
        
        // Sets the value of temp to the next node
        temp = temp->next;
    }
    
    reportTemp->financialOutlay = (reportTemp->totalBonus + reportTemp->totalSalary);
    
    if (report == 1) {
        // Testing
        printf("Department Name: %s\n", reportTemp->departmentName);
        printf("Number of Employees: %d\n", reportTemp->numberOfEmployees);
        printf("Total Salary: %d\n", reportTemp->totalSalary);
        printf("Total Bonuses: %d\n", reportTemp->totalBonus);
        printf("Total Financial Outlay: %d\n", reportTemp->financialOutlay);
    }
    
    return reportTemp;

};
