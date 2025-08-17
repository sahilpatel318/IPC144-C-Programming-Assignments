#pragma once
/*************************************************************************
                <assessment name example: Assignment 1 MS-1 >
Full Name   : Sahil Hareshbhai Patel
Student ID# : 173793225
Email       : shpatel27@myseneca.ca
Section     : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
**************************************************************************/

// get integer as input from user
int inputInt(void);

// get positive integer from user
int inputIntPositive(void);

//get input that is between min value and max value form user
int inputIntRange(int min, int max);

//get character input from user
char inputCharOption(const char* string);

//get string input from user
void inputCString(char* strng, int min, int max);

//display Phone (formatted)
void displayFormattedPhone(const char* phone_Number);

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void); 
