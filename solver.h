//
// Created by Maks on 17.02.2023.
//

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H
int valid(int *tab, int num, int x, int y);
int find_empty(int *tab, int *x, int *y);
int solve(int *tab);
#endif //SUDOKU_SOLVER_H
