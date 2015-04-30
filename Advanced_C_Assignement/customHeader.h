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

// Date Struct
struct date{
    int month;
    int date;
    int year;
};

// Login Struct
struct login{
    char username[20];
    char password[30];
    struct login *next;
};

// Address Struct
struct address{
    char street[40];
    char city[30];
    char country[30];
};

// Report Struct
struct report{
    char departmentName[20];
    int numberOfEmployees;
    int totalSalary;
    int totalBonus;
    int financialOutlay;
};

// Employee Struct
struct employee{
    int id;
    char firstName[20];
    char lastName[20];
    char email[30];
    struct address empAddress;
    char department[20];
    struct date date;
    int salary;
    struct employee *next;
};

// Function Declarations
void addEmployee();
void menu();
struct report* displayByDepartment();
struct employee* searchEmployee();
void deleteEmployee();
void sortList();
void swap();
void writeToFile();
int searchUser();
void login();

#endif
