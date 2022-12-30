#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
    brute force approach >:)
*/

typedef struct Position_Struct {
    int x;
    int y;
} Position;

typedef struct Board_Struct {
    int dimensions;
    int** arr;
} Board;

Board make_board(int dimensions) {
    Board board;
    board.dimensions = dimensions;
    board.arr = (int**)calloc(dimensions, sizeof(int*));
    for(int i = 0; i < dimensions; i++) {
        (board.arr)[i] = (int*)calloc(dimensions, sizeof(int));
    }
    
    for(int r = 0; r < dimensions; r++) {
        for(int c = 0; c < dimensions; c++) {
            (board.arr)[r][c] = 0;
        }
    }

    return board;
}

void print_board(Board board) {
    for(int r = 0; r < board.dimensions; r++) {
        for(int c = 0; c < board.dimensions; c++) {
            printf("%d  ", board.arr[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_possible(Position* path, Position curr_pos, int move_num) {
    if(curr_pos.x > 4 || curr_pos.x < 0 ||
        curr_pos.y > 4 || curr_pos.y < 0) {
        return false;
    }
    
    for(int move = 0; move < move_num; move++) {
        if((path[move]).x == curr_pos.x && (path[move]).y == curr_pos.y) {
            return false;
        }
    }
    return true;
}

void knight_tour(Position curr_pos, int move_num, bool *ended, Position* path, int* x_moves, int* y_moves, Board board) {
    // base case: function must end if the all 64 squares have been touched
    if(move_num == 25) {
        *ended = true;
    }

    if(!(*ended)) {
        for(int move = 0; move < 8; move++) {
            // change curr position for reccursive function call
            curr_pos.x += x_moves[move];
            curr_pos.y += y_moves[move];
            
            if(is_possible(path, curr_pos, move_num)) {
                path[move_num] = curr_pos;
                (board.arr)[curr_pos.x][curr_pos.y] = move_num + 1;
                print_board(board);
                
                knight_tour(curr_pos, move_num + 1, ended, path, x_moves, y_moves, board);
                
                if(!(*ended)) {
                    (board.arr)[curr_pos.x][curr_pos.y] = 0; // change space back to empty space
                }
            }
            
                // revert position back to previous
                curr_pos.x -= x_moves[move];
                curr_pos.y -= y_moves[move]; 

            if(*ended) { // if end reached, break out of function instance in recursive tunnel to quickly go to print statements
                return;
            }
        }
    }
}

void print_path(Position* path, bool ended) {
    char letter_pos;
    int number_pos;

    if(ended == false) {
        printf("\nPath is not possible from this position");
    }
    else {
        printf("\nHere is the sequence of moves:\n");
        letter_pos = 'A' + (path[0]).x;
        number_pos = (path[0]).y + 1;
        printf("\tfrom %c %d\n", letter_pos, number_pos); //formatted letter and number position

        for(int pos = 1; pos < 25; pos++) { // go through rest of positions
            letter_pos = 'A' + (path[pos]).x;
            number_pos = (path[pos]).y + 1;
            printf("\tknight to %c %d\n", letter_pos, number_pos);
        }
    }
}

int main() {
    // List of positions that stores the path of the knight
    Position* path = (Position*)calloc(25, sizeof(Position));
    Board board = make_board(5);
    
    // Possible x and y moves that the knight can take
    int x_moves[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int y_moves[8] = {2, 2, 1, -1, -2, -2, -1, 1};

    Position start;
    Position curr_pos;
    int move_num = 1;
    bool ended = false;

    // Take input for the starting position
    printf("Enter start position on the board (x, y): ");
    scanf("%d, %d", &(start.x), &(start.y));
    
    path[0] = start;
    board.arr[start.x][start.y] = move_num; //print board for first time
    print_board(board);
    curr_pos.x = start.x; curr_pos.y = start.y;
    
    // Call knight's tour!!
    knight_tour(curr_pos, move_num, &ended, path, x_moves, y_moves, board);

    print_path(path, ended);

    return 0;
}

/*
    - Implement find weight function to find num of following moves each space allows
        - go to space with lowest weight (greater than 0)
    - weights stored in array
    - go to space with next lowest weight if previous one doesn't work out
*/