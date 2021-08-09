#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "rps_checker.c"

int single_player();
int double_player();
int convert(int temp);
char * letter_to_word(char letter);
int winner_for_round(int tally[]);

int main() {
    //A simple game of Rock, Paper Scissors.
    
    int mode, no_of_rounds; //Initializes the parameters needed for the game.

    printf("Welcome to a simple game of Rock, Paper, Scissors! "); 
    printf("Which game mode would you like to play? \n");
    printf("Input the number (1) for single-player mode, and (2) for 2-player mode: \n");

    do {
        scanf(" %d", &mode);
    } while(mode != 1 && mode != 2); //Ensures that the user only inputs one of the two game modes.
    
    printf("How many rounds would you like your game to have? ");
    printf("Note that you can only select a maximum of 10 rounds. \n");

    do {
        scanf(" %d", &no_of_rounds);
    } while(no_of_rounds > 10); 

    //Allows players to access their choice.
    (mode == 1) ? (single_player(no_of_rounds)) : (double_player(no_of_rounds));

}

int single_player(int rounds) {
    int score_p1=0, score_p2=0, tally[2]={0, 0};
    for (int r=0; r<rounds; r++) {
        char p1;
        int p2;
        printf("Rock, Paper, or Scissors? Simply type R, P or S.\n");

        //Only allows inputs corresponding to Rock, Paper, or Scissors.
        do {
            scanf(" %c", &p1);
        } while (toupper(p1) != 'R' && toupper(p1) != 'P' && toupper(p1) != 'S'); 

        //The Computer would pick a number from 1 to 3. Such is equivalent to Rock, Paper, or Scissors.
        p2 = convert((rand() % 3) + 1); 
        Sleep(1000);
        determine_winner(toupper(p1), toupper(p2), tally);
        
        //Adds the scores.
        score_p1 += tally[0];
        score_p2 += tally[1];
    
        printf("===========================================\n");
        printf("%s vs %s \n", letter_to_word(toupper(p1)), letter_to_word(toupper(p2)));
        Sleep(1500);
        winner_for_round(tally);
        printf("The score of Player 1 is %d. \n", score_p1);
        printf("The score of your opponent is %d. \n", score_p2);
        printf("===========================================\n");
        Sleep(1000);
    }

    if (score_p1 > score_p2) {
        printf("Congratulations, you win!");
    } 
    else if (score_p1 < score_p2) {
        printf("Sorry, you lose. Better luck next time!");
    }
    else {
        printf("It's a draw!");
    }
}

int double_player(int rounds) {
    int score_p1=0, score_p2=0, tally[2]={0, 0};
    printf("Rock, Paper, or Scissors? Simply type R, P or S.\n");

    for (int r=0; r<rounds; r++) {
        char p1, p2;
        printf("Player 1:\n");

        //Only allows inputs corresponding to Rock, Paper, or Scissors.
        do {
            scanf(" %c", &p1);
        } while (toupper(p1) != 'R' && toupper(p1) != 'P' && toupper(p1) != 'S');

        printf("Player 2:\n");
        do {
            scanf(" %c", &p2);
        } while (toupper(p2) != 'R' && toupper(p2) != 'P' && toupper(p2) != 'S');
        Sleep(1500);
        determine_winner(toupper(p1), toupper(p2), tally);
        
        
        //Adds the scores.
        score_p1 += tally[0];
        score_p2 += tally[1];

        printf("===========================================\n");
        printf("%s vs %s \n", letter_to_word(toupper(p1)), letter_to_word(toupper(p2)));
        Sleep(1000);
        winner_for_round(tally);
        printf("The score of Player 1 is %d. \n", score_p1);
        printf("The score of Player 2 is %d. \n", score_p2);
        printf("===========================================\n");
        Sleep(1000);
    }
    if (score_p1 > score_p2) {
        printf("Congratulations Player 1, you win!");
    }
    else if (score_p2 > score_p1) {
        printf("Congratulations Player 2, you win!");
    }
    else {
        printf("It's a draw!");
    }
}

int convert(int temp) {
    //Converts the numbers 1, 2, & 3 to their corresponding "letters".
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

char * letter_to_word(char letter) {
    //Converts the characters into their corresponding strings. Makes it more intuitive to players.
    if (letter == 'R') {
        return "Rock";
    }
    if (letter == 'P') {
        return "Paper";
    }
    if (letter == 'S') {
        return "Scissors";
    }
}

int winner_for_round(int tally[]) {
    //A function that determines the winner for a specific round.
    if (tally[0] > tally[1]) {
        printf("Player 1 wins this round! \n");
    }
    else if (tally[0] < tally[1]) {
        printf("Player 2 wins this round! \n");
    }
    else {
        printf("This round ends with a draw! \n");
    }
}