//
//  addToEnd.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Allows the user to add a node to the end of the list
void addToEnd(struct employee* head) {
    
    // Creates a pointer to a new node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Assigns contents of head to temp
    temp = head;
    
    // While temps next node is not NULL
    while(temp->next != NULL)
    {
        // Set temp to the next node
        temp = temp->next;
    }
    // Creates a pointer to a new node
    struct employee *newNode;
    
    // Allocate and assign memory for the new node
    newNode = (struct employee*)malloc(sizeof(struct employee));
    
    // Get data for new node from user
    printf("\nEnter data(of type int) for this node: ");
    scanf("%d", &newNode->id);
    
    // Sets the next node to null for the new node as it is the last node in the list
    newNode->next = NULL;
    
    //
    temp->next = newNode ;
};