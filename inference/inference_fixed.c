#include "../mnistviewer/mnist.h"
#include "../mnistviewer/test_data.h"
#include <stdint.h>
#include <string.h>
#include "parameters_fixed.h"
#include <math.h>
#include "dot_product.h"

#define INPUT_SIZE 10000

fixed_point_t sigmoid_single(fixed_point_t z) {
	double z_as_double = f2d(z);
	double sigmoid = 1.0 / (1.0 + exp(-z_as_double));
	return d2f(sigmoid);
}

void sigmoid(fixed_point_t vec[30], fixed_point_t result[30], size_t height) {
	for(size_t i=0; i < height; i++) {
		 result[i] = sigmoid_single(vec[i]);
	}
}

void vector_add(fixed_point_t a[30], fixed_point_t b[30][1], fixed_point_t result[30], size_t height) {
    for (size_t i = 0; i < height; i++) {
		result[i] = b[i][0] + a[i];
    }
}


size_t argmax(const fixed_point_t arr[], size_t size) {
	if (size <= 0) {
		fprintf(stderr, "Error: Invalid array size\n");
		return -1;
	}

	size_t max_index = 0;
	double max_value = f2d(arr[0]);
	for (size_t i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = f2d(arr[i]);
			max_index = i;
		}
	}
	return max_index;
}

size_t feed_forward(fixed_point_t input[784]) {
	fixed_point_t res[30] = {0};
	fixed_point_t add_res[30] = {0};
	fixed_point_t dp_res[30] = {0};

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
		actual = test_label_header[i];
    	output = feed_forward(test_image_fixed[i]);
        if (output == actual) {
			counter++;
		}
	}
	printf("Accuracy: %zu/%d\n", counter, INPUT_SIZE);
}

void test_fixed_arithmetic() {
	double accepted_variance = 0.01;

	double a_input = 8.120;
	double b_input = 8.310;
	double d_input = -6.312;
	double e_input = -2.12;

	fixed_point_t a = d2f(a_input);
	fixed_point_t b = d2f(b_input);

	fixed_point_t result_add = a + b;
	double expected_add = a_input + b_input;
	if (fabs(f2d(result_add) - expected_add) < accepted_variance) {
		printf("Addition test passed.\n");

	} else {
		printf("Addition test failed. Produced: %f, Expected: %f\n", f2d(result_add), expected_add);

	}

	fixed_point_t result_sub = a - b;
	double expected_sub = a_input - b_input;
	if (fabs(f2d(result_sub) - expected_sub) < accepted_variance) {
		printf("Subtraction test passed.\n");

	} else {
		printf("Subtraction test failed. Produced: %f, Expected: %f\n", f2d(result_sub), expected_sub);

	}

	fixed_point_t result_mul = mul_fixed(a, b);
	double expected_mul = a_input * b_input;
	if (fabs(f2d(result_mul) - expected_mul) < accepted_variance) {
		printf("Multiplication test passed.\n");

	} else {
		printf("Multiplication test failed. Produced: %f, Expected: %f\n", f2d(result_mul), expected_mul);

	}

	fixed_point_t d = d2f(d_input);
	fixed_point_t e = d2f(e_input);

	fixed_point_t result_add_neg = d + e;
	double expected_add_neg = d_input + e_input;
	if (fabs(f2d(result_add_neg) - expected_add_neg) < accepted_variance) {
		printf("Addition with negative numbers test passed.\n");

	} else {
		printf("Addition with negative numbers test failed. Produced: %f, Expected: %f\n", f2d(result_add_neg), expected_add_neg);

	}

	fixed_point_t result_mul_neg = mul_fixed(d, e);
	double expected_mul_neg = d_input * e_input;
	if (fabs(f2d(result_mul_neg) - expected_mul_neg) < accepted_variance) {
		printf("Multiplication with negative numbers test passed.\n");

	} else {
		printf("Multiplication with negative numbers test failed. Produced: %f, Expected: %f\n", f2d(result_mul_neg), expected_mul_neg);

	}

}

void print_colored_pixel(fixed_point_t value) {
    int color_code = (int)(f2d(value) * 255);
    printf("\x1b[48;2;%d;%d;%dm  ", color_code, color_code, color_code);
}

void display_image(fixed_point_t *image) {
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
    size_t output = 0;
    char response;
    
    while(!quit) {
        output = feed_forward(test_image_fixed[i]);
        printf("Current image index: %d, Output of NN: %ld, Actual label: %d\n", i, output, test_label_header[i]);
        display_image(test_image_fixed[i]);
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
	images_to_fixed(test_image_header, test_image_fixed);
	evaluate();
    evaluate_display();

    return 0;
}
