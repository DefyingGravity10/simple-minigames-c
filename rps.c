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
    } while(no_of_rounds > 10); //Make sure that the user types a number!

    //Allows players to access their choice.
    (mode == 1) ? (single_player(no_of_rounds)) : (double_player(no_of_rounds));

}

int convert(int temp);
int determine_winner(char p1, char p2, int tally[]);

int single_player(int rounds) {
    int score_p1=0, score_p2=0, tally[2]={0, 0};
    for (int r=0; r<rounds; r++) {
        char p1;
        int p2;
        printf("Rock, Paper, or Scissors? Simply type R, P or S.\n");
        do {
            scanf(" %c", &p1);
        } while (toupper(p1) != 'R' && toupper(p1) != 'P' && toupper(p1) != 'S');

        p2 = convert((rand() % 3) + 1);
        determine_winner(toupper(p1), toupper(p2), tally);
        score_p1 += tally[0];
        score_p2 += tally[1];

        printf("The score of Player 1 is %d \n", score_p1);
        printf("Meanwhile, the score of your opponent is %d \n", score_p2);
    }
}
int double_player(int rounds) {
    int score_p1=0, score_p2=0, tally[2]={0, 0};
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

        determine_winner(toupper(p1), toupper(p2), tally); //Only notes score of player 1
        score_p1 += tally[0];
        score_p2 += tally[1];

        printf("The score of Player 1 is %d \n", score_p1);
        printf("Meanwhile, the score of Player 2 is %d \n", score_p2);
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

int rock(char p1, char p2, int tally[]);
int paper(char p1, char p2, int tally[]);
int scissors(char p1, char p2, int tally[]);

int determine_winner(char p1, char p2, int tally[]) {
    //This part ugh
    if (p1 == 'R') {
        rock(p1, p2, tally);
    }
    else if (p1 == 'P') {
        paper(p1, p2, tally);
    }
    else {
        scissors(p1, p2, tally);
    }
}

int rock(char p1, char p2, int tally[]) {
    if (p2 == 'P') {
        tally[1] += 1;
    }
    else if (p2 == 'S'){
        tally[0] += 1;
    }
}

int paper(char p1, char p2, int tally[]) {
    if (p2 == 'S') {
        tally[1] += 1;
    }
    else if (p2 == 'R'){
        tally[0] += 1;
    }
}

int scissors(char p1, char p2, int tally[]) {
    if (p2 == 'R') {
        tally[1] += 1;
    }
    else if (p2 == 'P'){
        tally[0] += 1;
    }
}