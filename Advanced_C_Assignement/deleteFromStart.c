//
//  deleteFromStart.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

void deleteFromStart(struct employee **head){
    // Create a pointer to a new node
    struct employee *newNode;
    
    newNode = *head;
    
    *head = newNode->next;
    
    free(newNode);
    
};