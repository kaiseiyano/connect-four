#include <stdio.h>
#include <stdbool.h> 

int main(void) {
    printf("Hello world!");

    return 0;
}

/* 
    Logic to validate the win (four in a row)
    Take in the x and y coordinates as input, as well as board as a 2D array.
    Before each check, validate that the end coordinates are within the range of the board   
    Returns false if no conditions are met 
*/
bool validateWin(int board[6][7], int x, int y){
    int width = 7; 
    int height = 6; 

    return false; 
}