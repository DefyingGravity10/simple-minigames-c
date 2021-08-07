#include <stdio.h>
int game_proper(char pos[]); 
int main()
{
    char pos[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printf("Welcome to a game of Tic-Tac-Toe.");
    printf("In this game, Player 1 will be using 'X' while Player 2 will be using 'O'.\n");

    printf("-------------\n");
    printf("| %c | %c | %c |\n", pos[0], pos[1], pos[2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", pos[3], pos[4], pos[5]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", pos[6], pos[7], pos[8]);
    printf("-------------\n");

    printf("Note that the numbers correspond to the available spots. One may place their piece with the number of their choice.\n");
    printf("\n");
    game_proper(pos);
}

int game_proper(char pos[]) {
    //The game will stop once a winner is found. The variable 'flag' represents the status of the game.
    int flag = 0, item;
    
    for (int i=0; i<9; i++) {
        printf("Player %d's turn!\n", i%2+1);
        printf("-------------\n");
        printf("| %c | %c | %c |\n", pos[0], pos[1], pos[2]);
        printf("-------------\n");
        printf("| %c | %c | %c |\n", pos[3], pos[4], pos[5]);
        printf("-------------\n");
        printf("| %c | %c | %c |\n", pos[6], pos[7], pos[8]);
        printf("-------------\n");
        printf("Where will you place your piece? \n");

        do {
            scanf(" %d", &item);
        } while(item < 1 || item > 9); //Make sure that the player does not input a position that is no longer available.

        (i%2+1 == 1) ? (pos[item-1] = 'X') : (pos[item-1] = 'O');
        item = 0;
    }
}