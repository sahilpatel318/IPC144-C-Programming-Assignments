/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P2)
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

// Defining all different variables
#define MONTHLYINCOME_MINIMUM 500.00
#define MONTHLYINCOME_MAXIMUM 400000.00
#define MINIMUM_COST 100.00
#define MINIMUM_ITEMS 1
#define MAXIMUM_ITEMS 10
#define MINIMUM_IMP_ITEMS 1
#define MAXIMUM_IMP_ITEMS 3
#define SEL_MINIMUM 0
#define SEL_MAXIMUM 2
#define MONTH 12

int main(void)
{
	char opt[MAXIMUM_ITEMS];
	int i, item, imp[MAXIMUM_ITEMS], yes;
	int menu, remMonth, flag = 1, MonthTotal, byPri;
	double income, remAmount, total = 0, cost[MAXIMUM_ITEMS], TotalPri = 0;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");


	// start of do loop
	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);

		// initialization of if else if loop

		if (income < MONTHLYINCOME_MINIMUM)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		else if (income > MONTHLYINCOME_MAXIMUM)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}
		printf("\n");

		// initialization of while loop 
	} while (income < MONTHLYINCOME_MINIMUM || income > MONTHLYINCOME_MAXIMUM);

	do
	{
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &item);

		if (item < MINIMUM_ITEMS || item > MAXIMUM_ITEMS)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
		printf("\n");
	} while (item < MINIMUM_ITEMS || item > MAXIMUM_ITEMS);


	// intialization of for loop

	for (i = 1; i <= item; i++)
	{
		printf("Item-%d Details:\n", i);
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);

			if (cost[i] < MINIMUM_COST)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (cost[i] < MINIMUM_COST);

		// initialization of do while loop
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &imp[i]);

			if (imp[i] < MINIMUM_IMP_ITEMS || imp[i] > MAXIMUM_IMP_ITEMS)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (imp[i] < MINIMUM_IMP_ITEMS || imp[i] > MAXIMUM_IMP_ITEMS);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &opt[i]);

			if (opt[i] != 'n' && opt[i] != 'y')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (opt[i] != 'n' && opt[i] != 'y');
		printf("\n");
	}

	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	// printing output statements
	for (i = 1; i <= item; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i, imp[i], opt[i], cost[i]);
		total += cost[i];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total);


	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &menu);

		if (menu < SEL_MINIMUM || menu > SEL_MAXIMUM)
		{
			printf("\nERROR: Invalid menu selection.\n\n");
		}
		else if (menu == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", total);
			MonthTotal = total / income;
			remAmount = total - (MonthTotal * income);
			remMonth = (remAmount / income) + 1;
			MonthTotal += remMonth;
			printf("Forecast: %d years, %d months\n", MonthTotal / MONTH, MonthTotal % MONTH);
			yes = 0;
			for (i = 0; i <= item; i++)
			{
				if (opt[i] == 'y')
				{
					yes = 1;
				}
			}
			if (yes == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");
		}
		else if (menu == 2)
		{
			do
			{
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &byPri);
				if (byPri < MINIMUM_IMP_ITEMS || byPri > MAXIMUM_IMP_ITEMS)
				{
					printf("ERROR: Value must be between 1 and 3\n");
				}
			} while (byPri < MINIMUM_IMP_ITEMS || byPri > MAXIMUM_IMP_ITEMS);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", byPri);
			for (i = 0; i <= item; i++)
			{
				if (imp[i] == byPri)
				{
					TotalPri += cost[i];
				}
			}

			// calculation part


			MonthTotal = TotalPri / income;
			remAmount = TotalPri - (MonthTotal * income);
			remMonth = (remAmount / income) + 1;
			MonthTotal += remMonth;
			printf("Amount:   $%.2lf\n", TotalPri);
			TotalPri = 0;
			printf("Forecast: %d years, %d months\n", MonthTotal / MONTH, MonthTotal % MONTH);
			yes = 0;
			for (i = 0; i <= item; i++)
			{
				if (imp[i] == byPri)
				{
					if (opt[i] == 'y')
					{
						yes = 1;
					}
				}
			}
			if (yes == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");
		}
		else
		{
			flag = 0;
		}
	} while (flag == 1);

	// final printing output
	printf("\nBest of luck in all your future endeavours!\n");


	return 0;

}

