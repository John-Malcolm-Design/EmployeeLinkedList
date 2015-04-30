//
//  readFromFile.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

void readFromFile(struct employee* head){
    
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
    int salary;
    
    // File Pointer
    FILE *fp;
    
    // Open File for Reading & Writing
    fp = fopen("/Users/johnmalcolm/Documents/C : C++/Advanced_C_Assignement/employees_db.txt", "r+");
    
    // Reads in 'line by line' until we reach the end of the file (EOF)
    while (fscanf(fp, "%d", &id) != EOF) {
        fscanf(fp, "%s", firstName);
        fscanf(fp, "%s", lastName);
        fscanf(fp, "%s", email);
        fscanf(fp, "%s", street);
        fscanf(fp, "%s", city);
        fscanf(fp, "%s", country);
        fscanf(fp, "%s", department);
        fscanf(fp, "%d", &date);
        fscanf(fp, "%d", &salary);
        
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
        temp->id = id;
        strcpy( temp->firstName, firstName );
        strcpy( temp->lastName, lastName );
        strcpy( temp->email, email );
        strcpy( temp->empAddress.street, street );
        strcpy( temp->empAddress.city, city );
        strcpy( temp->empAddress.country, country);
        strcpy( temp->department, department);
        temp->date = date;
        temp->salary = salary;
        temp->next= NULL;
        
        // Sets the next node to null for the new node as it is the last node in the list
        newNode->next = NULL;
        
        // Sets next to newNode
        temp->next = newNode;
    }
    
    fclose(fp);
}