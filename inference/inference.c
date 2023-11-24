#include "../mnistviewer/mnist.h"
#include "parameters.h"

int feed_forward(double *input) {
    
}

int main() {

    const double *input = test_image[0];

    int output = feed_forward(input);

    printf("Output from NN: %d\n", output);

    return 0;
}
