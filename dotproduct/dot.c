#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 100

void dot_product(int arr1[HEIGHT][WIDTH], int arr2[HEIGHT][WIDTH], int result[HEIGHT][WIDTH]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int sum = 0;
            for (int k = 0; k < 100; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    // Example arrays (100x100)
    int array1[HEIGHT][WIDTH] = {{0}};
    int array2[HEIGHT][WIDTH] = {{0}};

    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            array1[i][j] = rand() % 100; // Random values between 0 and 99
            array2[i][j] = rand() % 100;
        }
    }

    // Result array for dot product
    int result[HEIGHT][WIDTH] = {{0}};

    // Calculate dot product for full 100x100 arrays
    dot_product(array1, array2, result);

    // Printing a sample of the result
    printf("Sample of the result:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
