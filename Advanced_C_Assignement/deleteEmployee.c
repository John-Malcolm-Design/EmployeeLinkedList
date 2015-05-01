//
//  deleteEmployee.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Removes Emplyee from LinkedList
void deleteEmployee(struct employee **head, int num){
    
    // Creates a pointer to a new temporary node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Sets temp = head
    temp = *head;
    
    // New Node used for replacement
    struct employee *newNode;
    
    // Assign the value of temp to newNode
    newNode = temp;
    
    // Initialize Count
    int count = 0;
    
    // While the new temp node != NULL
    while( temp!= NULL )
    {
        // If new temp nodes data == item searching for print "Data Found."
        if(temp->id == num) {
            
            // If its the first node in LinkedList
            // Deletes Employee from the start of the LinkedList
            if (count == 0) {
                newNode = *head;
                *head = newNode->next;
                free(newNode);
                return;
            }
            
            // Deletes Employee & Fixes Links between nodes
            printf("%s Deleted", temp->firstName);
            newNode->next = temp->next;
            free(temp);
            return;
        }
        
        // Sets temp to the next node
        newNode = temp;
        temp = temp->next;
        
        // Increases Count used to check for replacement of first Node in LinkedList
        count++;
        
    }
    // If data was not found prints "Data not found"
    printf("\nData not found\n");
    
};
