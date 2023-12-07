#include <stdint.h>
#include <string.h>
#include "dot_product.h"

void dot_product(fixed_point_t weights[30][784], fixed_point_t image[784], fixed_point_t result[30], size_t height, size_t size) {        fixed_point_t dp, partial = 0;
        uint16_t FRACTIONAL_BITS = 8;
        for (size_t i = 0; i < height; i++) {
                for (size_t j = 0; j < size; j++) {
                        partial = weights[i][j]*image[j];
                        partial >>= FRACTIONAL_BITS;
                        dp += (fixed_point_t) partial;
                }
                result[i] = dp;
                dp = 0;
        }
}
