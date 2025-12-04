#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    char playAgain;

    do {
        int x = 1;                  // player position (0 to 2)
        int step = 0;               // obstacle vertical movement
        int obstaclePos = rand() % 3;   // 0,1,2 lane
        int score = 0;              // player score
        int speed = 120;            // initial speed (ms delay)
        int level = 1;              // difficulty level

        while (1) {
            // ---- INPUT ----
            if (_kbhit()) {
                char ch = getch();

                if (ch == 75 && x > 0)        // LEFT arrow
                    x--;

                if (ch == 77 && x < 2)        // RIGHT arrow
                    x++;
            }

            // ---- DRAW ----
            system("cls");

            // Scoreboard + Difficulty
            printf("SCORE: %d   LEVEL: %d\n", score, level);
            printf("|--- --- ---|\n");

            for (int i = 0; i < 10; i++) {
                if (i == step) {
                    if (obstaclePos == 0)
                        printf("| %d        |\n", 1);
                    else if (obstaclePos == 1)
                        printf("|     %d    |\n", 1);
                    else if (obstaclePos == 2)
                        printf("|        %d |\n", 1);
                } else {
                    printf("|           |\n");
                }
            }

            // ---- PLAYER ----
            if (x == 0)
                printf("| %d        |\n", 6);
            else if (x == 1)
                printf("|     %d    |\n", 6);
            else if (x == 2)
                printf("|        %d |\n", 6);

            // ---- COLLISION ----
            if (step == 10 && x == obstaclePos) {
                printf("\nGAME OVER!\n");
                printf("FINAL SCORE: %d\n", score);
                printf("FINAL LEVEL: %d\n", level);
                break;
            }

            Sleep(speed);

            // Move obstacle down
            step++;

            // Reset when reaches bottom
            if (step > 10) {
                step = 0;
                obstaclePos = rand() % 3; // new lane
                score++; // increase score when obstacle passes safely

                // Increase difficulty every 5 points
                if (score % 5 == 0) {
                    level++;
                    if (speed > 40)   // minimum speed limit
                        speed -= 10;  // faster movement
                }
            }
        }

        // ---- Restart Option ----
        printf("\nDo you want to play again? (y/n): ");
        playAgain = getch();  // wait for user input

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");
    return 0;
}

