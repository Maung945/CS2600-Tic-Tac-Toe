// Tick Tac Toe game between 2 players or player vs computer
#include <stdio.h>
void playerVsPlayer(int x) {

}

void plyerVsComputer(int x) {

}

void displayBoard() {
    printf("+-----+\n");
    int board[3][3];
    for(int i = 0; i < 3; i++) {
       for(int j = 0; j < 3; j++) {
            printf("| ");
        }
        printf("|\n");
        printf("+-----+\n");
    }
    //printf("+------------+\n");
}

int main() {
    // prompt user for game they wish to play
    printf("   WELCOME TO TIC-TAC-TOE    \n");
    printf("1 --- person vs. person\n");
    printf("2 --- person vs. random computer\n");
  
    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You have entered choice 1: \n");
            printf("==========================\n");
            displayBoard();
            break;
        case 2:
            printf("You have entered choide 2: \n");
            printf("==========================\n");
            displayBoard();
            break;
        default:
            printf("Enter a valid choice\n");
    }

    // read information console


    return 0;
}