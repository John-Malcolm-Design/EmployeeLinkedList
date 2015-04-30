//
//  addToStart.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Allows the user to add node to the start of the list
void addToStart( struct employee** head ){
    
    // Create a pointer to a new node
    struct employee *newNode;
    
    // Allocate and assign memory for the new node
    newNode = (struct employee*)malloc(sizeof(struct employee));
    
    // Get data for new node from user
    printf("\nEnter data(of type int) for this node: ");
    scanf("%d", &newNode->id);
    
    // Set the next pointer for the new node to the current first node
    newNode->next = *head;
    
    // Point the head at the new node
    *head = newNode;
    
};
