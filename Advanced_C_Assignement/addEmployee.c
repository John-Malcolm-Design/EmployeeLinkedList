//
//  addEmployee.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

// Adds an employee to the LinkedList
void addEmployee(struct employee* head) {
    
    // Initializes Id
    int id = 0;
    
    // Creates a pointer to a new employee
    struct employee *temp;
    
    // Allocate and assign memory for the new employee
    temp =(struct employee*)malloc(sizeof(struct employee));
    
    // Assigns contents of head to temp
    temp = head;
    
    // While temps next employee is not NULL
    while(temp->next != NULL)
    {
        id = temp->id;
        // Set temp to the next employee
        temp = temp->next;
    }
    // Creates a pointer to a new node
    struct employee *newNode;
    
    // Allocate and assign memory for the new employee
    newNode = (struct employee*)malloc(sizeof(struct employee));
    
    // Get data for new employee from user
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
    printf("Enter department (Either: Sales, IT, Legal or HR) : ");
    scanf("%s", &temp->department);
    
    // Date
    printf("Enter Start Date:\n");
    
    // Day
    printf("Day: (DD)");
    scanf("%d", &temp->date.date);
    
    // Month
    printf("Month: (MM)");
    scanf("%d", &temp->date.month);
    
    // Year
    printf("Year: (YYYY)");
    scanf("%d", &temp->date.year);
    
    // Salary
    printf("Enter Salary: ");
    scanf("%d", &temp->salary);
    
    // Sets next node to NULL
    temp->next= NULL;
    
    // Sets the next node to null for the new node as it is the last node in the list
    newNode->next = NULL;
    
    // Sets next to newNode/
    temp->next = newNode ;
    
    writeToFile(head);
    
};