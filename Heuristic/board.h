#ifndef BOARD_H
    #define BOARD_H
    
    typedef struct Position_Struct {
        int x;
        int y;
    } Position;

    typedef struct Board_Struct {
        int rows;
        int cols;
        int squares;
        int** arr;
    } Board;

    Board make_board(int rows, int cols);
    void print_board(Board board);

#endif 