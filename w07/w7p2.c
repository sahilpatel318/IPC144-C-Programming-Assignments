/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)

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
#define MAX_PATH_LENGTH 70

struct PlayerInfo {
    int Num_Of_Lives;
    char symbol;
    int Num_Of_Treasure;
    int Positions[MAX_PATH_LENGTH];
};
struct GameInfo {
    int Max_Num_Moves;
    int Path_Length;
    int Bombs[MAX_PATH_LENGTH];
    int Treasure[MAX_PATH_LENGTH];
};

int main(void)
{
    struct PlayerInfo Player;
    struct GameInfo Game;
    int i, j;
    int Min_Move_Allow, Max_Move_Allow;
    int nextMove = -1;
    char board[MAX_PATH_LENGTH];

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &Player.symbol);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &Player.Num_Of_Lives);
        if (Player.Num_Of_Lives < 1 || Player.Num_Of_Lives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (Player.Num_Of_Lives < 1 || Player.Num_Of_Lives > 10);
    Player.Num_Of_Treasure = 0;
    for (i = 0; i < MAX_PATH_LENGTH; i++)
    {
        Player.Positions[i] = 0;
    }
    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &Game.Path_Length);
        if (Game.Path_Length < 10 || Game.Path_Length > 70 || Game.Path_Length % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (Game.Path_Length < 10 || Game.Path_Length > 70 || Game.Path_Length % 5 != 0);
    do
    {
        Min_Move_Allow = Player.Num_Of_Lives;
        Max_Move_Allow = Game.Path_Length * 0.75;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &Game.Max_Num_Moves);
        if (Game.Max_Num_Moves < Min_Move_Allow || Game.Max_Num_Moves > Max_Move_Allow)
        {
            printf("    Value must be between %d and %d\n", Min_Move_Allow, Max_Move_Allow);
        }
    } while (Game.Max_Num_Moves < Min_Move_Allow || Game.Max_Num_Moves > Max_Move_Allow);
    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.Path_Length);
    for (i = 0; i < Game.Path_Length; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = i; j < i + 5; j++) {
            scanf("%d", &Game.Bombs[j]);
        }
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.Path_Length);
    for (i = 0; i < Game.Path_Length; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &Game.Treasure[j]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", Player.symbol);
    printf("   Lives      : %d\n", Player.Num_Of_Lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", Game.Path_Length);
    printf("   Bombs      : ");
    for (i = 0; i < Game.Path_Length; i++)
    {
        printf("%d", Game.Bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < Game.Path_Length; i++)
    {
        printf("%d", Game.Treasure[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    for (i = 0; i < Game.Path_Length; i++)
    {
        board[i] = '-';
    }
    while (Player.Num_Of_Lives > 0 && Game.Max_Num_Moves > 0)
    {
        if (nextMove != -1)
        {
            printf("\n  ");
            for (i = 0; i < Game.Path_Length; i++)
            {
                if (i != nextMove - 1 && i <= nextMove - 1)
                {
                    printf(" ");
                }
                else if (i == nextMove - 1 && i <= nextMove - 1)
                {
                    printf("%c", Player.symbol);
                }
            }
        }
        printf("\n  ");
        for (i = 0; i < Game.Path_Length; i++)
        {
            printf("%c", board[i]);
        }
        printf("\n  ");
        for (i = 0; i < Game.Path_Length; i++)
        {
            if ((i + 1) % 10 != 0)
            {
                printf("|");
            }
            else
            {
                printf("%d", (i + 1) / 10);
            }
        }
        printf("\n  ");
        for (i = 0; i < Game.Path_Length; i++)
        {
            printf("%d", (i + 1) % 10);
        }
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Player.Num_Of_Lives, Player.Num_Of_Treasure, Game.Max_Num_Moves);
        printf("+---------------------------------------------------+\n");
        printf("Next Move [1-%d]: ", Game.Path_Length);
        scanf("%d", &nextMove);
        while (nextMove < 1 || nextMove > Game.Path_Length)
        {
            printf("  Out of Range!!!\n");
            printf("Next Move [1-%d]: ", Game.Path_Length);
            scanf("%d", &nextMove);
        }
        printf("\n");
        if (Player.Positions[nextMove - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n");
        }
        else
        {
            Player.Positions[nextMove - 1] = 1;
            Game.Max_Num_Moves--;
            if (Game.Bombs[nextMove - 1] == 1 && Game.Treasure[nextMove - 1] == 1)
            {
                Player.Num_Of_Lives--;
                Player.Num_Of_Treasure++;
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                board[nextMove - 1] = '&';
            }
            else if (Game.Bombs[nextMove - 1] == 1)
            {
                Player.Num_Of_Lives--;
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                board[nextMove - 1] = '!';
            }
            else if (Game.Treasure[nextMove - 1] == 1)
            {
                Player.Num_Of_Treasure++;
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                board[nextMove - 1] = '$';
            }
            else
            {
                printf("===============> [.] ...Nothing found here... [.]\n");
                board[nextMove - 1] = '.';
            }
        }
    }
    printf("\nNo more LIVES remaining!\n");
    printf("\n  ");
    for (i = 0; i < Game.Path_Length; i++)
    {
        if (i != nextMove - 1 && i <= nextMove - 1)
        {
            printf(" ");
        }
        else if (i == nextMove - 1 && i <= nextMove - 1)
        {
            printf("%c", Player.symbol);
        }
    }
    printf("\n  ");
    for (i = 0; i < Game.Path_Length; i++)
    {
        printf("%c", board[i]);
    }
    printf("\n  ");
    for (i = 0; i < Game.Path_Length; i++)
    {
        if ((i + 1) % 10 != 0)
        {
            printf("|");
        }
        else
        {
            printf("%d", (i + 1) / 10);
        }
    }
    printf("\n  ");
    for (i = 0; i < Game.Path_Length; i++)
    {
        printf("%d", (i + 1) % 10);
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Player.Num_Of_Lives, Player.Num_Of_Treasure, Game.Max_Num_Moves);
    printf("+---------------------------------------------------+\n");
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}