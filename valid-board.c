//
// Created by Maks on 17.02.2023.
//

#include "valid-board.h"

int valid_row(int *tab, int row) {

    //0 = valid, 1 = invalid

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (*(tab + (9 * row) + i) == *(nums + j)) {
                *(nums + j) = -1;
                break;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (*(nums + i) != -1) {
            return 1;
        }
    }

    return 0;
}

int valid_column(int *tab, int column) {

    //0 = valid, 1 = invalid

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (*(tab + (9 * i) + column) == *(nums + j)) {
                *(nums + j) = -1;
                break;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (*(nums + i) != -1) {
            return 1;
        }
    }

    return 0;
}

int valid_box(int *tab, int box_column, int box_row) {

    //0 = valid, 1 = invalid

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = box_column * 3; i < (box_column + 1) * 3; i++) {
        for (int j = box_row * 3; j < (box_row + 1) * 3; j++) {
            for (int k = 0; k < 9; ++k) {

                if (*(tab + i * 9 + j) == *(nums + k)) {
                    *(nums + k) = -1;
                    break;
                }
            }
        }
    }


    for (int i = 0; i < 9; ++i) {
        if (*(nums + i) != -1) {
            return 1;
        }
    }

    return 0;

}

int valid_board(int *tab) {

    //0 = valid, 1 = invalid

    for (int i = 0; i < 9; ++i) {
        if (valid_column(tab, i) != 0 || valid_row(tab, i) != 0) {
            return 1;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (valid_box(tab, i, j) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
