/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : SAHIL HARESHBHAI PATEL
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

#define MININCOME 500.00
#define MAXINCOME 400000.00
#define MAXITEMS 10
#define MINCOST 100.00

int main() {
    double monthlyIncome;
    int numItems;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);
        if (monthlyIncome < MININCOME) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MININCOME);
        }
        else if (monthlyIncome > MAXINCOME) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAXINCOME);
        }
    } while (monthlyIncome < MININCOME || monthlyIncome > MAXINCOME);

    do {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);
        if (numItems < 1 || numItems > MAXITEMS) {
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAXITEMS);
        }
    } while (numItems < 1 || numItems > MAXITEMS);

    double cost[MAXITEMS];
    int priority[MAXITEMS];
    char financeOption[MAXITEMS];

    printf("\n");
    int i;
    for (i = 0; i < numItems; i++) {
        printf("Item-%d Details:\n", i + 1);

        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < MINCOST) {
                printf("      ERROR: Cost must be at least $%.2lf\n", MINCOST);
            }
        } while (cost[i] < MINCOST);

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOption[i]);
            if (financeOption[i] != 'y' && financeOption[i] != 'n') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (financeOption[i] != 'y' && financeOption[i] != 'n');

        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numItems; i++) {
    printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOption[i], cost[i]);
    }

    double totalCost = 0;
    for (i = 0; i < numItems; i++) {
        totalCost += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
