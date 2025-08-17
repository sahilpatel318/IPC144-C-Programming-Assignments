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

#include <stdio.h>
#include "core.h"


void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; 
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    int tempNo; 
    char nChar; 
    while (1)
    {
        scanf("%d%c", &tempNo, &nChar);
        if (nChar == '\n')
        {
            return tempNo;
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
}

int inputIntPositive(void)
{
    int tempNo;
    char nChar;
    while (1)
    {
        scanf("%d%c", &tempNo, &nChar);
        if (nChar == '\n')
        {
            if (tempNo > 0)
            {
                return tempNo;
            }
            else
            {

                printf("ERROR! Value must be > 0: ");
            }
        }
        else
        {
            clearInputBuffer();
            printf("Error! ");
            printf("Input a whole number: ");
        }
    }
}

int inputIntRange(int min, int max)
{
    int tempNo;
    char nChar;
    while (1)
    {
        scanf("%d%c", &tempNo, &nChar);
        if (nChar == '\n')
        {
            if (tempNo >= min && tempNo <= max)
            {
                return tempNo;
            }
            else
            {

                printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
            }
        }
        else
        {
            clearInputBuffer();
            printf("Error! ");
            printf("Input a whole number: ");
        }
    }
}

char inputCharOption(const char* string)
{
    int i, no_characters = 0;
    char temp_character, nChar;
    while (string[no_characters] != '\0')
    {
        no_characters++; 
    }
    while (1)
    {
        scanf("%c%c", &temp_character, &nChar);
        if (nChar == '\n')
        {
            for (i = 0; i < no_characters; i++)
            {
                if (string[i] == temp_character)
                {
                    return temp_character;
                }
            }
        }
        else {
            clearInputBuffer();
        }
        printf("ERROR: Character must be one of [%s]: ", string);
    }
}

void inputCString(char* string, int min, int max)
{
    char temp[256];
    int i, no_characters;
    do
    {
        no_characters = 0;
        scanf("%[^\n]%*c", temp);
        while (temp[no_characters] != '\0')
        {
            no_characters++;
        }
        if (min == max && max != no_characters) {
            printf("ERROR: String length must be exactly %d chars: ", max);
        }
        else if (no_characters > max) {
            printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if (no_characters < min)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
    } while (no_characters < min || no_characters > max);

    for (i = 0; i < no_characters; i++)
    {
        string[i] = temp[i];
    }
}

void displayFormattedPhone(const char* phone_Number)
{
    int i;
    int all_Numbers = 1;
    int no_characters = 0;
    if (phone_Number != NULL)
    {
        while (phone_Number[no_characters] != '\0') {
            if (phone_Number[no_characters] <= '0' || phone_Number[no_characters] >= '9')
            {
                all_Numbers = 0;
            }
            no_characters++;
        }
    }

    if (no_characters != 10 || all_Numbers != 1)
    {
        printf("(___)___-____");
    }
    else
    {
        i = 0;
        printf("(");
        while (i < 3) {
            printf("%c", phone_Number[i]);
            i++;
        }
        printf(")");
        while (i < 6) {
            printf("%c", phone_Number[i]);
            i++;
        }
        printf("-");
        while (i < 10) {
            printf("%c", phone_Number[i]);
            i++;
        }
    }
}