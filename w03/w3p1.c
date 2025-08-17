/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  :SAHIL HARESHBHAI PATEL
Student ID#:1737
Email      :shpatel27@myseneca.ca
Section    :NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    // defining all elements 
    int Productid1 = 111;
    char Producttaxes1 = 'Y';
    double product1price = 111.4900;
    int Productid2 = 222;
    char Producttaxes2 = 'N';
    double product2price = 222.9900;
    int Productid3 = 111;
    char Producttaxes3 = 'N';
    double product3price = 334.4900;
    double testValue = 330.99;

    // calculation
    double pricedifference = product3price - product2price;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", Productid1);
    printf("  Taxed: %c\n", Producttaxes1);
    printf("  Price: $%.4lf\n\n", product1price);
    printf("Product-2 (ID:%d)\n", Productid2);
    printf("  Taxed: %c\n", Producttaxes2);
    printf("  Price: $%.4lf\n\n", product2price);
    printf("Product-3 (ID:%d)\n", Productid3);
    printf("  Taxed: %c\n", Producttaxes3);
    printf("  Price: $%.4lf\n\n", product3price);
    printf("The average of all prices is: $%.4lf\n\n", (product1price + product2price + product3price) / 3.0);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", Producttaxes1 == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", Producttaxes2 == 'N' && Producttaxes3 == 'N');
    printf("3. Is product 3 less than testValue ($%.2f)? -> %d\n\n", testValue, product3price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", product3price > (product1price + product2price));
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", product1price >= product3price - product2price, pricedifference);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", product2price >= (product1price + product2price + product3price) / 3.0);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", Productid1 != Productid2 && Productid1 != Productid3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", Productid2 != Productid1 && Productid2 != Productid3);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", Productid3 != Productid1 && Productid3 != Productid2);
    return 0;
}