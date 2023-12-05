#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 100

void dot_product(int arr1[HEIGHT][WIDTH], int arr2[HEIGHT][WIDTH], int result[HEIGHT][WIDTH], int height, int width);

int main() {
    // Example arrays (100x100)
    int array1[HEIGHT][WIDTH] = {{0}};
    int array2[HEIGHT][WIDTH] = {{0}};

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            array1[i][j] = i % 100; // Random values between 0 and 99
            array2[i][j] = j % 100;
        }
    }

    // Result array for dot product
    int result[HEIGHT][WIDTH] = {{0}};

    // Calculate dot product for full 100x100 arrays
    dot_product(array1, array2, result, HEIGHT, WIDTH);

    // Printing a sample of the result
    printf("Sample of the result:\n");
    for (int k = 0; k < 5; k++) {
        for (int l = 0; l < 5; l++) {
            printf("%d\t", result[k][l]);
        }
        printf("\n");
    }

    return 0;
}
