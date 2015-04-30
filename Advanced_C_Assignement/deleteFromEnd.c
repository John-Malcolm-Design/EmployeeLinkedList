//
//  deleteFromEnd.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

void deleteFromEnd(struct employee *head){
    
    struct employee *temp, *last;
    
    temp = (struct employee*)malloc(sizeof(struct employee));
    
    temp = head;
    last = temp;
    
    while(temp->next != NULL && temp != NULL)
    {
        last = temp;
        temp = temp->next;
    }
    if (last == temp) {
        free(temp);
        head = NULL;
    }else{
        free(last->next);
        last->next = NULL;
    }
};
