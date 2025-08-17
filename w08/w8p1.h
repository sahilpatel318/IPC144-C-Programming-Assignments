/*//////////////////////////////////////////////////////////////////////////
<assessment name example : Workshop - #8 (Part - 1)>

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

// structures

struct catFoodInfo
{
	int skuNumber;
	double productPrice;
	double weightInpounds;
	int calories;
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

// 7. Logic entry point
void start();