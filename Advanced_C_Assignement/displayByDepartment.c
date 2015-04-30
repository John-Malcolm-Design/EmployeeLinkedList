//
//  printNodes.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Prints all Nodes to screen
struct report* displayByDepartment(struct employee* head, char departmentParam[20]){
    
    // Creates a pointer to a new node
    struct employee *temp;
    struct report *reportTemp;
    
    // Allocate and assign memory for the new node
    temp = (struct employee*)malloc(sizeof(struct employee));
    
    // Allocate and assign memory for the new node
    reportTemp = (struct employee*)malloc(sizeof(struct report));
    
    // Assigns contents of head to temp
    temp = head;

    strcpy(reportTemp->departmentName, departmentParam);
    
    // This while loop will traverse the LinkedList using the next pointer and print out the 'data'
    while( temp->next!= NULL ) {
        if ((strcmp(temp->department, departmentParam)) == 0) {
            // Print the data for the temp node
            printf("\nID: %d\nName: %s %s\nEmail: %s\nAddress: %s, %s, %s\nDepartment: %s\nDate: %d\nSalary: %d\n", temp->id, temp->firstName, temp->lastName, temp->email, temp->empAddress.street, temp->empAddress.city, temp->empAddress.country, temp->department, temp->date, temp->salary);
            
            reportTemp->totalSalary = reportTemp->totalSalary + temp->salary;
            reportTemp->numberOfEmployees++;
            
//            if (temp->date) {
//                <#statements#>
//            }
        }
        
        // Sets the value of temp to the next node
        temp = temp->next;
    }
    
    return reportTemp;

};
