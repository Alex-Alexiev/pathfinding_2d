#include <stdio.h>

#include "Array2dUtil.h"

void utArray2d_print(int *arr, int rows, int cols){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            printf("%d ", *(arr + r*cols + c));
        }
        printf("\n");
    }
}