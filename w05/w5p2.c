/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Sahil Patel
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month, flag = 0, i = 1;
    double mRating, eRating, mSum = 0, eSum = 0, etotal;

    printf("General Well-being Log");
    printf("\n======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d%*c", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month < JAN || month > DEC) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        if (year >= MAX_YEAR && year <= MIN_YEAR && month >= JAN && month <= DEC) {
            flag = 1;
        }
    } while ((((year < MIN_YEAR) || (year > MAX_YEAR)) || ((month < JAN) || (month > DEC))) && (flag != 1));

    flag = 0;

    printf("\n*** Log date set! ***\n");


    for (i = 1; i <= 3; i++) {
        if (month == 1) {
            printf("\n%d-JAN-0%d\n", year, i);
        }
        else if (month == 2) {
            printf("\n%d-FEB-0%d\n", year, i);
        }
        else if (month == 3) {
            printf("\n%d-MAR-0%d\n", year, i);
        }
        else if (month == 4) {
            printf("\n%d-APR-0%d\n", year, i);
        }
        else if (month == 5) {
            printf("\n%d-MAY-0%d\n", year, i);
        }
        else if (month == 6) {
            printf("\n%d-JUN-0%d\n", year, i);
        }
        else if (month == 7) {
            printf("\n%d-JUL-0%d\n", year, i);
        }
        else if (month == 8) {
            printf("\n%d-AUG-0%d\n", year, i);
        }
        else if (month == 9) {
            printf("\n%d-SEP-0%d\n", year, i);
        }
        else if (month == 10) {
            printf("\n%d-OCT-0%d\n", year, i);
        }
        else if (month == 11) {
            printf("\n%d-NOV-0%d\n", year, i);
        }
        else {
            printf("\n%d-DEC-0%d\n", year, i);
        }



        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &mRating);
            if (mRating < 0.0 || mRating > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else {
                mSum = mSum + mRating;
                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eRating);
                    if (eRating < 0.0 || eRating > 5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eSum = eSum + eRating;
                        flag = 1;
                    }
                } while (eRating < 0.0 || eRating > 5.0);
            }
        } while ((((mRating < 0.0) || (mRating > 5.0)) || ((eRating < 0.0) || (eRating > 5.0))) && (flag != 1));

    }

    printf("\nSummary");
    printf("\n=======");
    printf("\nMorning total rating: %.3lf", mSum);
    printf("\nEvening total rating:  %.3lf", eSum);
    printf("\n----------------------------");
    etotal = mSum + eSum;
    printf("\nOverall total rating: %.3lf", etotal);
    printf("\n\nAverage morning rating:  %.1lf", mSum / 3);
    printf("\nAverage evening rating:  %.1lf", eSum / 3);
    printf("\n----------------------------");
    printf("\nAverage overall rating:  %.1lf\n", etotal / 6);

    return 0;
}