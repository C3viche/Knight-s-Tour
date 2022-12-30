#include "board.h"
#include "helper.h"
#include "input_validation.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Optimized version of knight's tour where certain paths are
    chosen over others rather than a static order.

    Implement find weight function to find num of following moves each space allows
    - go to space with lowest weight (greater than 0)
    - weights stored in array
    - go to space with next lowest weight if previous one doesn't work out

    this will allow the knight to traverse the board through spots that have low potential moves to use them up. this
    will make it easier for the knight to travel later on when the board fills up with visited spots.
*/

void knight_tour(Position curr_pos, int move_num, bool *ended, Position* path, int* x_moves, int* y_moves, Board board) {
    // base case: function must end if the all 64 squares have been touched
    if(move_num == board.squares) {
        *ended = true;
    }

    if(!(*ended)) {
        Position temp_pos;
        int weights[8];
        int least;

        if(move_num == board.squares - 1) { // last move will have weights of all 0 WHEN MOVE_NUM == dimensions squared - 1
            for(int i = 0; i < 8; i++) {
                temp_pos.x = curr_pos.x + x_moves[i];
                temp_pos.y = curr_pos.y + y_moves[i];
                
                if(is_possible(path, temp_pos, move_num, board)) { // find last possible move normally and move knight
                    curr_pos.x = temp_pos.x;
                    curr_pos.y = temp_pos.y;

                    path[move_num] = curr_pos;
                    (board.arr)[curr_pos.y][curr_pos.x] = move_num + 1;
                    //print_board(board);

                    knight_tour(curr_pos, move_num + 1, ended, path, x_moves, y_moves, board);
                    return;
                }
            }
        }

        // Calculate weights for all moves except last one
        for(int move = 0; move < 8; move++) {
            temp_pos.x = curr_pos.x + x_moves[move];
            temp_pos.y = curr_pos.y + y_moves[move];
            
            weights[move] = find_weight(temp_pos, path, board, move_num, x_moves, y_moves);
        }

        for(int weight = 0; weight < 8; weight++) {
            least = least_pos_int(weights, 8);

            if(weights[least] == 0) {
                return; // break out of function instance if all weights are 0
            }
            
            // change curr position for reccursive function call
            curr_pos.x += x_moves[least];
            curr_pos.y += y_moves[least];
            
            path[move_num] = curr_pos;
            (board.arr)[curr_pos.y][curr_pos.x] = move_num + 1;
            //print_board(board);
                
            knight_tour(curr_pos, move_num + 1, ended, path, x_moves, y_moves, board);
                
            if(!(*ended)) {
                (board.arr)[curr_pos.x][curr_pos.y] = 0; // change space back to empty space
                weights[least] = 0; // change weight to 0 to tell computer to not check it again

                // revert position back to previous
                curr_pos.x -= x_moves[least];
                curr_pos.y -= y_moves[least]; 
            }
            else { // if end reached, break out of function instance in recursive tunnel to quickly go to print statements
                return;
            }
        }
    }
}

int main() {
    // Prompt for board dimensions
    int rows; int cols;
    
    rows = getPosInt("Enter the number of rows on the board: ");
    cols = getPosInt("Enter the number of columns on the board: ");
    
    // List of positions that stores the path of the knight
    Position* path = (Position*)calloc(rows * cols, sizeof(Position));
    Board board = make_board(rows, cols);
    
    // Possible x and y moves that the knight can take
    int x_moves[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int y_moves[8] = {2, 2, 1, -1, -2, -2, -1, 1};

    Position start;
    Position curr_pos;
    int move_num = 1;
    bool ended = false;

    // Take input for the starting position where 0, 0 is lower left
    do {
        start.x = getValidInt("Enter starting x position on the board: ");
    } while(!inbetween(start.x, 0, board.cols - 1));
    
    do {
        start.y = getValidInt("Enter starting y position on the board: ");
    } while(!inbetween(start.y, 0, board.rows - 1));
    
    path[0] = start;
    board.arr[start.y][start.x] = move_num;
    curr_pos.x = start.x; curr_pos.y = start.y;
    
    // Call knight's tour!!
    knight_tour(curr_pos, move_num, &ended, path, x_moves, y_moves, board);

    print_path(path, board, ended);

    return 0;
}