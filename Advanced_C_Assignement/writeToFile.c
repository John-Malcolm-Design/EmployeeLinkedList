//
//  writeToFile.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 30/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

void writeToFile(struct employee* head){
    
    // Variables for reading from file
    int id;
    int endOfFile;
    char firstName[255];
    char lastName[255];
    char email[255];
    char street[255];
    char city[255];
    char country[255];
    char department[255];
    int date;
    int month;
    int year;
    int salary;
    
    // File Pointer
    FILE *fp;
    
    // Open File for Reading & Writing
    fp = fopen("/Users/johnmalcolm/Documents/C : C++/Advanced_C_Assignement/employees.txt", "w+");
    
    // Creates a pointer to a new node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Assigns contents of head to temp
    temp = head;
    
    // While temps next node is not NULL
    while(temp->next != NULL)
    {
        fprintf(fp, "%d %s %s %s %s %s %s %s %d %d %d %d\n", temp->id, temp->firstName, temp->lastName, temp->email, temp->empAddress.street, temp->empAddress.city, temp->empAddress.country, temp->department, temp->date.date, temp->date.month, temp->date.year, temp->salary);
        
        // Set temp to the next node
        temp = temp->next;
    }
    
    
    fclose(fp);
}