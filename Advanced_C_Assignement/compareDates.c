//
//  compareDates.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 30/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

int compareDates(struct date d1, struct date d2)
{
   return d1.year - d2.year;
}