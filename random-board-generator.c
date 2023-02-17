//
// Created by Maks on 17.02.2023.
//

#include "random-board-generator.h"
#include "solver.h"
#include <stdlib.h>
#include <time.h>


void board_generator(int *tab) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            *(tab + (i*9) +j) = 0;
        }
    }

    srand(time(NULL));

    int counter = 25;

//    switch (level) {
//        case 1:
//            counter = rand() % 5 + 38;
//            break;
//        case 2:
//            counter = rand() % 4 + 34;
//            break;
//        case 3:
//            counter = rand() % 6 + 28;
//            break;
//        case 4:
//            counter = rand() % 4 + 23;
//            break;
//        case 5:
//            counter = rand() % 3 + 21;
//            break;
//    }

    int cords[counter][2];
    for (int i = 0; i < counter; i++) {
        int num1 = rand() % 8;
        int num2 = rand() % 8;


        for (int j = 0; j < i; j++) {
            if (cords[j][0] == num1 && cords[j][1] == num2) {

                num1 = rand() % 8;
                num2 = rand() % 8;
                j = -1;
            }
        }


        cords[i][0] = num1;
        cords[i][1] = num2;

    }
    int temp = 0;

    while(1) {
        if (temp == counter) {
            break;
        }

        int value = rand() % 9 + 1;

        if (valid(tab,value,cords[temp][0], cords[temp][1]) == 1) {
            *(tab+(cords[temp][0] * 9) + cords[temp][1]) = value;
            temp++;
        }
    }
}