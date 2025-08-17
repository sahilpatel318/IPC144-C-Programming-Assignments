/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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
#include "w8p2.h"

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

	//Display calories per servings
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

// Part-2

// convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* valueInLbs, double* valueInKg)
{
	double result; //declaring double variable to store result
	result = (*valueInLbs) / LBS_TO_KG; //calculating reasult

	// Whether valueINKg is NULL or not
	if (valueInKg != NULL)
	{
		*valueInKg = result;//If it is then store result to it
	}
	return result;  // Returning Result
}

// convert lbs : g(call convertKG, then * 1000)
double convertLbsG(const double* valueInLbs, int* valueInGm)
{
	double result;//declaring double variable to store result

	//converting result into gms
	result = (convertLbsKg(valueInLbs,NULL) * 1000);

	if (valueInGm != NULL)
	{
		*valueInGm = (int)result;
	}
	else
	{
		return (int)result;
	}

	return result;
}

// convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* gm)
{
	*kg = convertLbsKg(lbs, NULL);
	*gm = convertLbsG(lbs, NULL);
}

// calculate: servings based on gPerServ
double calculateServings(const int serveSizeInGm,
	   const  int totalGm, double* numOfServings)
{
	double totalServings;//declaring double variable to store servings

	//calculating total servings
	totalServings = serveSizeInGm / (double)totalGm;

	if (numOfServings != NULL)
	{
		*(numOfServings) = totalServings;
	}
	return totalServings;
}

// calculate: cost per serving
double calculateCostPerServing(const double* productPrice, 
	const double* totalServes, double* costPerServing)
{
	double perServeCost;//declaring double variable to store per serve cost

	//calculating per serving cost
	perServeCost = *(productPrice) / *(totalServes);

	if (costPerServing != NULL)
	{
		*(costPerServing) = perServeCost;
	}

	return perServeCost;
}

// calculate: cost per calorie
double calculateCostPerCal(const double* costPerServing,
	const int* calPerServing, double* costPerCal)
{
	double perCalCost;//declaring double variable to store per calorie cost

	//calculating per calorie cost
	perCalCost = (*costPerServing) / (double)(*calPerServing);

	if (costPerCal != NULL)
	{	
		*costPerCal = perCalCost;
	}

	return perCalCost;
}

// Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct catFoodInfo catFood)
{
	struct ReportData reportData;

	reportData.skuNumber = catFood.skuNumber;
	reportData.productPrice = catFood.productPrice;
	reportData.weightInPounds = catFood.weightInpounds;
	reportData.calPerServe = catFood.calories;
	reportData.weightInKgs = 
		convertLbsKg(&reportData.weightInPounds, NULL);
	reportData.weightInGms = 
		convertLbsG(&reportData.weightInPounds, NULL);
	reportData.totalserve = 
		calculateServings(reportData.weightInGms, NUMOFGRAMS, NULL);
	reportData.costPerServe = calculateCostPerServing(&reportData.productPrice,
		&reportData.totalserve, NULL);

	reportData.CostCalPerServe = calculateCostPerCal(&reportData.costPerServe,
		&reportData.calPerServe, NULL);

	return reportData;
}

// Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUMOFGRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapestProduct)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		reportData.skuNumber, reportData.productPrice,
		reportData.weightInPounds, reportData.weightInKgs, 
		reportData.weightInGms, reportData.calPerServe, 
		reportData.totalserve, reportData.costPerServe, 
		reportData.CostCalPerServe);

	if (cheapestProduct == 1)
	{
		printf(" ***");
	}
	printf("\n");
}

// Display the findings (cheapest)
void displayFinalAnalysis(const struct catFoodInfo catFood)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");

	printf("Based on the comparison data, the PURRR-fect economical option is:\n"
		"SKU:%07d Price: $%.2lf\n\n", catFood.skuNumber, catFood.productPrice);

	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------


// Logic entry point
void start() // Start of main part
{
	struct catFoodInfo catFood[MAXPRODUCTS];
	struct ReportData dataReport[MAXPRODUCTS];
	double cheapestProduct = 1000.00;
	int cheapestProd[MAXPRODUCTS];
	int i;
	int chepestProductNum;

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
	printf("\n");

	//Calling function to display report header
	displayReportHeader();

	for (i = 0; i < MAXPRODUCTS; i++)
	{
		dataReport[i] = calculateReportData(catFood[i]);
	}


	for (i = 0; i < MAXPRODUCTS; i++)
	{
		if (dataReport[i].costPerServe < cheapestProduct)
		{
			cheapestProduct = dataReport[i].costPerServe;
			chepestProductNum = i;
		}
	}
	cheapestProd[chepestProductNum] = 1;

	for (i = 0; i < MAXPRODUCTS; i++)
	{
		displayReportData(dataReport[i], cheapestProd[i]);
	}


	displayFinalAnalysis(catFood[chepestProductNum]);
}