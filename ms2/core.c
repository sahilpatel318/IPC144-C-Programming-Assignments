/*/////////////////////////////////////////////////////////////////////////
                        <assessment name example: Assignment 1 MS-1 >
Full Name  : Sahil Hareshbhai Patel
Student ID#: 173793225
Email      : shpatel27@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// get an integer
int inputInt() {

    char newLine;
    int value;
    while (1) {
        scanf("%d%c", &value, &newLine);
        if (newLine == '\n') {
            return value;
        }
        else {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    }
}


// get a positive integer
int inputIntPositive() {
    int value;

    do {
        value = inputInt();
        if (value <= 0) {
            clearInputBuffer();
            printf("ERROR! Value must be > 0: ");
            
        }
    } while (value <= 0);
    return value;
}

// get a positive integer input in a given range
int inputIntRange(int start, int end) {
    int value;
    do {
        value = inputInt();
        if ((value < start) || (value > end)) {
            printf("ERROR! Value must be between %d and %d inclusive: ", start, end);
        }
    } while ((value < start) || (value > end));
    return value;
}

// get a choice from user
char inputCharOption(char choices[]) {
    char value;
    while (1) {
        scanf("%c", &value);
        clearInputBuffer();
        int i;
        for (i = 0; choices[i] != '\0'; i++) {
            if (choices[i] == value) {
                return value;
            }
        }
        printf("ERROR: Character must be one of [%s]: ", choices);
    }
}

// get string in a perticular length range
void inputCString(char* string, int min, int max) {

    int length;
    do {
        scanf("%[^\n]", string);

        length = strlen(string);

        if (length < min) {
            if (min == max) {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
        else if (length > max) {
            if (min == max) {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
        }
        clearInputBuffer();
    } while ((length < min) || (length > max));
}

// displaly the given phone number in a perticular format
void displayFormattedPhone(const char* number) {
    int length = 0;
    int flag = 1;
    char formattedNum[14] = { '\0' };
    if (number != NULL) {

        while (number[length] != '\0' && flag) {
            if (number[length] >= '0' && number[length] <= '9')
            {
                length++;
            }
            else {
                length = 0;
                flag = 0;
            }
        }
    }

    if (length != 10) {
        strcpy(formattedNum, "(___)___-____");
      
    }
    else {
        int pointer = 0;
        int i;
        for (i = 0; i < 10; i++) {

            if (i == 0) {
                formattedNum[pointer] = '(';
                pointer += 1;
                formattedNum[pointer] = number[i];
                pointer += 1;
            }
            else if (i == 2) {
                formattedNum[pointer] = number[i];
                pointer += 1;
                formattedNum[pointer] = ')';
                pointer += 1;
            }
            else if (i == 5) {
                formattedNum[pointer] = number[i];
                pointer += 1;
                formattedNum[pointer] = '-';
                pointer += 1;
            }
            else {
                formattedNum[pointer] = number[i];
                pointer += 1;
            }
        }
    }
    printf("%s", formattedNum);
}