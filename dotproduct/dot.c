#include <stdio.h>

#define WIDTH 800
#define HEIGHT 100

void dot_product(int arr1[HEIGHT][WIDTH], int arr2[HEIGHT][WIDTH], int result[HEIGHT][WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int sum = 0;
            for (int k = 0; k < 100; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

