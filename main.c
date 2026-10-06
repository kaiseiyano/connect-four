#include <stdio.h>
#include <stdbool.h>


/* 
    Logic to validate the win (four in a row)
    Take in the x and y coordinates as input, as well as board as a 2D array.
    Before each check, validate that the end coordinates are within the range of the board   
    Returns false if no conditions are met 
*/
void validateWin(int board[6][7], int r, int c){
    int width = 7; 
    int height = 6; 

    // Check horizontally 
    int i = c;
    while (i < c + 4){
        printf("%d \n", board[r][i]); 
        if (i == width || board[r][c] != board[r][i]){
            break; 
        }
        i++; 
    }
    if (i == c + 4){
        printf("True \n"); 
    } else {
        printf("False \n"); 
    }
    i = c;
    while (i > c - 4){
        printf("%d \n", board[r][i]); 
        if (i < 0 || board[r][c] != board[r][i]){
            break; 
        }
        i--; 
    }
    if (i == c - 4){
        printf("True \n"); 
    } else {
        printf("False \n"); 
    }

    // Check vertically 
    i = r;
    while (i > r - 4){
        printf("%d \n", board[i][c]); 
        if (i == height || board[r][c] != board[i][c]){
            break; 
        }
        i--; 
    }
    if (i == r - 4){
        printf("True \n"); 
    } else {
        printf("False \n"); 
    }
    i = r;
    while (i < r + 4){
        printf("%d \n", board[i][c]); 
        if (i == height || board[r][c] != board[i][c]){
            break; 
        }
        i++; 
    }
    if (i == r + 4){
        printf("True \n"); 
    } else {
        printf("False \n"); 
    }
}

int main(void) {

    int board[6][7] = {
        {1, 1, 1, 1, 1, 0, 1},  
        {0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 1, 1, 1, 1, 1}, 
        {0, 0, 0, 0, 0, 0, 1}, 
        {0, 1, 1, 1, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 1},  
    };

    validateWin(board, 2, 6);

    return 0;
}

