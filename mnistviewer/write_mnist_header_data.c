#include <stdio.h>
#include "mnist.h"

void write_test_data_to_header(const char *header_file_path, double test_image[][SIZE], int test_label[]) {
    FILE *header_file = fopen(header_file_path, "w");

    if (header_file == NULL) {
        fprintf(stderr, "Error opening header file for writing.\n");
        return;

    }

    fprintf(header_file, "double test_image[%d][%d] = {\n", NUM_TEST, SIZE);
    for (int i = 0; i < NUM_TEST; i++) {
        fprintf(header_file, "  {");
        for (int j = 0; j < SIZE; j++) {
            fprintf(header_file, "%.6f", test_image[i][j]);
            if (j < SIZE - 1) {
                fprintf(header_file, ", ");

            }

        }
        fprintf(header_file, "}");
        if (i < NUM_TEST - 1) {
            fprintf(header_file, ",");

        }
        fprintf(header_file, "\n");
    }
    fprintf(header_file, "};\n\n");

    fprintf(header_file, "int test_label[%d] = {", NUM_TEST);
    for (int i = 0; i < NUM_TEST; i++) {
        fprintf(header_file, "%d", test_label[i]);
        if (i < NUM_TEST - 1) {
            fprintf(header_file, ", ");

        }

    }
    fprintf(header_file, "};\n\n");

    fclose(header_file);
}

int main() {
    load_mnist();
    const char *header_file_path = "test_data.h";
    write_test_data_to_header(header_file_path, test_image, test_label);
    return 0;
}
