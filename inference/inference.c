#include "../mnistviewer/mnist.h"
#include "parameters.h"
#include <math.h>

#define WEIGHTS_SIZE 784

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}




int main() {
    load_mnist();
    int actual = test_label[0];
    double *input = test_image[0];
    int input_size = WEIGHTS_SIZE; 
    int output = feed_forward(input, input_size);

    printf("Output from NN: %d\n", output);
    printf("Actual: %d\n", actual);

    return 0;
}
