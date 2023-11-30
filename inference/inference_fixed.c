#include "../mnistviewer/mnist.h"
#include "parameters_fixed.h"
#include <math.h>


int sigmoid_single(int z) {
	double z_as_double = fixed_to_double(z);
	double sigmoid = 1.0 / (1.0 + exp(-z_as_double));
	return double_to_fixed(sigmoid);	
}


void sigmoid(int vec[30], int result[30], int height) {
	for(int i=0; i < height; i++) {
		 result[i] = sigmoid_single(vec[i]);
	}
}

void dot_product(int weights[30][784], int image[784], int result[30], int height, int size) {
	int dp = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < size; j++) {
			dp += weights[i][j] * image[j]; 
		}
		result[i] = dp;
		dp = 0;
	}
}

void vector_add(int a[30], int b[30][1], int result[30], int height) {
	for (int i = 0; i < height; i++) {
		result[i] = b[i][0] + a[i];
	}
}


int argmax(const int arr[], int size) {
	if (size <= 0) {
		fprintf(stderr, "Error: Invalid array size\n");
		return -1;
	}

	int max_index = 0;
	int max_value = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
			max_index = i;
		}
	}
	return max_index;
}

int feed_forward(int *input) {
	int res[784] = {0};
	int add_res[30] = {0};
	int dp_res[30] = {0};

	// Hidden layer (height is 30)
	const int height_hl = 30;
	int **biases_hl = biases[0];
	int **weights_hl = weights[0];
	dot_product(weights_hl, input, dp_res, height_hl, 784);
	vector_add(dp_res, biases_hl, add_res, height_hl);
	sigmoid(add_res, res, height_hl);

	// Output layer (height is 10)
	const int height_ol = 10;
	int **biases_ol = biases[1];
	int **weights_ol = weights[1];
	dot_product(weights_ol, input, dp_res, height_ol, 30);
	vector_add(dp_res, biases_ol, add_res, height_ol);
	sigmoid(add_res, res, height_ol);

	
	int output = argmax(res, height_ol);
	return output;
}


void evaluate() {
	int actual, output, counter = 0;
	for (int i = 0; i < 10000; i++) {
		actual = test_label[i];
    	output = feed_forward(test_image_fixed[i]);
		if (output == actual) {
			counter++;
		}
	}
	printf("Accuracy: %d/10000\n", counter);
}



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
/*
void evaluate_display() {
	int quit = 0;
	int i = 0;
	int output = 0;
	char response;
	
	while(!quit) {
		output = feed_forward(test_image[i]);
		printf("Current image index: %d, Output of NN: %d, Actual label: %d\n", i, output, test_label[i]);
		display_image(test_image[i]);
		printf("Show next image? (y/n)");
		scanf(" %c", &response);
		if (response == 'n' || response == 'N')
			quit = 1;
		i++;
		if(i >= 10000) {
			printf("End of images\n");
			break;
		}
	}
}*/

int main() {

    load_mnist();
    
    images_to_fixed(test_image, test_image_fixed);

	evaluate();

    return 0;
}
