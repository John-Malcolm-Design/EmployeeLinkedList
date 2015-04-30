//
//  printNodes.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Prints all Nodes to screen
void printNodes(struct employee* head){
    
    // Creates a pointer to a new node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp = (struct employee*)malloc(sizeof(struct employee));
    
    // Assigns contents of head to temp
    temp = head;
    
    
    // This while loop will traverse the LinkedList using the next pointer and print out the 'data'
    while( temp!= NULL ) {
        
        // Print the data for the temp node
        printf("\nID: %d\nName: %s %s\nEmail: %s\nAddress: %s, %s, %s\nDepartment: %s\nDate: %d", temp->id, temp->firstName, temp->lastName, temp->email, temp->empAddress.street, temp->empAddress.city, temp->empAddress.country, temp->department, temp->date);
        
        // Sets the value of temp to the next node
        temp = temp->next;
    }
};
