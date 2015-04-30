//
//  main.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

int main(int argc, const char * argv[]) {
    
    // Calls Login function
    login();
    
    // Node initialization & Memory allocation
    struct employee *head = NULL;
    head = (struct employee*)malloc(sizeof(struct employee));
    
    // Reads data from the file and appends onto LinkedList
    readFromFile(head);
    
    // Displays the menu
    menu(head);
    
}
