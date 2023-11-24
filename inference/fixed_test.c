#include <stdio.h>

#define FRACTIONAL_BITS 8

void floatToFixedPoint(float *floatArray, int *fixedPointArray, int size) {
    int i;
    float scale = 1 << FRACTIONAL_BITS;

    for (i = 0; i < size; ++i) {
        fixedPointArray[i] = (int)(floatArray[i] * scale);

    }

}

int main() {
    float floatArray[] = {-1.234, 5.678, 9.012};
    int size = sizeof(floatArray) / sizeof(float);

    int fixedPointArray[size];

    floatToFixedPoint(floatArray, fixedPointArray, size);

    printf("Original Float Array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%f ", floatArray[i]);

    }

    printf("\n\nFixed-Point Array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", fixedPointArray[i]);

    }

    return 0;

}

