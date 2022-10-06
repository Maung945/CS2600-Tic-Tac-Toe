// Tick Tac Toe game between 2 players or player vs computer
#include <stdio.h>
int main() {
    // prompt user for game they wish to play
    printf("   WELCOME TO TIC-TAC-TOE    \n");
    printf("1 --- person vs. person\n");
    printf("2 --- person vs. random computer\n");
  
    int choice;
    printf("Enter a choice now: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("person to person\n");
            break;
        case 2:
            printf("Person vs computer\n");
            break;
        default:
            printf("Enter a valid choice\n");
    }

    // read information console


    return 0;
}