/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P1)
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

int main(void)
{
	{
		//defining character
		char TypeofLoop;
		//defining integer
		int number, i;


		// printing the instructions for the use
		printf("+----------------------+\n");
		printf("Loop application STARTED\n");
		printf("+----------------------+\n");

		// first do while loop defining
		do {
			printf("\n");
			printf("D = do/while | W = while | F = for | Q = quit\n");
			printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
			scanf (" %c%d", &TypeofLoop, &number);

			// switch case loop defining and demostration
			switch (TypeofLoop) {
			case 'D':
				if (number >= 3 && number <= 20) {
					printf("DO-WHILE: ");
					i = 0;

					// do while loop initialization
					do {
						printf("%c", TypeofLoop);
						i++;

					} while (i < number);
					printf("\n");
				}

				// else loop printing the exit message
				
				else {
					printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
				}
				break;

				// defining case loop statement
			case 'W':

				// defining if else loop
				if (number >= 3 && number <= 20) {
					printf("WHILE   : ");

					i = 0;
					while (i < number) {
						printf("%c", TypeofLoop);
						i++;
					}
					printf("\n");
				}

				// exit from the loop
				else {
					printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
				}


				break;
			case 'F':
				if (number >= 3 && number <= 20) {
					printf("FOR     : ");
					for (i = 0; i < number; i++) {
						printf("%c", TypeofLoop);
					}
					printf("\n");
				}
				else {
					printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
				}

				break;
			case 'Q':

				if (number != 0) {
					printf("ERROR: To quit, the number of iterations should be 0!\n");
				}

				// getting out from switch case
				break;

				// general message if input is out of contex data
			default:
				printf("ERROR: Invalid entered value(s)!\n");

			}


		} while (TypeofLoop != 'Q' || number != 0);

		// printing the last instructions for user
		printf("\n");
		printf("+--------------------+\n");
		printf("Loop application ENDED\n");
		printf("+--------------------+\n");



		return 0;
	}
}