#include "helper.h"
#include <stdio.h>

/*
    A couple of helper functions I created for knight's tour
*/

int least_pos_int(int* nums, int size) { // RETURNS INDEX OF LOWEST POS INT
    int least = nums[0];
    int index = 0;

    for(int i = 1; i < size; i++) {
        if(nums[i] == 0) {
            continue;
        }
        
        if(least == 0 && nums[i] > 0) { // if first num is zero, change it to first positive num encountered
            least = nums[i];
            index = i;
        }
        else if(nums[i] < least) { // changes num to lowest positive int
            least = nums[i];
            index = i;
        }
    }

    return index;
}

// returns true if position on board is possible after given set of moves
bool is_possible(Position* path, Position curr_pos, int move_num, Board board) {
    if(!in_board(board, curr_pos.y, curr_pos.x)) {
        return false;
    }
    
    for(int move = 0; move <= move_num; move++) {
        if((path[move]).x == curr_pos.x && (path[move]).y == curr_pos.y) {
            return false;
        }
    }
    return true;
}

// finds the weight of a square (curr_pos is the square examined)
int find_weight(Position curr_pos, Position* path, Board board, int move_num, int* x_moves, int* y_moves) {
    int weight = 0;
    Position temp_pos;

    if(!is_possible(path, curr_pos, move_num, board)) {
        return 0;
    }
    
    // find if all moves are possible and add to weight if it is
    for(int move = 0; move < 8; move++) {
        temp_pos.x = curr_pos.x + x_moves[move];
        temp_pos.y = curr_pos.y + y_moves[move];

        if(is_possible(path, temp_pos, move_num, board)) {
            weight++;
        }
    }

    return weight;
}

// prints path in chess terms
void print_path(Position* path, Board board, bool ended) {
    char letter_pos;
    int number_pos;

    if(ended == false) {
        printf("\nPath is not possible from this position");
    }
    else {
        printf("\n");
        print_board(board);
        printf("Here is the sequence of moves:\n");
        letter_pos = 'A' + (path[0]).x;
        number_pos = (path[0]).y + 1;
        printf("\tfrom %c %d\n", letter_pos, number_pos); //formatted letter and number position

        for(int pos = 1; pos < board.squares; pos++) { // go through rest of positions
            letter_pos = 'A' + (path[pos]).x;
            number_pos = (path[pos]).y + 1;
            printf("\tknight to %c %d\n", letter_pos, number_pos);
        }
    }
}

bool in_board(Board board, int row, int col) {
    if(col >= board.cols || col < 0 ||
        row >= board.rows || row < 0) {
        return false;
    }
    return true;
}