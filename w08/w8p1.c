/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
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
#include<stdio.h>
#include "w8p1.h"

// Get user input of int type and validate for a positive non-zero number
int getIntPositive(int* intPositive)
{
	int userEnteredvalue;  // varible to store user entered value

	do //Start of Do-While loop
	{
		scanf("%d", &userEnteredvalue); //Scanning the entereed value

		//If condition to check user enter value is more than zero
		if (userEnteredvalue <= 0)
		{
			//Display error message if user enter value less than 0
			printf("ERROR: Enter a positive value: ");
		}

	} while (userEnteredvalue <= 0); //End of Do-While loop

	//If condition to check value is not zero
	if (intPositive != NULL)
	{
		//assigning value via pointer
		*intPositive = userEnteredvalue;
	}

	return userEnteredvalue;
}

// Get user input of double type and validate for a positive non-zero number
double getDoublePositive(double* doublePositive)
{
	double userEnteredvalue;  // varible to store user entered value

	do //Start of Do-While loop
	{
		scanf("%lf", &userEnteredvalue); //Scanning the entereed value

		//If condition to check user enter value is more than zero
		if (userEnteredvalue <= 0)
		{
			//Display error message if user enter value less than 0
			printf("ERROR: Enter a positive value: ");
		}

	} while (userEnteredvalue <= 0); //End of Do-While loop

	//If condition to check value is not zero
	if (doublePositive != NULL)
	{
		//assigning value via pointer
		*doublePositive = userEnteredvalue;
	}

	return userEnteredvalue;
}

// Opening message
void openingMessage(const int numberOfproducts)
{
	/*Cat food cost Analysis heading and opening messsage*/
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags"
		" of product data for analysis.\n", numberOfproducts);
	printf("NOTE: A 'serving' is %dg\n\n", NUMOFGRAMS);
}

// Get user input for the details of the cat food product

struct catFoodInfo getCatFoodInfo(const int sequence)
{
	struct catFoodInfo catFood;

	//Display sequence number
	printf("Cat Food Product #%d\n", sequence + 1);
	printf("--------------------\n");

	//Display special serial number of product
	printf("SKU           : ");
	getIntPositive(&catFood.skuNumber);

	//Display Price of the product
	printf("PRICE         : $");
	getDoublePositive(&catFood.productPrice);

	//Display weight of the product in pounds
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&catFood.weightInpounds);

	//Displat calories per servings
	printf("CALORIES/SERV.: ");
	getIntPositive(&catFood.calories);

	printf("\n");
	return catFood;
}

// Display the table header
void displayCatFoodHeader()
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

//Display the record of cat food data
void displayCatFoodData
(int skuNumber, double* productPrice, double* weightInpounds, int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n"
		, skuNumber, *productPrice, *weightInpounds, calories);
}

// Logic entry point

void start() // Start od main part
{
	struct catFoodInfo catFood[MAXPRODUCTS];
	int i;

	openingMessage(MAXPRODUCTS);  //calling openingMessage function

	for (i = 0; i < MAXPRODUCTS; i++)  //For loop to display cat food info
	{
		catFood[i] = getCatFoodInfo(i); //calling function getCatFoodInfo
	}

	displayCatFoodHeader();  //calling function to display table header

	for (i = 0; i < MAXPRODUCTS; i++)  //For loop to display cat food data
	{
		/*calling function to display data row*/
		displayCatFoodData
		(catFood[i].skuNumber, &catFood[i].productPrice,
			&catFood[i].weightInpounds, catFood[i].calories);
	}
	printf("\n\n");

}