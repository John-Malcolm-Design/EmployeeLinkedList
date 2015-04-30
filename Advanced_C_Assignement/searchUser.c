//
//  searchUser.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 30/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Search list and return node
int searchUser(struct login *head, char* username, char* password) {
    
    // Creates a pointer to a new temporary node
    struct login *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct login*)malloc(sizeof(struct login));
    
    // Sets temp = head
    temp = head;
    
    // While the new temp node != NULL
    while( temp!= NULL ) {

        // If new temp nodes data == item searching for print "Data Found."
        if((strcmp(temp->username, username) == 0) && (strcmp(temp->password, password) == 0)) {
            // Returns the node
            return(1);
            break;
        }
        // Sets temp to the next node
        temp = temp ->next;
    }
    // returns head if not found
    return 0;
};