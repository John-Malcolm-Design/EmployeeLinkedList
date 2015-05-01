//
//  sortList.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Bubble sort for emplyee LinkedList
void sortList(struct employee *head)
{
    int swapped, i;
    struct employee *ptr1;
    
    do
    {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != NULL)
        {
            if (ptr1->id > ptr1->next->id)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
    }
    while (swapped);
}