#include "../mnistviewer/mnist.h"
#include <stdint.h>
#include <string.h>
#include "parameters_split_double.h"
#include <math.h>

#define INPUT_SIZE 10000
typedef double number_t;
typedef int32_t fixed_point_t;
#define FIXED_POINT_FRACTIONAL_BITS 16 

number_t sigmoid_single(number_t z) {
	return 1.0 / (1.0 + exp(-z));
}

void sigmoid(number_t vec[30], number_t result[30], size_t height) {
	for(size_t i=0; i < height; i++) {
		 result[i] = sigmoid_single(vec[i]);
	}
}

void dot_product(number_t weights[30][784], number_t image[784], number_t result[30], size_t height, size_t size) {
	number_t dp = 0;
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < size; j++) {
			dp += weights[i][j] * image[j]; 
		}
		result[i] = dp;
		dp = 0;
	}
}

void vector_add(number_t a[30], number_t b[30][1], number_t result[30], size_t height) {
    for (size_t i = 0; i < height; i++) {
		result[i] = b[i][0] + a[i];
    }
}


size_t argmax(const number_t arr[], size_t size) {
	if (size <= 0) {
		fprintf(stderr, "Error: Invalid array size\n");
		return -1;
	}

	size_t max_index = 0;
	number_t max_value = arr[0];
	for (size_t i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
			max_index = i;
		}
	}
	return max_index;
}

size_t feed_forward(number_t input[784]) {
	number_t res[30] = {0};
	number_t add_res[30] = {0};
	number_t dp_res[30] = {0};

	// Hidden layer
	const size_t height_hl = 30;
	const size_t width_hl = 784;
	dot_product(weights_hl, input, dp_res, height_hl, width_hl);
	vector_add(dp_res, biases_hl, add_res, height_hl);
	sigmoid(add_res, res, height_hl);

	// Output layer
	const size_t height_ol = 10;
	const size_t width_ol = 30;
	dot_product(weights_ol, res, dp_res, height_ol, width_ol);
	vector_add(dp_res, biases_ol, add_res, height_ol);
	sigmoid(add_res, res, height_ol);
	
	return argmax(res, height_ol);
}


void evaluate() {
	size_t actual, output, counter = 0;

	for (int i = 0; i < INPUT_SIZE; i++) {
		actual = test_label[i];
    	output = feed_forward(test_image[i]);
        if (output == actual) {
			counter++;
		}
	}
	printf("Accuracy: %zu/%d\n", counter, INPUT_SIZE);
}


double f2d(fixed_point_t input) {
	return ((double)input / (double)(1 << FIXED_POINT_FRACTIONAL_BITS));
}


fixed_point_t d2f(double input) {
	return (fixed_point_t)(input * (1 << FIXED_POINT_FRACTIONAL_BITS));
}


fixed_point_t mul_fixed(fixed_point_t a, fixed_point_t b) {
	int32_t result = (int32_t)a * b;
	result >>= FIXED_POINT_FRACTIONAL_BITS;
	return (fixed_point_t)result;
}


int main() {
    load_mnist();
	evaluate();
    return 0;
}
