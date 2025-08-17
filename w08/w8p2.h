/*//////////////////////////////////////////////////////////////////////////
<assessment name example : Workshop - #8 (Part - 2)>

Full Name : Sahil Hareshbhai Patel
Student ID# : 173793225
Email : shpatel27@myseneca.ca
Section : NJJ

Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include<stdio.h>
#define MAXPRODUCTS 3
#define NUMOFGRAMS 64
#define LBS_TO_KG 2.20462

// structures

struct catFoodInfo
{
	int skuNumber;
	double productPrice;
	double weightInpounds;
	int calories;
};

struct ReportData
{
    int skuNumber;
    double productPrice;
    int calPerServe;
    double weightInPounds;
    double weightInKgs;
    int weightInGms;
    double totalserve;
    double costPerServe;
    double CostCalPerServe;

};

// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
int getIntPositive(int*);

// 2. Get user input of double type and validate for a positive non-zero number
double getDoublePositive(double*);

// 3. Opening message
void openingMessage(const int);

// 4. Get user input for the details of cat food product
struct catFoodInfo getCatFoodInfo(const int);

// 5. Display the table header
void displayCatFoodHeader();

// 6. Display the record of cat food data 
void displayCatFoodData(int, double*, double*, int);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double*, double*);

// 9. convert lbs: g
double convertLbsG(const double*, int*);

// 10. convert lbs: kg / g
void convertLbs(const double*, double*, int*);

// 11. calculate: servings based on gPerServ
double calculateTotalServings(const int, const  int, double*);

// 12. calculate: cost per serving
double calculateCostPerServing(const double*, const double*, double*);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double*, const int*, double*);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData, const int);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct catFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start();
