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
    
    int id = 0;
//    char firstName[255];
//    char lastName[255];
//    char email[255];
//    char street[255];
//    char city[255];
//    char country[255];
//    char department[255];
//    int date;
//    int salary;
    
    // Creates a pointer to a new node
    struct employee *temp;
    
    // Allocate and assign memory for the new node
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Assigns contents of head to temp
    temp = head;
    
    // While temps next node is not NULL
    while(temp->next != NULL)
    {
        id = temp->id;
        // Set temp to the next node
        temp = temp->next;
    }
    // Creates a pointer to a new node
    struct employee *newNode;
    
    // Allocate and assign memory for the new node
    newNode = (struct employee*)malloc(sizeof(struct employee));
    
    // Get data for new node from user
    printf("\nEnter data for this node: \n");
    temp->id = ++id;
    
    // Firstname
    printf("Enter first name: ");
    scanf("%s", &temp->firstName);
    
    // Surname
    printf("Enter last name: ");
    scanf("%s", &temp->lastName);
    
    // Email
    printf("Enter email: ");
    scanf("%s", &temp->email);
    
    // Employee Address Below
    // Street
    printf("\nAddress: \n");
    printf("Enter house number and street name (Use underscores instead of spaces!): ");
    scanf("%s", &temp->empAddress.street);
    
    // City
    printf("Enter city/town: ");
    scanf("%s", &temp->empAddress.city);
    
    // Country
    printf("Enter country: ");
    scanf("%s", &temp->empAddress.country);
    
    // Department
    printf("Enter department: ");
    scanf("%s", &temp->department);
    
    // Date
    printf("Enter Date: (DDMMYYYY - Numbers Only!)");
    scanf("%d", &temp->date);
    
    // Salary
    printf("Enter Salary: ");
    scanf("%d", &temp->salary);
    
    // Sets next node to NULL
    temp->next= NULL;
    
    // Sets the next node to null for the new node as it is the last node in the list
    newNode->next = NULL;
    
    // Sets next to newNode/
    temp->next = newNode ;
};