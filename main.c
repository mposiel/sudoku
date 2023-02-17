#include <stdio.h>
#include "valid-board.h"
#include "solver.h"


void print_tab(int *tab) {
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
    int tab[9][9] = {{0, 0, 0, 3, 5, 0, 0, 0, 1},
                     {6, 0, 3, 0, 1, 4, 0, 0, 0},
                     {0, 1, 4, 0, 0, 0, 0, 7, 3},
                     {2, 8, 0, 1, 0, 3, 0, 0, 9},
                     {0, 0, 6, 0, 0, 0, 0, 0, 2},
                     {7, 0, 1, 0, 2, 0, 0, 5, 0},
                     {9, 5, 2, 4, 7, 1, 0, 0, 0},
                     {0, 0, 0, 0, 0, 2, 0, 0, 0},
                     {0, 0, 0, 0, 0, 5, 9, 2, 0}
    };

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
            printf("\nBrawo!\n");
        }


        print_tab(player_tab);
        int opcja;
        while (1) {
            printf("Wybierz opcje:\n1. Wstaw liczbe\n2. Usun liczbe\n3. Pokaz poczatkowa plansze\n4. Pokaz rozwiazanie\n5. Zakoncz gre\nOpcja nr:");

            if (scanf("%d", &opcja) != 1) {
                printf("Wpisz liczbe od 1 do 5!");
                continue;
            }
            if (opcja != 1 && opcja != 2 && opcja != 3 && opcja != 4 && opcja != 5) {
                printf("Wpisz liczbe od 1 do 5!");
                continue;
            }

            break;
        }

        if (opcja == 1) {
            int row, column, val;
            while (1) {

                while (1) {
                    printf("Podaj numer rzedu:");
                    if (scanf("%d", &row) != 1) {
                        printf("Podaj liczbe od 1 do 9!\n");
                        continue;
                    }
                    if (row < 1 || row > 9) {
                        printf("Podaj liczbe od 1 do 9!\n");
                        continue;
                    }
                    row--;
                    break;

                }

                while (1) {
                    printf("Podaj numer kolumny:");
                    if (scanf("%d", &column) != 1) {
                        printf("Podaj liczbe od 1 do 9!");
                        continue;
                    }
                    if (column < 1 || column > 9) {
                        printf("Podaj liczbe od 1 do 9!");
                        continue;
                    }
                    column--;
                    break;
                }

                int flag = 0;

                for (int i = 0; i < predetermined_counter; ++i) {
                    if (row == predetermined_cord[i][0] && column == predetermined_cord[i][1]) {
                        printf("Tej liczby nie mozna zmienic!\n");
                        flag++;
                    }
                }

                if (flag != 0) {
                    continue;
                } else {
                    while (1) {
                        printf("Podaj liczbe od 1 do 9:");
                        if (scanf("%d", &val) != 1) {
                            printf("\nWartosca musi byc liczba w przedziale od 1 do 9!");
                            continue;
                        }
                        if (val < 1 || val > 9) {
                            printf("\nWartosca musi byc liczba w przedziale od 1 do 9!");
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
                    printf("\nNajpierw wstaw liczbe!\n\n");
                    break;
                }

                while (1) {
                    printf("Podaj numer rzedu:");
                    if (scanf("%d", &row) != 1) {
                        printf("Podaj liczbe od 1 do 9!\n");
                        continue;
                    }
                    if (row < 1 || row > 9) {
                        printf("Podaj liczbe od 1 do 9!\n");
                        continue;
                    }
                    row--;
                    break;

                }

                while (1) {
                    printf("Podaj numer kolumny:");
                    if (scanf("%d", &column) != 1) {
                        printf("Podaj liczbe od 1 do 9!");
                        continue;
                    }
                    if (column < 1 || column > 9) {
                        printf("Podaj liczbe od 1 do 9!");
                        continue;
                    }
                    column--;
                    break;
                }

                int flag = 0;

                for (int i = 0; i < predetermined_counter; ++i) {
                    if (row == predetermined_cord[i][0] && column == predetermined_cord[i][1]) {
                        printf("Tej liczby nie mozna zmienic!\n");
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
            printf("\nPoczatkowa plansza:\n\n");
            print_tab(&tab);
            printf("Twoja plansza:\n\n");
        } else if (opcja == 4) {
            printf("\nRozwiazanie:\n\n");
            solve(player_tab);
            print_tab(player_tab);
            printf("Koniec gry!");
            break;
        } else if (opcja == 5) {
            printf("Koniec gry!");
            break;
        }


    }


    return 0;
}
