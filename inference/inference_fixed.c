#include "../mnistviewer/mnist.h"
#include <stdint.h>
#include <string.h>
//#include "parameters_fixed.h"
#include "parameters_split_fixed.h"
#include <math.h>


uint16_t sigmoid_single(uint16_t z) {
	double z_as_double = fp16b_to_fp64d(z);
	double sigmoid = 1.0 / (1.0 + exp(-z_as_double));
	return fp64d_to_fp16b(sigmoid);	
}


void sigmoid(uint16_t vec[30], uint16_t result[30], uint16_t height) {
	for(uint16_t i=0; i < height; i++) {
		 result[i] = sigmoid_single(vec[i]);
	}
}

void dot_product(uint16_t weights[30][784], uint16_t image[784], uint16_t result[30], uint16_t height, uint16_t size) {
	uint16_t dp = 0;
	//printf("Using height = %d, size = %d\n", height, size);
	for (uint16_t i = 0; i < height; i++) {
		for (uint16_t j = 0; j < size; j++) {
			printf("Using w = %d, img = %d\n", weights[i][j], image[i]);
            printf("weight %d\n", weights[i][j]);
            printf("input %d\n", image[j]);
			dp += weights[i][j] * image[j]; 
		}
		result[i] = dp;
		printf("DP: %d\n", result[i]);	
		dp = 0;
	}
}

void vector_add(uint16_t a[30], uint16_t b[30][1], uint16_t result[30], uint16_t height) {
    printf("add\n");
    for (uint16_t i = 0; i < height; i++) {
		result[i] = b[i][0] + a[i];
	    printf("result %d = %d + %d\n", result[i], b[i][0], a[i]);
    }
}


uint16_t argmax(const uint16_t arr[], uint16_t size) {
	if (size <= 0) {
		fprintf(stderr, "Error: Invalid array size\n");
		return -1;
	}

	uint16_t max_index = 0;
	uint16_t max_value = arr[0];
	for (uint16_t i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
			max_index = i;
		}
	}
	return max_index;
}

uint16_t feed_forward(uint16_t input[784]) {
	uint16_t res[30] = {0};
	uint16_t add_res[30] = {0};
	uint16_t dp_res[30] = {0};
	printf("Hidden layer: \n");	
	// Hidden layer (height is 30)
	const uint16_t height_hl = 30;
	dot_product(weights_hl, input, dp_res, height_hl, 784);
	vector_add(dp_res, biases_hl, add_res, height_hl);
	sigmoid(add_res, res, height_hl);

	// Output layer (height is 10)
	printf("Output layer: \n");	
	const uint16_t height_ol = 10;
	dot_product(weights_ol, input, dp_res, height_ol, 30);
	vector_add(dp_res, biases_ol, add_res, height_ol);
	sigmoid(add_res, res, height_ol);

    printf("[");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", res[i]);
    }
    printf("]\n");
	
	uint16_t output = argmax(res, height_ol);
	return output;
}


void evaluate() {
	uint16_t actual, output, counter = 0;
	for (uint16_t i = 0; i < 10000; i++) {
		actual = test_label[i];
    	output = feed_forward(test_image_fixed[i]);
        if (output == actual) {
			counter++;
		}
		if (i == 2) return;
	}
	printf("Accuracy: %d/10000\n", counter);
}



/*
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
}*/

int main() {

    load_mnist();
    
    images_to_fixed(test_image, test_image_fixed);

    //display_image(test_image_fixed[0]);

	//evaluate();
	uint16_t test_val = 18688;
	uint16_t test_val2 = 18688; 
	uint16_t res = test_val * test_val2;
	printf("Using: %d\n", res);
	double x = fp16b_to_fp64d(res);
	printf("%f\n", x);
	uint16_t int_rep = fp64d_to_fp16b(x);
	printf("%d\n", int_rep);
    return 0;
}
