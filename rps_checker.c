//Is "rps_checker.c"

int rock(char p1, char p2, int tally[]);
int paper(char p1, char p2, int tally[]);
int scissors(char p1, char p2, int tally[]);

int determine_winner(char p1, char p2, int tally[]) {
    //A function that enables the program to update the players' scores for this round.
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
        tally[0] = 0;
        tally[1] = 1;
    }
    else if (p2 == 'S'){
        tally[0] = 1;
        tally[1] = 0;
    }
    else {
        tally[0] = 0;
        tally[1] = 0;
    }
}

int paper(char p1, char p2, int tally[]) {
    if (p2 == 'S') {
        tally[0] = 0;
        tally[1] = 1;
    }
    else if (p2 == 'R'){
        tally[0] = 1;
        tally[1] = 0;
    }
    else {
        tally[0] = 0;
        tally[1] = 0;
    }
}

int scissors(char p1, char p2, int tally[]) {
    if (p2 == 'R') {
        tally[0] = 0;
        tally[1] = 1;
    }
    else if (p2 == 'P'){
        tally[0] = 1;
        tally[1] = 0;
    }
    else {
        tally[0] = 0;
        tally[1] = 0;
    }
}