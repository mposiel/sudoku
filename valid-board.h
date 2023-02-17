//
// Created by Maks on 17.02.2023.
//

#ifndef SUDOKU_VALID_BOARD_H
#define SUDOKU_VALID_BOARD_H

int valid_row(int* tab, int row);
int valid_column(int* tab, int column);
int valid_box(int* tab, int box_column, int box_row);
int valid_board(int* tab);


#endif //SUDOKU_VALID_BOARD_H
