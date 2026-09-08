#include <stdio.h>

char board[3][3];

void boardArr () {
    char count = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count;
            count++;
        }
    }
}

int drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void makeMove (char currentPlayer) {
    int cell = 0;
    while (1) {
        printf("Player %c Print the number 1 to 9: ", currentPlayer);
        scanf("%d", &cell);

        if (cell < 1  || cell > 9) {
        printf("Invalid move!\n");
        continue;
        }
        int col = (cell - 1) % 3;
        int row = (cell - 1) / 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Cell already taken\n");
        } else {
            board[row][col] = currentPlayer;
            break;
        }
    }
}

int winner () {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}


int main () {
    char currentPlayer = 'X';
    int moves = 0;
    boardArr();

    while (1) {
        drawBoard();
        makeMove (currentPlayer);
        moves++;

        if (winner()) {
            drawBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (moves == 9) {
            drawBoard();
            printf("It's a draw!");
        }

        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
    return 0;
}
