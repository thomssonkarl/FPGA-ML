#include "../mnistviewer/mnist.h"
#include "parameters.h"
#include <math.h>

#define WEIGHTS_SIZE 784
#define LAYERS_SIZE 2
#define BIAS_WIDTH 1
#define LAYER_1_HEIGHT 30
#define LAYER_2_HEIGHT 10
#define HEIGHTS {LAYER_1_HEIGHT, LAYER_2_HEIGHT}


double sigmoid_single(double z) {
	//TODO: Usually is called with very high/low value of z resulting in exp = 0.0
	printf("Called with: %f\n", z);
	double result = 1.0 / (1.0 + exp(-z));

	printf("Returning: %e\n", result);
	return result;
}


void sigmoid(double vec[][WEIGHTS_SIZE], double res[][WEIGHTS_SIZE], int height) {
	for(int i=0; i < BIAS_WIDTH; i++) {
		for(int j=0; j < height; j++) {
			double sig = sigmoid_single(vec[i][j]);
			res[i][j] = sig;
		}
    }
}

double dot_product(double **weights, double *image) {
	double result = 0.0;
	for (int i = 0; i < WEIGHTS_SIZE; i++) {
		result += weights[0][i] * image[i]; 
	}
	return result;
}

void vector_add(double a, double **b, double add_res[][WEIGHTS_SIZE], int height) {
	for (int i = 0; i < BIAS_WIDTH; i++) {
		for (int j = 0; j < height; j++) {
			add_res[i][j] = b[i][j] + a;
		}
	}
}

void show_result_vec(double res[BIAS_WIDTH][WEIGHTS_SIZE]) {
	for (int i = 0; i < BIAS_WIDTH; i++) {
		for (int j = 0; j < WEIGHTS_SIZE; j++) {
			printf("%e\n", res[i][j]);
		}
	}
}

int feed_forward(double *input) {
	double res[BIAS_WIDTH][WEIGHTS_SIZE] = {{0}};
	double add_res[BIAS_WIDTH][WEIGHTS_SIZE] = {{0}};
	int heights[] = HEIGHTS;

	for (int layer = 0; layer < LAYERS_SIZE; layer++) {
		int LAYER_HEIGHT = heights[layer];
		double **bias = biases[layer];
		double **weight = weights[layer];

		double dp = dot_product(weight, input);
		vector_add(dp, bias, add_res, LAYER_HEIGHT);
		sigmoid(add_res, res, LAYER_HEIGHT);

	}
	show_result_vec(res);
	return res[0][0];
}


int main() {

    load_mnist();
    int actual = test_label[0];
    double *input = test_image[0];

    int output = feed_forward(input);

    printf("Output from NN: %d\n", output);
    printf("Actual: %d\n", actual);

    return 0;
}
