#!/usr/bin/env python3

def hash_code(string):
    
    mask = (1 << 32) - 1

    h = 0

    for char in string:
        first_five_bits = (h & mask) >> (32 - 5)

        h = (h << 5) & mask

        h = h | first_five_bits

        h += ord(char)

    return h


def hash_64_to_32(key):

    mask = (1 << 32) - 1
    
    high = (key >> 32)

    low = key & mask

    hash_32 = high ^ low

    return hash_32

import struct

def float_to_binary(num):
    # Pack the float into 4 bytes (for 32-bit representation)
    packed = struct.pack('!f', num)
            
    # Format the bytes into binary
    return ''.join(f'{byte:08b}' for byte in packed)

# Example usage
float_num = 3.14
binary_representation = float_to_binary(float_num)
print(binary_representation)

print(hash_code("Cat"))

e = 9876543210987654321

print(hash_64_to_32(e))
