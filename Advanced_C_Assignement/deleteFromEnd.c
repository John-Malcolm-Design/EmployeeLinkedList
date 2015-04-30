//
//  deleteFromEnd.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

void deleteFromEnd(struct employee **head, int num){
    
    // Creates a pointer to a new temporary node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Sets temp = head
    temp = *head;
    
    struct employee *newNode;
    
    newNode = temp;
    int count = 0;
    
    // While the new temp node != NULL
    while( temp!= NULL )
    {
        // If new temp nodes data == item searching for print "Data Found."
        if(temp->id == num) {
            if (count == 0) {
                newNode = *head;
                
                *head = newNode->next;
                
                free(newNode);
                
                return;
            }
            printf("%s", temp->firstName);
            newNode->next = temp->next;
            free(temp);
            return;
        }
        // Sets temp to the next node
        newNode = temp;
        temp = temp->next;
        count++;
        
    }
    // IF data was not found prints "Data not found"
    printf("\nData not found\n");
    
};
