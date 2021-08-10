//Is "ttt_checker.c"

int h_ott(char pos[]) {
    int value;
    //Checks if positions 1, 2, and 3 have the same symbol.
    (pos[0] == pos[1] && pos[0] == pos[2]) ? (value = 1) : (value = 0);
    return value;
}

int v_ofs(char pos[]) {
    int value;
    //Checks if positions 1, 4, and 7 have the same symbol.
    (pos[0] == pos[3] && pos[0] == pos[6]) ? (value = 1) : (value = 0);
    return value;
}

int d_ofn(char pos[]) {
    int value;
    //Checks if positions 1, 4, and 7 have the same symbol.
    (pos[0] == pos[4] && pos[0] == pos[8]) ? (value = 1) : (value = 0);
    return value;
}

int v_tfe(char pos[]) {
    int value;
    //Checks if positions 2, 5, and 8 have the same symbol.
    (pos[1] == pos[4] && pos[1] == pos[7]) ? (value = 1) : (value = 0);
    return value;
}

int v_tsn(char pos[]) {
    int value;
    //Checks if positions 3, 6, and 9 have the same symbol.
    (pos[2] == pos[5] && pos[2] == pos[8]) ? (value = 1) : (value = 0);
    return value;
}

int d_tfs(char pos[]) {
    int value;
    //Checks if positions 3, 5, and 7 have the same symbol.
    (pos[2] == pos[4] && pos[2] == pos[6]) ? (value = 1) : (value = 0);
    return value;
}

int h_ffs(char pos[]) {
    int value;
    //Checks if positions 4, 5, and 6 have the same symbol.
    (pos[3] == pos[4] && pos[3] == pos[5]) ? (value = 1) : (value = 0);
    return value;
}

int h_sen(char pos[]) {
    int value;
    //Checks if positions 7, 8, and 9 have the same symbol.
    (pos[6] == pos[7] && pos[6] == pos[8]) ? (value = 1) : (value = 0);
    return value;
}