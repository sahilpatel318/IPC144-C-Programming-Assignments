
/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Sahil Hareshbhai Patel
Student ID#: 173793225
Email      : shpatel27@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) 
{


    // Defining all variables and intializing all variables
    int apples, oranges, pears, tomatoes, cabbages;
    int picked, continueShopping = 1;

    // Defining start of the loop
    while (continueShopping) {

        printf("Grocery Shopping\n");
        printf("================\n");


        // defining loop for apples
        while (1 < 2) {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples >= 0) {
                printf("\n");
                break;
            }
            printf("ERROR: Value must be 0 or more.\n");
        }


        // defining loop for oranges
        while (1 < 2) {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges >= 0) {
                printf("\n");
                break;
            }
            printf("ERROR: Value must be 0 or more.\n");
        }

        // defining loop for pears
        while (1 < 2) {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears >= 0) {
                printf("\n");
                break;
            }
            printf("ERROR: Value must be 0 or more.\n");
        }

        // defining loop for tomatoes
        while (1 < 2) {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes >= 0) {
                printf("\n");
                break;
            }
            printf("ERROR: Value must be 0 or more.\n");
        }

        // defining loop for cabbages
        while (1 < 2) {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages >= 0) {
                printf("\n");
                break;
            }
            printf("ERROR: Value must be 0 or more.\n");
        }

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        // Picking stage for APPLES
        if (apples > 0) {
            while (apples > 0) {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &picked);
                if (picked <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked > apples) {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                }
                else {
                    apples -= picked;
                    if (apples > 0) {
                        printf("Looks like we still need some APPLES...\n");
                    }
                    else {
                        printf("Great, that's the apples done!\n\n");
                    }
                }
            }
        }

        // Picking stage for ORANGES
        if (oranges > 0) {
            while (oranges > 0) {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &picked);
                if (picked <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked > oranges) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                }
                else {
                    oranges -= picked;
                    if (oranges > 0) {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                    else {
                        printf("Great, that's the oranges done!\n\n");
                    }
                }
            }
        }

        // Picking stage for PEARS
        if (pears > 0) {
            while (pears > 0) {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &picked);
                if (picked <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked > pears) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                }
                else {
                    pears -= picked;
                    if (pears > 0) {
                        printf("Looks like we still need some PEARS...\n");
                    }
                    else {
                        printf("Great, that's the pears done!\n\n");
                    }
                }
            }
        }

        // Picking stage for TOMATOES
        if (tomatoes > 0) {
            while (tomatoes > 0) {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &picked);
                if (picked <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked > tomatoes) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else {
                    tomatoes -= picked;
                    if (tomatoes > 0) {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                    else {
                        printf("Great, that's the tomatoes done!\n\n");
                    }
                }
            }
        }

        // Picking stage for CABBAGES
        if (cabbages > 0) {
            while (cabbages > 0) {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &picked);
                if (picked <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked > cabbages) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                }
                else {
                    cabbages -= picked;
                    if (cabbages > 0) {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                    else {
                        printf("Great, that's the cabbages done!\n\n");
                    }
                }
            }
        }

        printf("All the items are picked!\n\n");

        // Asking if the user wants to do another shopping session
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continueShopping);
        printf("\n");
    }

    // final geeting statement
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}

