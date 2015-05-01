//
//  login.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 30/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

void login(){
    
    // File Pointer
    FILE *login;
    
    // Open File for Reading & Writing
    login = fopen("/Users/johnmalcolm/Documents/C : C++/Advanced_C_Assignement/login.txt", "r+");
    
    // Node initialization & Memory allocation
    struct login *LoginHead = NULL;
    LoginHead = (struct login*)malloc(sizeof(struct login));
    
    char username[20];
    char password[20];
    
    // Gets username and password and loops until end of file
    while (fscanf(login, "%s", username) != EOF) {
        
        // Gets password
        fscanf(login, "%s", password);
        
        // Creates a pointer to a new node
        struct login *tempLogin;
        
        // Allocate and assign memory for the new node
        tempLogin = (struct login*)malloc(sizeof(struct login));
        
        // Assigns contents of head to temp
        tempLogin = LoginHead;
        
        // While temps next node is not NULL
        while(tempLogin->next != NULL)
        {
            // Set temp to the next node
            tempLogin = tempLogin->next;
        }
        
        // Creates a pointer to a new node
        struct employee *newNodeLogin;
        
        // Allocate and assign memory for the new node
        newNodeLogin = (struct login*)malloc(sizeof(struct login));
        
        // Get data for new node from file
        strcpy( tempLogin->username, username );
        strcpy( tempLogin->password, password );
        tempLogin->next= NULL;
        
        // Sets the next node to null for the new node as it is the last node in the list
        newNodeLogin->next = NULL;
        
        // Sets next to newNode
        tempLogin->next = newNodeLogin;
    }
    
    // Variables for user input
    char usernameChoice[20];
    char passwordChoice[20];
    int loginIncorrect;
    
    do {
        // If the login is incorrect displays message
        if (loginIncorrect == 1) {
            printf("\nIncorrect Credentials!");
        }
        
        // Prompts user for username and password
        printf("\nEnter Username: ");
        scanf("%s", usernameChoice);
        printf("Enter Password: ");
        scanf("%s", passwordChoice);
        
        // Sets login to incorrect
        loginIncorrect = 1;
        
    // Runs until the username and password match a node in the login LinkedList
    } while (searchUser(LoginHead, usernameChoice, passwordChoice) != 1);
    
    // Close file
    fclose(login);
}