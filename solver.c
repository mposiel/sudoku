//
// Created by Maks on 17.02.2023.
//

#include "solver.h"

int valid(int *tab, int num, int x, int y) {
    // Sprawdzamy wiersz
    for (int i = 0; i < 9; i++) {
        if (*(tab + (x * 9) + i) == num && i != y) {
            return 0;
        }
    }

    // Sprawdzamy kolumnę
    for (int i = 0; i < 9; i++) {
        if (*(tab + (i * 9) + y) == num && i != x) {
            return 0;
        }
    }

//    Sprawdzamy kwadrat
    int box_x = x / 3;
    int box_y = y / 3;
    for (int i = box_x * 3; i < (box_x + 1) * 3; i++) {
        for (int j = box_y * 3; j < (box_y + 1) * 3; j++) {
            if (*(tab + i * 9 + j) == num && (i != x || j != y)) {
                return 0;
            }
        }
    }



    return 1;
}

int find_empty(int *tab, int *x, int *y) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (*(tab + (i * 9) + j) == 0) {
                *x = i;
                *y = j;
                return 1;
            }
        }
    }
    return 0;
}


int solve(int *tab) {
    int x, y;
    if (find_empty(tab, &x, &y) == 0) {
        return 1;
    }
    for (int i = 1; i < 10; ++i) {
        if (valid(tab, i, x, y) == 1) {
            *(tab+(x*9)+y) = i;
            if(solve(tab)==1) {
                return 1;
            }
            *(tab+(x*9)+y) = 0;
        }
    }
    return 0;
}
