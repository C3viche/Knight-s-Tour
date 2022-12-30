#include "board.h"
#include <stdio.h>
#include <stdlib.h>

Board make_board(int rows, int cols) {
    Board board;
    board.rows = rows;
    board.cols = cols;
    board.squares = cols * rows;
    board.arr = (int**)calloc(rows, sizeof(int*));
    for(int i = 0; i < rows; i++) {
        (board.arr)[i] = (int*)calloc(cols, sizeof(int));
    }
    
    // Fills board with zeroes
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            (board.arr)[r][c] = 0;
        }
    }

    return board;
}

void print_board(Board board) {
    for(int r = 0; r < board.rows; r++) {
        for(int c = 0; c < board.cols; c++) {
            printf("%d  ", board.arr[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}