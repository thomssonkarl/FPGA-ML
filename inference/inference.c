#include "../mnistviewer/mnist.h"
#include "parameters.h"
#include <math.h>

#define INPUT_SIZE 784
#define LAYERS_SIZE 2
#define BIAS_WIDTH 1
#define LAYER_1_HEIGHT 30
#define LAYER_2_HEIGHT 10
#define SIZES {LAYER_1_HEIGHT, LAYER_2_HEIGHT}


double sigmoid_single(double z) {
	return 1.0 / (1.0 + exp(-z));
}


void sigmoid(double vec[LAYER_1_HEIGHT][1], double res[LAYER_1_HEIGHT][INPUT_SIZE], int height) {
	for(int i=0; i < BIAS_WIDTH; i++) {
		for(int j=0; j < height; j++) {
			double sig = sigmoid_single(vec[i][j]);
			res[i][j] = sig;
		}
    }
}

void dot_product(double **weights, double *image, double res_vec[][1], int height, int iter) {
	double result = 0.0;
	int size;
	if (iter == 0) {
		size = INPUT_SIZE;
	}
	if (iter == 1) {
		size = LAYER_1_HEIGHT;
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < size; j++) {
			result += weights[i][j] * image[j]; 
		}
		res_vec[i][0] = result;
		result = 0.0;
	}
}

void vector_add(double a[LAYER_1_HEIGHT][1], double **b, double add_res[LAYER_1_HEIGHT][1], int height) {
	for (int j = 0; j < height; j++) {
		add_res[j][0] = b[j][0] + a[j][0];
	}
}

void show_result_vec(double res[BIAS_WIDTH][INPUT_SIZE]) {
	for (int i = 0; i < BIAS_WIDTH; i++) {
		for (int j = 0; j < LAYER_1_HEIGHT; j++) {
			printf("%e\n", res[i][j]);
		}
	}
}


void show_add_vec(double add_vec[LAYER_1_HEIGHT][1]) {
	for(int i = 0; i < 30; i++) {
		printf("%e\n", add_vec[i][0]);
	}
}


int argmax(const double arr[], int size) {
	if (size <= 0) {
		fprintf(stderr, "Error: Invalid array size\n");
		return -1;
	}

	int max_index = 0;
	double max_value = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
			max_index = i;
		}
	}
	return max_index;
}

int feed_forward(double *input) {
	double res[BIAS_WIDTH][INPUT_SIZE] = {{0}};
	double add_res[LAYER_1_HEIGHT][BIAS_WIDTH] = {{0}};
	double dp_res_vec[LAYER_1_HEIGHT][1] ={{0}};
	int heights[] = SIZES;

	for (int layer = 0; layer < LAYERS_SIZE; layer++) {
		int LAYER_HEIGHT = heights[layer];
		double **bias = biases[layer];
		double **weight = weights[layer];

		if (layer == 0) {
			dot_product(weight, input, dp_res_vec, LAYER_HEIGHT, layer);
		}
		else if (layer == 1) {
			dot_product(weight, res[0], dp_res_vec, LAYER_HEIGHT, layer);
		}
		vector_add(dp_res_vec, bias, add_res, LAYER_HEIGHT);
		sigmoid(add_res, res, LAYER_HEIGHT);
	}

	int output = argmax(res[0], 10);
	return output;
}


void evaluate() {
	int actual, output, counter = 0;
	double *input;
	for (int i = 0; i < 10000; i++) {
		actual = test_label[i];
    	input = test_image[i];
    	output = feed_forward(input);
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
}

int main() {

    load_mnist();
    
    images_to_fixed(test_image, test_image_fixed);

    for (int i = 0; i < 784; i++) {
        printf("%d, ", test_image_fixed[0][i]);
        if (i % 28 == 0) printf("\n");    
    }

	//evaluate();
	//evaluate_display();

    return 0;
}
