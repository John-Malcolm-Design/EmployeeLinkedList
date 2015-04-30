//
//  main.c
//  Advanced_C_Assignement
//
//  Created by John Malcolm Anderson on 20/04/2015.
//  Copyright (c) 2015 John Malcolm Anderson. All rights reserved.
//

#include "customHeader.h"

int main(int argc, const char * argv[]) {
    
    // Node initialization & Memory allocation
    struct employee *head = NULL;
    head = (struct employee*)malloc(sizeof(struct employee));
    
    // Reads data from the file and appends onto LinkedList
    readFromFile(head);
    
    // Displays the menu
    menu(head);

}


// HOW TO PUT DATA IN NODES

//    // Initialize data and next properties of the billy Node.
//    temp->id = 0002;
//    strcpy( temp->firstName, "Charles" );
//    strcpy( temp->lastName, "Mahony" );
//    strcpy( temp->email, "charlieboy12@yahoo.com" );
//    strcpy( temp->empAddress.street, "12 Newcastle Rd" );
//    strcpy( temp->empAddress.city, "Galway" );
//    strcpy( temp->empAddress.country, "Ireland");
//    strcpy( temp->department, "Sales");
//    temp->date = 12042019;
//    temp->salary = 50000;
//    temp->next= NULL;


