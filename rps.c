//Refactor and add a scoring for both contenders.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int single_player();
int double_player();

int main() {
    //A simple game of Rock, Paper Scissors.
    
    int mode, no_of_rounds; //Initializes the parameters needed for the game.

    printf("Welcome to a simple game of Rock, Paper, Scissors! "); 
    printf("Which game mode would you like to play? \n");
    printf("Input the number (1) for single-player mode, and (2) for 2-player mode: \n");

    do {
        scanf(" %d", &mode);
    } while(mode != 1 && mode != 2);
    
    printf("How many rounds would you like your game to have? ");
    printf("Note that you can only select a maximum of 10 rounds. \n");

    do {
        scanf(" %d", &no_of_rounds);
    } while(no_of_rounds > 10);

    //Allows players to access their choice.
    (mode == 1) ? (single_player(no_of_rounds)) : (double_player(no_of_rounds));

}

int convert(int temp);
int determine_winner(char p1, char p2);

int single_player(int rounds) {
    int score_p1, score_p2;
    for (int r=0; r<rounds; r++) {
        char p1;
        int p2;
        printf("Rock, Paper, or Scissors? Simply type R, P or S.\n");
        do {
            scanf(" %c", &p1);
        } while (toupper(p1) != 'R' && toupper(p1) != 'P' && toupper(p1) != 'S');

        p2 = convert((rand() % 3) + 1);
        determine_winner(toupper(p1), toupper(p2));
    }
}
int double_player(int rounds) {
    int score_p1, score_p2;
    printf("Rock, Paper, or Scissors? Simply type R, P or S.\n");

    for (int r=0; r<rounds; r++) {
        char p1, p2;
        printf("Player 1:\n");
        do {
            scanf(" %c", &p1);
        } while (toupper(p1) != 'R' && toupper(p1) != 'P' && toupper(p1) != 'S');

        printf("Player 2:\n");
        do {
            scanf(" %c", &p2);
        } while (toupper(p2) != 'R' && toupper(p2) != 'P' && toupper(p2) != 'S');

        determine_winner(toupper(p1), toupper(p2)); //Only notes score of player 1
    }
}

int convert(int temp) {
    if (temp == 1) {
        return 'R';
    }
    else if (temp == 2) {
        return 'P';
    }
    else {
        return 'S';
    }
}

int rock(char p1, char p2);
int paper(char p1, char p2);
int scissors(char p1, char p2);

int determine_winner(char p1, char p2) {
    //This part ugh
    if (p1 == 'R') {
        return rock(p1, p2);
    }
    else if (p1 == 'P') {
        return paper(p1, p2);
    }
    else {
        return scissors(p1, p2);
    }
}

int rock(char p1, char p2) {
    if (p2 == 'R') {
        return 0;
    }
    else if (p2 == 'P') {
        return -1;
    }
    else {
        return 1;
    }
}

int paper(char p1, char p2) {
    if (p2 == 'P') {
        return 0;
    }
    else if (p2 == 'S') {
        return -1;
    }
    else {
        return 1;
    }
}

int scissors(char p1, char p2) {
    if (p2 == 'S') {
        return 0;
    }
    else if (p2 == 'R') {
        return -1;
    }
    else {
        return 1;
    }
}