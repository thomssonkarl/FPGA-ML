#include <stdio.h>
#include "mnist.h"

void print_colored_pixel(double value) {
    int color_code = (int)(value * 255);
    printf("\x1b[48;2;%d;%d;%dm  ", color_code, color_code, color_code);
}

void display_image(double *image) {
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            print_colored_pixel(image[i * 28 + j]);
        }
        printf("\n");
    }
}

int main() {
    load_mnist();
    unsigned int quit = 0;
    unsigned int i = 0;
    char response;

    while (!quit) {
        printf("Label for the image: %d\n", test_label[i]);
        display_image(&test_image[i][0]);

        printf("Show next image? (y/n): ");
        scanf(" %c", &response);

        if (response == 'n' || response == 'N') {
            quit = 1;
        }

        i++;
        if (i >= 10000) {
            printf("End of images\n");
            break;
        }
    }

    return 0;
}
