#include <stdio.h>
#include <windows.h>
#include "ttt_checker.c"

void print_board(char pos[]);
int game_proper(char pos[]); 
int check_if_match(char pos[], int num);

void main_ttt()
{   //A game of Tic-Tac-Toe.
    char pos[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printf("Welcome to a game of Tic-Tac-Toe.");
    printf("In this game, Player 1 will be using 'X' while Player 2 will be using 'O'.\n");
    Sleep(1500);
    print_board(pos); 
    printf("Note that the numbers correspond to the available spots. One may place their piece with the number of their choice.\n");
    Sleep(3000);

    //Proclaims a draw if a winner has not been declared.
    if (!game_proper(pos)) {
        print_board(pos);
        printf("It's a draw!\n");
    }
}

void print_board(char pos[]) {
    //A function that displays the game on screen.
    printf("-------------\n");
    printf("| %c | %c | %c |\n", pos[0], pos[1], pos[2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", pos[3], pos[4], pos[5]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", pos[6], pos[7], pos[8]);
    printf("-------------\n");
}

int game_proper(char pos[]) {
    //The game will stop once a winner is found.
    int item;
    
    for (int i=0; i<9; i++) {
        Sleep(200);
        printf("\n");
        printf("Player %d's turn!\n", i%2+1); 
        print_board(pos);
        printf("Where will you place your piece? \n");

        //Ensures that the players give an input within the set parameters. Filled slots can no longer be chosen.
        do {
            scanf(" %d", &item);
        } while((item < 1 || item > 9) || (pos[item-1] == 'X' || pos[item-1] == 'O')); 

        //Place 'X' in the array if it's Player 1's turn & and 'O' otherwise.
        (i%2+1 == 1) ? (pos[item-1] = 'X') : (pos[item-1] = 'O');

        //If a winner is found, proclaim the victor.
        if (check_if_match(pos, item) == 1) {
            print_board(pos);
            printf("Player %d wins!\n", i%2+1);
            return 1;
        }
        //Resets the value of item. Else the program might not ask for user's input.
        item = 0;
    }
    return 0;
}

int check_if_match(char pos[], int num) {
    int h, v, d;
    //Checks if 3 consecutive blocks are filled with the same symbol.
    switch(num) {
        case(1): {
            h = h_ott(pos);
            v = v_ofs(pos);
            d = d_ofn(pos);
            if (h || v || d) {
                return 1;
            }
            break;
        }
        case(2): {
            h = h_ott(pos);
            v = v_tfe(pos);
            if (h || v) {
                return 1;
            }
            break;
        }
        case(3): {
            h = h_ott(pos);
            v = v_tsn(pos);
            d = d_tfs(pos);
            if (h || v || d) {
                return 1;
            }
            break;
        }
        case(4): {
            h = h_ffs(pos);
            v = v_ofs(pos);
            if (h || v) {
                return 1;
            }
            break;
        }
        case(5): {
            int d2;
            h = h_ffs(pos);
            v = v_tfe(pos);
            d = d_ofn(pos);
            d2 = d_tfs(pos);
            if (h || v || d || d2) {
                return 1;
            }
            break;
        }
        case(6): {
            h = h_ffs(pos);
            v = v_tsn(pos);
            if (h || v) {
                return 1;
            }
            break;
        }
        case(7): {
            h = h_sen(pos);
            v = v_ofs(pos);
            d = d_tfs(pos);
            if (h || v || d) {
                return 1;
            }
            break;
        }
        case(8): {
            h = h_sen(pos);
            v = v_tfe(pos);
            if (h || v) {
                return 1;
            }
            break;
        }
        case(9): {
            h = h_sen(pos);
            v = v_tsn(pos);
            d = d_ofn(pos);
            if (h || v || d) {
                return 1;
            }
            break;
        }
        return 0;
    }
}