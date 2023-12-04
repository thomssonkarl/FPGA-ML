import numpy as np

def fp64d_to_fp16b(a):
        return bin(np.float16(a).view('H'))[2:].zfill(16)

def int_representation(__a):
        return int(__a, 2)

def fp16b_to_fp64d(__a):
    binary_str = format(__a, '016b')  # Ensure 16 bits in the binary representation
    float16_view = np.uint16(int(binary_str, 2)).view(np.float16)
    return float16_view.item()

value_to_test = 0.5 

int_rep = int_representation(fp64d_to_fp16b(value_to_test))

print(int_rep)

decimal_a = fp16b_to_fp64d(int_representation(fp64d_to_fp16b(value_to_test)))

# this should output ~0.35
print(decimal_a)

