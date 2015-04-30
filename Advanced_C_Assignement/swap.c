//
//  swap.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

/* function to swap data of two nodes a and b*/
void swap(struct employee *a, struct employee *b)
{
    int temp = a->id;
    a->id = b->id;
    b->id = temp;
}