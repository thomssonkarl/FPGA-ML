#include "../mnistviewer/mnist.h"
#include "parameters.h"
#include <math.h>

#define WEIGHTS_SIZE 784
#define LAYERS_SIZE 2

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double dp(double **a, double b) {
	
}

int feed_forward(double * in) {
	for (int layer = 0; layer < LAYERS_SIZE; layer++) {
		double **bias = biases[layer]; //kolonnvektor
		double **weight = weights[layer];
		//dot product
	}
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
