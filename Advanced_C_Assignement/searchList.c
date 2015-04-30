//
//  searchList.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Allows the user to search the list for specific data. Does not return a value
void searchList(struct employee *head, int num) {
    
    // Creates a pointer to a new temporary node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Sets temp = head
    temp = head;
    
    // While the new temp node != NULL
    while( temp!= NULL )
    {
        // If new temp nodes data == item searching for print "Data Found."
        if(temp->id == num) {
            printf("\nData Found.\n");
            return;
        }
        // Sets temp to the next node
        temp = temp->next;
    }
    // IF data was not found prints "Data not found"
    printf("\nData not found\n");
};
