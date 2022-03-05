#include "rps.c"
#include "ttt.c"

int status = 1; //A flag that signifies the program was run for the first time.
void first_time();
void succeeding_times();
char prompt_after_game();

void main() {
    int option = 0;
    if (status == 1) {
        first_time();
        status = 0;
    }
    else {
        succeeding_times();
    }

    //Get the input of the user regardless of the branch chosen.
    do {
        scanf("%d", &option);
    } while(option < 1 || option > 3);

    switch(option) {
        case(1): {
            //Launches the game: Rock, Paper, Scissors.
            char ans = 'Y';
            while (toupper(ans) == 'Y') { //Allows the player to repeat the game.
                main_rps();
                ans = prompt_after_game();
            }
            break;
        }
        case(2): {
            //Launches the game: Tic-Tac-Toe.
            char ans = 'Y';
            while (toupper(ans) == 'Y') { //Allows the player to repeat the game.
                main_ttt();
                ans = prompt_after_game();
            }
            break;
        }
        case(3): {
            //Exits the game.
            printf("Thank you for your time. Hope to see you again!");
            exit(0);
        }
    }
    
    //Allows the player to choose another option.
    char response = 'Y';
    printf("Would you like to choose another option? Input 'Y' if Yes and 'N' if No.\n");
    do {
        scanf("%c", &response);
    } while(toupper(response) != 'Y' && toupper(response) != 'N');

    if (toupper(response) == 'Y') {
        main();
    }
    else {
        printf("Thank you for your time. Hope to see you again!");
        exit(0);
    }
}

void first_time() {
    //Prints the message when the player plays for the first time.
    printf("Good day! Which of these games would you like to play? \n");
    printf("Press the corresponding number for your choice!\n");
    printf("(1) Rock, Paper, Scissors\n");
    printf("(2) Tic-Tac-Toe\n");
    printf("(3) Quit\n");
}

void succeeding_times() {
    //Displays the message when the player plays for the succeeding times.
    printf("Which of these games would you play now?\n");
    printf("(1) Rock, Paper, Scissors\n");
    printf("(2) Tic-Tac-Toe\n");
    printf("(3) Quit\n");
}

char prompt_after_game() {
    char ans;
    printf("Would you like to play again? Input 'Y' if Yes and 'N' if No.\n");
    do {
        scanf("%c", &ans);
    } while(toupper(ans) != 'Y' && toupper(ans) != 'N');
    
    return ans;
}