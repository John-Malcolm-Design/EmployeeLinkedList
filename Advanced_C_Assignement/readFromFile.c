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
        
        
        printf("\nID: %d\nName: %s %s\nEmail: %s\nAddress: %s, %s, %s\nDepartment: %s\nDate: %d\nSalary: %d\n", id, firstName, lastName, email, street, city, country, department, date, salary);
    }
    
    fclose(fp);
}