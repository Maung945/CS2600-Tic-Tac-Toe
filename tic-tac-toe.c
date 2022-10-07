// Tick Tac Toe game between 2 players or player vs computer
#include <stdio.h>
#include <stdbool.h>
char board[3][3];
int playerTurn = 1;

void initialize() {
    int i, j;
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3; j++) {
            board[i][j] = ',';
        }
    }
}

void displayBoard() {
    printf("+-----+\n");
    for(int i = 1; i <= 3; i++) {
        printf("|");
        for(int j = 1; j <= 3; j++) {
            printf("%c", board[i][j]);
            rintf("|");
        }
        printf("\n");
        printf("+-----+\n");
    }
}

void playerMove() {
    int row, column;
    bool correctMove = false;
    printf("\n Player %d", playerTurn, ":Make your move\n");
    while(!correctMove) {
        scanf("%d ", row);
        scanf("%d ", column);
        if(row < 1 || row > 3 || column < 1 || column > 3) {
            printf("Invalid Entry, Try Again!\n");
            correctMove = false;
            return;
        }
        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= 3; j++) {
                if(board[row][column] == '.' && playerTurn == 1) {
                    board[row][column] = 'O';
                }
                else if (board[row][column] == '.' && playerTurn == 2) {
                    board[row][column] = 'X';
                }
                else if (board[row][column] == 'X' || board[row][column] == 'O') {
                    return;
                }
                correctMove = true;
                playerTurn++;
                if(playerTurn >2)
                    playerTurn = 1;
            }           
        }
        if(!correctMove) {
            printf("Wrong Move, Enter Againg\n");
        }
    }
}

char checkWin() {
    int i;   
    for (i = 1; i <= 3; i++) {
        // check rows
        if (board[i][1] == board[i][2] && board[i][2] == board[i][3])
            return board[i][1];
        // check columns
        if (board[1][i] == board[2][i] && board[1][i] == board[3][i])
            return board[1][i];
    }
    // check diagonal 1
    if (board[1][1] == board[2][2] && board[2][2] == board[3][3])
        return board[1][1];
    // check diagonal 2
    if (board[1][3] == board[2][2] && board[2][2] == board[3][1])
        return board[1][3];
    // if everything else doesn't work, then it returns nothing, meaning the game goes on
    return '&';
}

int main() {
    // prompt user for game they wish to play
    int choice;
    printf("   WELCOME TO TIC-TAC-TOE    \n");
    printf("1 --- person vs. person\n");
    printf("2 --- person vs. random computer\n");
  
    
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have entered choice 1: \n");
            printf("==========================\n");
            while(1) {
                displayBoard();
                playerMove();
                if(checkResult()) {
                    break;
                }
            }
            //break;
        case 2:
            printf("You have entered choice 2: \n");
            printf("==========================\n");
            
            break;
        default:
            printf("Enter a valid choice\n");
    }

    // read information console


    return 0;
}
