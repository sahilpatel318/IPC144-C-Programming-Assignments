/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
int main(void)
{
    // define all characters
    int shirts;
    const double tax = 0.13;
    const char patSize = 'S';
    double smallshirt, mediumshirt, largeshirt, subtotal, taxes, total;

    printf("Set Shirt Prices\n");
    printf("================\n");

    // Getting print all details and scan all the input values
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallshirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumshirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largeshirt);
    printf("\nShirt Store Price List\n");
    printf("======================\n");

    // getting print all values 
    printf("SMALL  : $%.2lf\n", smallshirt);
    printf("MEDIUM : $%.2lf\n", mediumshirt);
    printf("LARGE  : $%.2lf\n\n", largeshirt);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirts);
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", shirts);

    //calculation for Taxes
    subtotal = shirts * smallshirt;
    taxes = subtotal * tax;
    total = subtotal + taxes;

    //calculations
    subtotal = (subtotal * 100) + 0.5;
    subtotal = (double)((int)subtotal);
    subtotal /= 100;

    taxes = (taxes * 100) + 0.5;
    taxes = (double)((int)taxes);
    taxes /= 100;

    total = (total * 100) + 0.5;
    total = (double)((int)total);
    total /= 100;

    // Print of final output 
    printf("Sub-total: $%8.4lf\n", subtotal);
    printf("Taxes    : $%8.4lf\n", taxes);
    printf("Total    : $%8.4lf\n", total);


    return 0;
}