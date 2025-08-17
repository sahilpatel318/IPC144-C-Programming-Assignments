/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

int main()
{
    // defining all characters and variables
    char coffeetypeno1, coffeetypeno2, coffeetypeno3;
    int weightofbagno1, weightofbagno2, weightofbagno3;
    char coffeecreamtypeno1, coffeecreamtypeno2, coffeecreamtypeno3;
    char strengthofcoffee, userofcoffeecream;
    int dailyservings;
    double GRAM_IN_LBS = 0.00220462;

    // Getting values from the user according to their need
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeetypeno1);
    printf("Bag weight (g): ");
    scanf("%d", &weightofbagno1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeecreamtypeno1);
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeetypeno2);
    printf("Bag weight (g): ");
    scanf("%d", &weightofbagno2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeecreamtypeno2);
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeetypeno3);
    printf("Bag weight (g): ");
    scanf("%d", &weightofbagno3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeecreamtypeno3);

    // printing table according the given inputs
    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeetypeno1 == 'L' || coffeetypeno1 == 'l'), (coffeetypeno1 == 'M' || coffeetypeno1 == 'm'),
        (coffeetypeno1 == 'R' || coffeetypeno1 == 'r'), weightofbagno1, weightofbagno1 * GRAM_IN_LBS, (coffeecreamtypeno1 == 'Y' || coffeecreamtypeno1 == 'y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeetypeno2 == 'L' || coffeetypeno2 == 'l'), (coffeetypeno2 == 'M' || coffeetypeno2 == 'm'),
        (coffeetypeno2 == 'R' || coffeetypeno2 == 'r'), weightofbagno2, weightofbagno2 * GRAM_IN_LBS, (coffeecreamtypeno2 == 'Y' || coffeecreamtypeno2 == 'y'));

    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeetypeno3 == 'L' || coffeetypeno3 == 'l'), (coffeetypeno3 == 'M' || coffeetypeno3 == 'm'),
        (coffeetypeno3 == 'R' || coffeetypeno3 == 'r'), weightofbagno3, weightofbagno3 * GRAM_IN_LBS, (coffeecreamtypeno3 == 'Y' || coffeecreamtypeno3 == 'y'));

    // adding more inputs and scan the entered values
    printf("\nEnter how you like your coffee...\n");
    printf("\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strengthofcoffee);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &userofcoffeecream);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyservings);

    // printing table values by processing the given inputs
    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeetypeno1 == 'L' || coffeetypeno1 == 'l') == (strengthofcoffee == 'L' || strengthofcoffee == 'l')), (weightofbagno1 == 250 && dailyservings >= 1 && dailyservings <= 4),
        ((coffeecreamtypeno1 == 'Y' || coffeecreamtypeno1 == 'y') == (userofcoffeecream == 'Y' || userofcoffeecream == 'y')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeetypeno2 == 'R' || coffeetypeno2 == 'r') == (strengthofcoffee == 'R' || strengthofcoffee == 'r')), (weightofbagno2 == 500 && dailyservings >= 5 && dailyservings <= 9),
        ((coffeecreamtypeno2 == 'Y' || coffeecreamtypeno2 == 'y') == (userofcoffeecream == 'Y' || userofcoffeecream == 'y')));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeetypeno3 == 'M' || coffeetypeno3 == 'm') == (strengthofcoffee == 'M' || strengthofcoffee == 'm')), (weightofbagno3 == 1000 && dailyservings >= 10),
        ((coffeecreamtypeno3 == 'Y' || coffeecreamtypeno3 == 'y') == (userofcoffeecream == 'Y' || userofcoffeecream == 'y')));

    // adding more inputs and scan the entered values
    printf("\nEnter how you like your coffee...\n");
    printf("\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strengthofcoffee);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &userofcoffeecream);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyservings);

    // printing table values by processing the given inputs
    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeetypeno1 == 'L' || coffeetypeno1 == 'l') == (strengthofcoffee == 'L' || strengthofcoffee == 'l')), (weightofbagno1 == 250 && dailyservings >= 1 && dailyservings <= 4),
        ((coffeecreamtypeno1 == 'Y' || coffeecreamtypeno1 == 'y') == (userofcoffeecream == 'Y' || userofcoffeecream == 'y')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeetypeno2 == 'R' || coffeetypeno2 == 'r') == (strengthofcoffee == 'R' || strengthofcoffee == 'r')), (weightofbagno2 == 500 && dailyservings >= 5 && dailyservings <= 9),
        ((coffeecreamtypeno2 == 'Y' || coffeecreamtypeno2 == 'y') == (userofcoffeecream == 'Y' || userofcoffeecream == 'y')));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeetypeno3 == 'M' || coffeetypeno3 == 'm') == (strengthofcoffee == 'M' || strengthofcoffee == 'm')), (weightofbagno3 == 1000 && dailyservings >= 10),
        ((coffeecreamtypeno3 == 'Y' || coffeecreamtypeno3 == 'y') == (userofcoffeecream == 'Y' || userofcoffeecream == 'y')));


    // printing final thank you messeage
    printf("\nHope you found a product that suits your likes!\n");
    return 0;
}