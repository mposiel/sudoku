#include <stdio.h>
#include "valid-board.h"
#include "solver.h"
#include "random-board-generator.h"


void print_tab(int* tab) {

    printf("    1 2 3   4 5 6   7 8 9  \n");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (j == 0) {
                printf("%d ", i + 1);
            }
            if (j % 3 == 0) {
                printf("| ");
            }
            if (*(tab + (i * 9) + j) == 0) {
                printf("_ ");
            } else {
                printf("%d ", *(tab + (i * 9) + j));
            }
        }
        printf("|\n");
        if ((i + 1) % 3 == 0 && i != 8) {
            printf("  -  -  -  -  -  -  -  -  -\n");
        } else if (i == 8) {
            printf("\n");
        }
    }
}

int main() {


    int tab[9][9];
    board_generator(tab);

    while(1) {
        if (solvable(tab)==0) {
            board_generator(tab);
        } else {
            break;
        }
    }


    int predetermined_counter = 0;

    int player_tab[9][9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            player_tab[i][j] = tab[i][j];

            if (tab[i][j] != 0) {
                predetermined_counter++;
            }

        }
    }


    int predetermined_cord[predetermined_counter][2], temp_counter = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (tab[i][j] != 0) {
                predetermined_cord[temp_counter][0] = i;
                predetermined_cord[temp_counter][1] = j;
                temp_counter++;
            }
        }
    }

    int inserted_counter = 0;

    while (1) {

        if (valid_board(player_tab) == 0) {
            printf("\nGood job!\n");
        }
        if(inserted_counter+predetermined_counter==81) {
            printf("\nGame over!\n");
        }


        print_tab(player_tab);

        int opcja;
        while (1) {
            printf("Choose an option:\n1. Insert number\n2. Delete number\n3. Show the initial board\n4. Show solution\n5. End the game\nOption number:");

            if (scanf("%d", &opcja) != 1) {
                printf("Enter a number from 1 to 5!\n");
                while (getchar() != '\n') continue;
                continue;
            }

            if (opcja < 1 || opcja > 5) {
                printf("Enter a number from 1 to 5!\n");
                continue;
            }

            break;
        }


        if (opcja == 1) {
            int row, column, val;
            while (1) {

                while (1) {
                    printf("Enter row number:");
                    if (scanf("%d", &row) != 1) {
                        printf("Enter a number from 1 to 9!\n");
                        while (getchar() != '\n') continue;
                        continue;
                    }
                    if (row < 1 || row > 9) {
                        printf("Enter a number from 1 to 9!\n");
                        continue;
                    }
                    row--;
                    break;

                }

                while (1) {
                    printf("Enter column number:");
                    if (scanf("%d", &column) != 1) {
                        printf("Enter a number from 1 to 9!\n ");
                        while (getchar() != '\n') continue;
                        continue;
                    }
                    if (column < 1 || column > 9) {
                        printf("Enter a number from 1 to 9!\n");
                        continue;
                    }
                    column--;
                    break;
                }

                int flag = 0;

                for (int i = 0; i < predetermined_counter; ++i) {
                    if (row == predetermined_cord[i][0] && column == predetermined_cord[i][1]) {
                        printf("This number cannot be changed!\n");
                        flag++;
                    }
                }

                if (flag != 0) {
                    continue;
                } else {
                    while (1) {
                        printf("Enter a number from 1 to 9:");
                        if (scanf("%d", &val) != 1) {
                            printf("The value must be a number between 1 and 9!\n");
                            while (getchar() != '\n') continue;
                            continue;
                        }
                        if (val < 1 || val > 9) {
                            printf("The value must be a number between 1 and 9!\n");
                            continue;
                        }
                        break;

                    }
                    player_tab[row][column] = val;
                    inserted_counter++;
                    break;
                }

            }


        } else if (opcja == 2) {

            int row, column;
            while (1) {
                if (inserted_counter == 0) {
                    printf("\nPut in the number first!\n");
                    break;
                }

                while (1) {
                    printf("Enter row number:");
                    if (scanf("%d", &row) != 1) {
                        printf("Enter a number from 1 to 9!\n");
                        while (getchar() != '\n') continue;
                        continue;
                    }
                    if (row < 1 || row > 9) {
                        printf("Enter a number from 1 to 9!\n");
                        continue;
                    }
                    row--;
                    break;

                }

                while (1) {
                    printf("Enter column number:");
                    if (scanf("%d", &column) != 1) {
                        printf("Enter a number from 1 to 9!\n");
                        while (getchar() != '\n') continue;
                        continue;
                    }
                    if (column < 1 || column > 9) {
                        printf("Enter a number from 1 to 9!\n");
                        continue;
                    }
                    column--;
                    break;
                }

                int flag = 0;

                for (int i = 0; i < predetermined_counter; ++i) {
                    if (row == predetermined_cord[i][0] && column == predetermined_cord[i][1]) {
                        printf("This number cannot be changed!\n");
                        flag++;
                    }
                }

                if (flag != 0) {
                    continue;
                } else {

                    player_tab[row][column] = 0;
                    inserted_counter--;
                    break;
                }

            }
        } else if (opcja == 3) {
            printf("\nStarting board:\n\n");
            print_tab(&tab);
            printf("Your board:\n\n");
        } else if (opcja == 4) {
            printf("\nSolution:\n\n");
            solve(tab);
            print_tab(tab);
            printf("Game over!");
            break;
        } else if (opcja == 5) {
            printf("Game over!");
            break;
        }


    }

    return 0;
}
