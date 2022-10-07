/*
* Descrption: Tic-Tac-Toe Game "User Vs User" and "User Vs Computer";
* 
* Copyright @ Myo Aung 2022.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h> 

char board[3][3];                                   // Global Variables
int playerTurn = 1;                                 

void initialize() {                                 // This function inatialize the board
    int i, j;
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3; j++) {
            board[i][j] = '.';
        }
    }
}

void displayBoard() {                               // Display Board Function.
    printf("\nThe current status is:\n");
    printf("+-----+\n");
    for(int i = 1; i <= 3; i++) {
        printf("|");
        for(int j = 1; j <= 3; j++) {
            printf("%c", board[i][j]);
            printf("|");
        }
        printf("\n");
        printf("+-----+\n");
    }
}

void player_vs_player_Move() {                        // Player1 Vs Player Move Function
    int row, column;
    bool correctMove = false;
    printf("\nPlayer %d :Make your move\n" , playerTurn);
    while(!correctMove) {
        scanf("%d %d", &row, &column);
        printf("\nGood!\n");
        if(row < 1 || row > 3 || column < 1 || column > 3) {
            printf("Invalid Entry, Try Again!\n");     // This if-statement checks boundaries
            correctMove = false;
            return;
        }
        for(int i = 1; i <= 3; i++) {                  // Placing move on the board
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
                playerTurn++;                           // Turn increment but limited to 2
                if(playerTurn >2)
                    playerTurn = 1;
            }           
        }
        if(!correctMove) {                                
            printf("Wrong Move, Enter Againg\n");
        }
    }
}

void player_vs_computer_move() {                        // Player1 Vs Computer Move Function
    time_t t; 
    srand((unsigned) time(&t)); 
    int row, column;
    bool correctMove = false;

    printf("\nPlayer %d :Make your move\n" , playerTurn);
    while(!correctMove) {
        if(playerTurn == 1) {
            printf("Asking Player %d for entry: " , playerTurn);
            scanf("%d %d", &row, &column);               // Randomly generate moves between 1 and 3
            printf("\nGood!\n");
        } else if(playerTurn == 2) {
            row = rand() % 3 + 1;                       // Random number for row
            column = rand() % 3 + 1;                    // Random number for column
            printf("Here is Computer Move: %d %d \n", row, column);
        }

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
        if (board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return board[i][1];                             // check rows
        }
        
        if (board[1][i] == board[2][i] && board[1][i] == board[3][i]) {
            return board[1][i];                             // check columns
        }
    }
    
    if (board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return board[1][1];                                 // check diagonal(backward)
    }
    
    if (board[1][3] == board[2][2] && board[2][2] == board[3][1]) {
        return board[1][3];                                // check diagonal(forward)
    }
    
    return '&';                                           // if everything else doesn't work, then it returns nothing, meaning the game goes on
}

bool checkDraw() {                                        // This function checks the board is filled
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(board[i][j] == '.')
                return false;
        }
    }
    return true;
}

bool checkResult() {                                        // Checking Results
    char result = checkWin();
    switch(result) {
        case 'O':
            displayBoard();
            printf("Player 1-'O' Won!!\n");
            return true;
        case 'X':
            displayBoard();
            printf("Player 2/Computer -'X' Won!!\n");
            return true;
        case '&':
            if(checkDraw()) {
                displayBoard();
                printf("Match Drawn!\n");
                return true;
            }
        break;
    }
    return false;
}   

void play_vs_player_Game() {                                // Player Vs Player Game Function
    while(1) {
        displayBoard();
        player_vs_player_Move();
        if(checkResult()) {
            break;
        }
    }
    printf("\n");
}

void player_Vs_computer_Game() {                            // Player Vs Player Game Function
    while(1) {
        displayBoard();
        player_vs_computer_move();
        if(checkResult()) {
            break;
        }
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int choice;                                             // prompt user for game they wish to play
    printf("   WELCOME TO TIC-TAC-TOE    \n");
    printf("1 --- person vs. person\n");
    printf("2 --- person vs. random computer\n");
  
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    initialize();                                           // Initialze the Board with '.'

    switch(choice) {                                        // Menu for choice of games
        case 1:
            printf("You have entered choice 1: \n");
            printf("==========================\n");
            play_vs_player_Game();
            break;
        case 2:
            printf("You have entered choice 2: \n");
            printf("==========================\n");
            player_Vs_computer_Game();
            break;
        default:
            printf("Enter a valid choice\n");
    }
    return 0;
}
