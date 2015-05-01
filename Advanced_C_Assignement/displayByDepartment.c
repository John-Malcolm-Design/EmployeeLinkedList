//
//  displayByDepartment.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Prints all Emplyees to screen seperated into sections for each department
struct report* displayByDepartment(struct employee* head, char departmentParam[20], int report){
    
    // Initializes Time variables
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Creates a pointer to a new node
    struct employee *temp;
    struct report *reportTemp;
    
    // Allocate and assign memory for the new node
    temp = (struct employee*)malloc(sizeof(struct employee));
    
    // Allocate and assign memory for the new node
    reportTemp = (struct report*)malloc(sizeof(struct report));
    
    // Initializes/ resets reportTemp values
    reportTemp->numberOfEmployees = 0;
    reportTemp->financialOutlay = 0;
    reportTemp->totalBonus = 0;
    reportTemp->totalSalary = 0;
    
    // Assigns contents of head to temp
    temp = head;
    
    // Copies the departmentname into linkedlist
    strcpy(reportTemp->departmentName, departmentParam);
    
    // This while loop will traverse the LinkedList using the next pointer and print out the 'data'
    while( temp->next!= NULL ) {
        if ((strcmp(temp->department, departmentParam)) == 0) {
            
            // Prints to screen if the user has selected the display all option in menu
            if (report != 1) {
                // Print the data for the temp node
                printf("\nID: %d\nName: %s %s\nEmail: %s\nAddress: %s, %s, %s\nDepartment: %s\nDate: %d/%d/%d\nSalary: %d\n", temp->id, temp->firstName, temp->lastName, temp->email, temp->empAddress.street, temp->empAddress.city, temp->empAddress.country, temp->department, temp->date.date, temp->date.month, temp->date.year, temp->salary);
            }
            
            // Calculates/ Updates Salary & Number of emplyees Below
            reportTemp->totalSalary = reportTemp->totalSalary + temp->salary;
            reportTemp->numberOfEmployees = reportTemp->numberOfEmployees + 1;
            
            int i = (t->tm_year + 1900 - temp->date.year);
            
            // Calculates/ Updates Bonus Below
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
    
    // Calculates financialOutlay
    reportTemp->financialOutlay = (reportTemp->totalBonus + reportTemp->totalSalary);
    
    // Prints to file if the user selected the report option in menu
    if (report == 1) {
        
        // New File
        FILE *fpReport;
        
        // Open File for appending
        fpReport = fopen("/Users/johnmalcolm/Documents/C : C++/Advanced_C_Assignement/report.txt", "a");

        // Appends report for each department to file
        fprintf(fpReport, "Department Name: %s\n", reportTemp->departmentName);
        fprintf(fpReport, "Number of Employees: %d\n", reportTemp->numberOfEmployees);
        fprintf(fpReport, "Total Salary: %d\n", reportTemp->totalSalary);
        fprintf(fpReport, "Total Bonuses: %d\n", reportTemp->totalBonus);
        fprintf(fpReport, "Total Financial Outlay: %d\n\n", reportTemp->financialOutlay);
        
        // Closes File
        fclose(fpReport);
        
        // Prints report for each department to screen
        printf("Department Name: %s\n", reportTemp->departmentName);
        printf("Number of Employees: %d\n", reportTemp->numberOfEmployees);
        printf("Total Salary: %d\n", reportTemp->totalSalary);
        printf("Total Bonuses: %d\n", reportTemp->totalBonus);
        printf("Total Financial Outlay: %d\n\n", reportTemp->financialOutlay);
        
    }
    
    // Reurns report struct
    return reportTemp;
    
};
