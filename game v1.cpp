
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess;
    int attempts, i;
    int minNumber = 1;
    int maxNumber = 10;
    char choice;

    srand(time(0));

    do {
        // Generate random number within the specified range
        randomNumber = (rand() % (maxNumber - minNumber + 1)) + minNumber;

        attempts = 3;
        i = 1;

        printf("\n===== NUMBER GUESSING GAME =====\n");
        printf("Guess a number between %d and %d.\n", minNumber, maxNumber);
        printf("You have %d attempts!\n\n", attempts);

        while (i <= attempts) {
            printf("Attempt %d of %d: Enter your guess: ", i, attempts);

            // Validate input
            if (scanf("%d", &guess) != 1) {
                printf("Invalid input! Please enter a number.\n");

                while (getchar() != '\n');
                continue;
            }

            // Validate guessing range
            if (guess < minNumber || guess > maxNumber) {
                printf("Invalid guess! Enter a number between %d and %d.\n",
                       minNumber, maxNumber);
                continue;
            }

            // Check the guess
            if (guess == randomNumber) {
                printf("\nCongratulations! You guessed correctly!\n");
                break;
            }
            else if (guess > randomNumber) {
                printf("Too high! Try again.\n");
            }
            else {
                printf("Too low! Try again.\n");
            }

            i++;
        }

        // Display result if all attempts are used
        if (i > attempts) {
            printf("\nGame Over! You have used all %d attempts.\n", attempts);
            printf("The correct number was %d.\n", randomNumber);
        }

        // Ask whether the user wants to play again
        do {
            printf("\nDo you want to play again? (Y/N): ");
            scanf(" %c", &choice);

            if (choice != 'Y' && choice != 'y' &&
                choice != 'N' && choice != 'n') {
                printf("Invalid choice! Please enter Y or N.\n");
            }

        } while (choice != 'Y' && choice != 'y' &&
                 choice != 'N' && choice != 'n');

    } while (choice == 'Y' || choice == 'y');

    printf("\nThank you for playing! Goodbye!\n");

    return 0;
}


