/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  :Sahil Hareshbhai Patel
Student ID#:173793225
Email      :shpatel27@myseneca.ca
Section    :NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

#define MAX_PATH_LENGTH 70

struct Playerinfo {
    int pLives;
    char pName[20]; // Adjusted size for player name
    int nTreasure;
    int history[MAX_PATH_LENGTH];
};

struct Gameinfo {
    int pathLength;
    int nMoves;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
};

int main(void) {
    // Declarations
    int i;
    struct Playerinfo p1;
    struct Gameinfo g1;

    // Header
    printf("================================");
    printf("\n         Treasure Hunt!");
    printf("\n================================");
    printf("\n\nPLAYER Configuration");
    printf("\n--------------------");

    // Getting player name (single character)
    printf("\nEnter a single character to represent the player: ");
    scanf(" %c", &p1.pName[0]); // Corrected indexing

    // Do-while loop to get max player lives
    do {
        printf("Set the number of lives: ");
        scanf("%d", &p1.pLives);

        // If for the conditions when lives > 10 or <1
        if (p1.pLives < 1 || p1.pLives > 10) {
            printf("     Must be between 1 and 10!\n");
        }

    } while (p1.pLives < 1 || p1.pLives > 10);

    // Config set display message
    printf("Player configuration set-up is complete");

    // Game CONFIG
    printf("\n\nGAME Configuration");
    printf("\n------------------");

    // Do while loop for the Path length
    do {
        // Initial input
        printf("\nSet the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &g1.pathLength);
        // If statement to fulfill conditions
        if (g1.pathLength < 10 || g1.pathLength > 70 || g1.pathLength % 5 != 0) {
            printf("     Must be a multiple of 5 and between 10-70!!!");
        }
    } while (g1.pathLength < 10 || g1.pathLength > 70 || g1.pathLength % 5 != 0);

    // Do while for number of moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &g1.nMoves);

        // Value must be between 3 and 26 if condition
        if (g1.nMoves > 26 || g1.nMoves < 3) {
            printf("    Value must be between 3 and 26\n");
        }
    } while (g1.nMoves > 26 || g1.nMoves < 3);

    // BOOM
    printf("\nBOMB Placement");
    printf("\n--------------");
    printf("\nEnter the bomb positions in sets of 5 where a value");
    printf("\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.");
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.pathLength);

    // For loop for bomb input
    for (i = 0; i < g1.pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        // For placing the bombs using scanf
        int j;
        for (j = i; j < i + 5; j++) {
            scanf("%d", &g1.bombs[j]);
        }
    }
    printf("BOMB placement set");

    // Treasure placement
    printf("\n\nTREASURE Placement");
    printf("\n------------------");
    printf("\nEnter the treasure placements in sets of 5 where a value");
    printf("\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.");
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.pathLength);

    // For loop for treasure
    for (i = 0; i < g1.pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        // Actual for loop for scanf to get value
        int j;
        for (j = i; j < i + 5; j++) {
            scanf("%d", &g1.treasures[j]);
        }
    }
    // Print game final info
    printf("TREASURE placement set");
    printf("\n\nGAME configuration set-up is complete...");
    printf("\n\n------------------------------------");
    printf("\nTREASURE HUNT Configuration Settings");
    printf("\n------------------------------------");
    printf("\nPlayer:");
    printf("\n   Symbol     : %c", p1.pName[0]);
    printf("\n   Lives      : %d", p1.pLives);
    printf("\n   Treasure   : [ready for gameplay]");
    printf("\n   History    : [ready for gameplay]");
    printf("\n\nGame:");
    printf("\n   Path Length: %d", g1.pathLength);

    // For bomb info
    printf("\n   Bombs      : ");
    for (i = 0; i < g1.pathLength; i++) {
        printf("%d", g1.bombs[i]);
    }

    // For treasure info
    printf("\n   Treasure   : ");
    for (i = 0; i < g1.pathLength; i++) {
        printf("%d", g1.treasures[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}

