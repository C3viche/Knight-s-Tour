#ifndef HELPER_H
    #define HELPER_H
    
    #include "board.h"
    #include <stdbool.h>
    int least_pos_int(int* nums, int size);
    bool is_possible(Position* path, Position curr_pos, int move_num, Board board);
    int find_weight(Position curr_pos, Position* path, Board board, int move_num, int* x_moves, int* y_moves);
    void print_path(Position* path, Board board, bool ended);
    bool in_board(Board board, int row, int col);

#endif