#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// defining all variables
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    // intializing all variables
    const int JAN = 1, DEC = 12;
    int years, months;

    // printing header lines
    printf("General Well-being Log\n");
    printf("======================\n");

    years = 0;
    months = 0;

    // intialization of while loop
    while ((years < MIN_YEAR || years > MAX_YEAR) || (months < JAN || months > DEC))
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &years, &months);

        // start of if loop
        if (years < MIN_YEAR || years > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        //another if loop
        if (months < JAN || months > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    }
    printf("\n");
    printf("*** Log date set! ***\n\n");
    printf("Log starting date: %d-", years);
    switch (months)

        // switch case all inputs
    {
    case 1: printf("JAN-01"); break;
    case 2: printf("FEB-01"); break;
    case 3: printf("MAR-01"); break;
    case 4: printf("APR-01"); break;
    case 5: printf("MAY-01"); break;
    case 6: printf("JUN-01"); break;
    case 7: printf("JUL-01"); break;
    case 8: printf("AUG-01"); break;
    case 9: printf("SEP-01"); break;
    case 10: printf("OCT-01"); break;
    case 11: printf("NOV-01"); break;
    case 12: printf("DEC-01"); break;
    }
    printf("\n");

    return 0;
}
