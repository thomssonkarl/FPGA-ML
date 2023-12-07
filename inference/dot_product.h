#pragma once
typedef int32_t fixed_point_t;

void dot_product(fixed_point_t weights[30][784], fixed_point_t image[784], fixed_point_t result[30], size_t height, size_t size);
