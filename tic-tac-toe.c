// Tick Tac Toe game between 2 players or player vs computer
#include <stdio.h>
int board[3][3];
void playerVsPlayer(int x) {

}

void plyerVsComputer(int x) {

}

void setSymbol(int row, int column) {
    int symbol = (int)'&';
    board[row][column] = symbol;
}

void displayBoard() {
    printf("+-----+\n");
    for(int i = 1; i <= 3; i++) {
        printf("|");
        for(int j = 1; j <= 3; j++) {
            board[i][j] = ' ';
            printf("%c", board[i][j]);
            printf("|");
        }
        printf("\n");
        printf("+-----+\n");
    }
}
void playerOneMove() {
    int row, column, symbol;
    printf("Player1 : make a move\n");
    scanf("%d %d", &row, &column);
    if(row < 1 || row > 3 || column < 1 || column > 3) {
        printf("Invalid Entry, Try Again!\n");
        playerOneMove();
        return;
    }
    if(board[row][column] == 'X') {
        printf("Invalid Move!\n");
        playerOneMove();
        return;
    }
    printf("+-----+\n");
    for(int i = 1; i <= 3; i++) {
        printf("|");
        for(int j = 1; j <= 3; j++) {
            if(i == row && j == column && board[i][j] != 'X') {
                board[i][j] = 'O';
            }
            printf("%c", board[i][j]);
            printf("|");
        }
        printf("\n");
        printf("+-----+\n");
    }
}

void playerTwoMove() {
    int row, column, symbol;
    printf("Player2 : make a move\n");
    scanf("%d %d", &row, &column);
    if(row < 1 || row > 3 && column < 1 || column > 3) {
        printf("Invalid Entry, Try Again!\n");
        playerOneMove();
        return;
    }
    if(board[row][column] == 'O') {
        printf("Invalid Move!\n");
        playerTwoMove();
        return;
    }
    printf("+-----+\n");
    for(int i = 1; i <= 3; i++) {
        printf("|");
        for(int j = 1; j <= 3; j++) {
            if(i == row && j == column) {
                board[i][j] = 'X';
            }
            printf("%c", board[i][j]);
            printf("|");
        }
        printf("\n");
        printf("+-----+\n");
    }
}

int main() {
    // prompt user for game they wish to play
    int choice;
    int row = 3;
    int column = 3;
    int symbol = (int) '.';
    printf("   WELCOME TO TIC-TAC-TOE    \n");
    printf("1 --- person vs. person\n");
    printf("2 --- person vs. random computer\n");
  
    
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You have entered choice 1: \n");
            printf("==========================\n");
            displayBoard();
            playerOneMove();
            playerTwoMove();
            break;
        case 2:
            printf("You have entered choide 2: \n");
            printf("==========================\n");
            displayBoard();
            playerOneMove();
            playerTwoMove();
            break;
        default:
            printf("Enter a valid choice\n");
    }

    // read information console


    return 0;
}