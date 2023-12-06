import numpy as np

def fp64d_to_fp16b(a):
        return bin(np.float16(a).view('H'))[2:].zfill(16)

def int_representation(__a):
        return int(__a, 2)

def fp16b_to_fp64d(__a):
    binary_str = format(__a, '016b')  # Ensure 16 bits in the binary representation
    float16_view = np.uint16(int(binary_str, 2)).view(np.float16)
    return float16_view.item()

def d2f(input):
    FIXED_POINT_FRACTIONAL_BITS = 16
    return int(input * (1 << FIXED_POINT_FRACTIONAL_BITS))

double_input = -3.14
fixed_point_result = d2f(double_input)
print(fixed_point_result)

