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
    const double TAX = 0.13;
    const char pattySize = 'S', sallySize = 'M', tommySize = 'L';
    int pattyShirt, sallyShirt, tommyShirt, rounded, quant;
    float SMALL, MEDIUM, LARGE;
    float subTotal1, subTotal2, subTotal3, total1, total2, total3, taxes1, taxes2, taxes3, subTotal, total, taxes;

    printf("Set Shirt Prices\n================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &SMALL);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &MEDIUM);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &LARGE);

    printf("\nShirt Store Price List\n======================\n");

    printf("SMALL  : $%.2f\n", SMALL);
    printf("MEDIUM : $%.2f\n", MEDIUM);
    printf("LARGE  : $%.2f\n\n", LARGE);

    printf("Patty's shirt size is '%c'\n", pattySize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &pattyShirt);

    printf("\nTommy's shirt size is '%c'\n", tommySize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tommyShirt);

    printf("\nSally's shirt size is '%c'\n", sallySize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &sallyShirt);
    printf("\n");

    subTotal1 = (SMALL * pattyShirt);
    rounded = (subTotal1 + 0.005) * 100;
    subTotal1 = (float)rounded / 100;

    subTotal2 = (MEDIUM * sallyShirt);
    rounded = (subTotal2 + 0.005) * 100;
    subTotal2 = (float)rounded / 100;

    subTotal3 = (LARGE * tommyShirt );
    rounded = (subTotal3 + 0.005) * 100;
    subTotal3 = (float)rounded / 100;


    taxes1 = (subTotal1 * TAX);
    rounded = (taxes1 + 0.005) * 100;
    taxes1 = (float)rounded / 100;

    taxes2 = (subTotal2 * TAX);
    rounded = (taxes2 + 0.005) * 100;
    taxes2 = (float)rounded / 100;

    taxes3 = (subTotal3 * TAX);
    rounded = (taxes3 + 0.005) * 100;
    taxes3 = (float)rounded / 100;



    total1 = (subTotal1 + taxes1);
    rounded = (total1 + 0.005) * 100;
    total1 = (float)rounded / 100;

    total2 = (subTotal2 + taxes2);
    rounded = (total2 + 0.005) * 100;
    total2 = (float)rounded / 100;

    total3 = (subTotal3 + taxes3);
    rounded = (total3 + 0.005) * 100;
    total3 = (float)rounded / 100;

    subTotal = subTotal1 + subTotal2 + subTotal3;
    rounded = (subTotal + 0.005) * 100;
    subTotal = (float)rounded / 100;

    total = total1 + total2 + total3;
    rounded = (total + 0.005) * 100;
    total = (float)rounded / 100;

    taxes = taxes1 + taxes2 + taxes3;
    rounded = (taxes + 0.005) * 100;
    taxes = (float)rounded / 100;

    int numOfShirts;
    numOfShirts = pattyShirt + sallyShirt + tommyShirt;
    float average1;
    average1 = subTotal / numOfShirts;

    float average2;
    average2 = total / numOfShirts;


    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", pattySize, SMALL, pattyShirt, subTotal1, taxes1, total1);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", sallySize, MEDIUM, sallyShirt, subTotal2, taxes2, total2);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tommySize, LARGE, tommyShirt, subTotal3, taxes3, total3);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal, taxes, total);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subTotal);

    quant = subTotal / 2;
    subTotal = subTotal * 100;
    subTotal = (int)subTotal % 200;
    subTotal = subTotal / 100;
    printf("Toonies  %3d %9.4lf\n", quant, subTotal);

    quant = subTotal / 1;
    subTotal = subTotal * 100;
    subTotal = (int)subTotal % 100;
    subTotal = subTotal / 100;
    printf("Loonies  %3d %9.4lf\n", quant, subTotal);

    quant = subTotal / 0.25;
    subTotal = subTotal * 100;
    subTotal = (int)subTotal % 25;
    subTotal = subTotal / 100;
    printf("Quarters %3d %9.4lf\n", quant, subTotal);

    quant = subTotal / 0.10;
    subTotal = subTotal * 100;
    subTotal = (int)subTotal % 10;
    subTotal = subTotal / 100;
    printf("Dimes    %3d %9.4lf\n", quant, subTotal);

    quant = subTotal / 0.05;
    subTotal = subTotal * 100;
    subTotal = (int)subTotal % 5;
    subTotal = subTotal / 100;
    printf("Nickels  %3d %9.4lf\n", quant, subTotal);

    subTotal = subTotal * 100;
    quant = subTotal / 1;
    subTotal = (int)subTotal % 1;
    subTotal = subTotal / 100;
    printf("Pennies  %3d %9.4lf\n", quant, subTotal);


    printf("\nAverage cost/shirt: $%.4f", average1);

    printf("\n\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", total);

    quant = total / 2;
    total = total * 100;
    total = (int)total % 200;
    total = total / 100;
    printf("Toonies  %3d %9.4lf\n", quant, total);

    quant = total / 1;
    total = total * 100;
    total = (int)total % 100;
    total = total / 100;
    printf("Loonies  %3d %9.4lf\n", quant, total);

    quant = total / 0.25;
    total = total * 100;
    total = (int)total % 25;
    total = total / 100;
    printf("Quarters %3d %9.4lf\n", quant, total);

    quant = total / 0.10;
    total = total * 100;
    total = (int)total % 10;
    total = total / 100;
    printf("Dimes    %3d %9.4lf\n", quant, total);

    quant = total / 0.05;
    total = total * 100;
    total = (int)total % 5;
    total = total / 100;
    printf("Nickels  %3d %9.4lf\n", quant, total);

    total = total * 100;
    quant = total / 1;
    total = (int)total % 1;
    total = total / 100;
    printf("Pennies  %3d %9.4lf\n", quant, total);

    printf("\n");

    printf("Average cost/shirt: $%.4f\n", average2);


    return 0;
}