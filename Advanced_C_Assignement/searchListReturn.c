//
//  searchListReturn.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Search list and return node
struct employee * searchListReturn(struct employee *head, int num) {
    
    // Creates a pointer to a new temporary node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Sets temp = head
    temp = head;
    
    // While the new temp node != NULL
    while( temp!= NULL ) {
        
        // If new temp nodes data == item searching for print "Data Found."
        if(temp ->id == num) {
            // Returns the node
            return(temp);
        }
        // Sets temp to the next node
        temp = temp ->next;
    }
    // returns head if not found
    return NULL;
};