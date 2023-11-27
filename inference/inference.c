#include "../mnistviewer/mnist.h"
#include "parameters.h"
#include <math.h>

#define WEIGHTS_SIZE 784
#define LAYERS_SIZE 2
#define BIAS_WIDTH 1

double sigmoid_single(double z) {
	return 1.0 / (1.0 + exp(-z));
}

void sigmoid(double **x, double **res) {
	int height;
	for(int i=0; i < BIAS_WIDTH; i++) {
		height = sizeof(x[i]) / sizeof(double);
		for(int j=0; j < height; j++) {
			res[i][j] = sigmoid_single(x[i][j]);
		}
    	}
}

double dp(double **a, double **b) {
	return 0;
}

void vector_add(double a, double **b, double **add_res) {
	add_res = b;
}

int feed_forward(double * in) {
	double **res = {{1}}; //TODO
	double **add_res = {{1}}; //TODO
	for (int layer = 0; layer < LAYERS_SIZE; layer++) {
		double **bias = biases[layer]; //kolonnvektor
		double **weight = weights[layer];
		//dot product
		double dot = dp(weight, res);
		vector_add(dot, bias, add_res);
		sigmoid(add_res, res);
	}
	return res[0][0]; //dont worry about this
}


int main() {
    load_mnist();
    int actual = test_label[0];
    double *input = test_image[0];
    int input_size = WEIGHTS_SIZE; 
    int output = feed_forward(input);

    printf("Output from NN: %d\n", output);
    printf("Actual: %d\n", actual);

    return 0;
}
