//
//  customHeader.h
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#ifndef Advanced_C_Assignement_customHeader_h
#define Advanced_C_Assignement_customHeader_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct address{
    char street[40];
    char city[30];
    char country[30];
};

// Node Struct
struct employee{
    int id;
    char firstName[20];
    char lastName[20];
    char email[30];
    struct address empAddress;
    char department[20];
    int date;
    int salary;
    struct employee *next;
};

// Function Declarations
void addToStart();
void addToEnd();
void menu();
void printNodes();
void searchList();
struct employee* searchListReturn();
void deleteFromStart();
void deleteFromEnd();
void sortList();
void swap();

#endif
