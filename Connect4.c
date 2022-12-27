#include <stdbool.h>
#include <stdio.h>

bool make_move(char board[6][7], int column, char player);

bool check_win(char board[6][7], char player);

int main(void) {
    puts("Hello! \n\nWelcome to connect 4!\n");
    puts("Player 1 will be represented by X and Player 2 will be represented by O\n");

    bool win_check = false, validTurn;
    char board[6][7];
    char player;
    int turn = 1, column = 0, check = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }

    while (win_check == false) {
        validTurn = false;
        for (int i = 0; i < 6; i++) {
            printf("\n - - - - - - - \n|");
            for (int j = 0; j < 7; j++) {
                printf("%c|", board[i][j]);
            }
        }
        printf("\n - - - - - - - \n");
        while (validTurn == false)
            if (turn > 42) {
                puts("\n\nTie Game!");
                win_check = true;
                break;
            } else if (turn % 2 == 1) {
                player = 'X';

                puts("\n\nIt is player 1's turn, please choose column 1, 2, 3, 4, 5, 6, or 7 to make a move.");
                check = scanf("%d", &column);

                if (check == 0 || column > 7) {
                    puts("Game terminated!\n\n");
                    win_check = true;
                    break;
                }
                if (make_move(board, column, player) == 0) {
                    puts("Invalid Move!\n\n");

                    for (int i = 0; i < 6; i++) {
                        printf("\n - - - - - - - \n|");
                        for (int j = 0; j < 7; j++) {
                            printf("%c|", board[i][j]);
                        }
                    }
                    continue;
                } else {
                    if (check_win(board, player) == 1) {
                        win_check = true;

                        for (int i = 0; i < 6; i++) {
                            printf("\n - - - - - - - \n|");
                            for (int j = 0; j < 7; j++) {
                                printf("%c|", board[i][j]);
                            }
                        }
                        printf("\n - - - - - - - \n");

                        puts("\n\nPlayer 1 Wins!");
                        break;
                    }
                    validTurn = true;
                    turn++;
                    break;
                }
            } else {
                player = 'O';

                puts("\n\nIt is player 2's turn, please choose column 1, 2, 3, 4, 5, 6, or 7 to make a move.");
                check = scanf("%d", &column);

                if (check == 0 || column > 7 || column < 1) {
                    puts("Game terminated!\n\n");
                    win_check = true;
                    break;
                }
                if (make_move(board, column, player) == 0) {
                    puts("Invalid Move!\n\n");
                    continue;
                } else {
                    if (check_win(board, player) == 1) {
                        win_check = true;

                        for (int i = 0; i < 6; i++) {
                            printf("\n - - - - - - - \n|");
                            for (int j = 0; j < 7; j++) {
                                printf("%c|", board[i][j]);
                            }
                        }
                        printf("\n - - - - - - - \n");

                        puts("\n\nPlayer 2 Wins!");
                        break;
                    }
                    validTurn = true;
                    turn++;
                    break;
                }
            }
    }
}

bool check_win(char board[6][7], char player) {
    int four = 0;

    for (int i = 0; i < 6; i++) {
        four = 0;
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == player) {
                four++;
            } else {
                four = 0;
            }
            if (four == 4) {
                return true;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        four = 0;
        for (int j = 0; j < 6; j++) {
            if (board[j][i] == player) {
                four++;
            } else {
                four = 0;
            }
            if (four == 4) {
                return true;
            }
        }
    }

    // Checking Diagonals from bottom left
    for (int i = 0; i < 4; i++) {
        four = 0;
        for (int j = 0; j < 4 + i; j++) {
            if (board[5 - j][3 + i - j] == player) {
                four++;
            } else {
                four = 0;
            }
            if (four == 4) {
                return true;
            }
        }
    }
    // Checking Diagonals from top right
    for (int i = 0; i < 2; i++) {
        four = 0;
        for (int j = 0; j < 4 + i; j++) {
            if (board[0 + j][3 - i + j] == player) {
                four++;
            } else {
                four = 0;
            }
            if (four == 4) {
                return true;
            }
        }
    }
    // Checking Diagonals from top left
    for (int i = 0; i < 3; i++) {
        four = 0;
        for (int j = 0; j < 4 + i; j++) {
            if (board[0 + j][3 + i - j] == player) {
                four++;
            } else {
                four = 0;
            }
            if (four == 4) {
                return true;
            }
        }
    }
    // Checking Diagonals from bottom right
    for (int i = 0; i < 3; i++) {
        four = 0;
        for (int j = 0; j < 4 + i; j++) {
            if (board[5 - j][3 - i + j] == player) {
                four++;
            } else {
                if (four == 4) {
                    return true;
                }
                four = 0;
            }
            if (four == 4) {
                return true;
            }
        }
    }

    return false;
}

bool make_move(char board[6][7], int column, char player) {
    bool move = false;
    for (int i = 5; i >= 0; i--) {
        if (board[i][column - 1] != 'X' && board[i][column - 1] != 'O') {
            board[i][column - 1] = player;
            move = true;
            break;
        }
    }
    return move;
}
