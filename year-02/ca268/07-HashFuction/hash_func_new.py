import struct


# Function to convert integer to bit representation
def int_to_bits(key):
    return bin(key)[2:]


# Function to convert floating-point number to bit representation
def float_to_bits(key):
    # We use '>d' for big-endian double precision float
    packed = struct.pack('>d', key)
    return ''.join(f'{byte:08b}' for byte in packed)


# Function to convert string to bit representation
def string_to_bits(key):
    return ''.join(format(ord(c), '08b') for c in key)


# Perform a left cyclic shift (also known as a circular left shift or bit rotation to the left)
def hash_code_cyclic_shift(s, shift_bits):
    max_32bit = (1 << 32) - 1  # Maximum value for a 32-bit unsigned integer
    h = 0
    for character in s:
        # Create a mask with top `shift_bits` set to 1 and the rest to 0
        #high_bits_mask = ~((1 << (32 - shift_bits)) - 1) & max_32bit
        high_bits_mask = 1 << (32 - shift_bits)
        # Capture the high-order bits that will be "lost"
        high_order_bits = h & high_bits_mask
        # Perform the left shift and mask to keep within 32 bits
        h = (h << shift_bits) & max_32bit
        # Wrap the high-order bits to the low-order side
        h |= high_order_bits >> (32 - shift_bits)
        # Add the character's ASCII value to the hash
        h += ord(character)
    return h


# Compress a 64-bit integer into a 32-bit hash value
def hash_64_to_32(key_64):
    # Assume key_64 is a 64-bit integer
    # Extract the high 32 bits
    high_bits = key_64 >> 32
    # Extract the low 32 bits
    low_bits = key_64 & 0xFFFFFFFF

    # Combine them using XOR
    hash_32 = high_bits ^ low_bits

    return hash_32


# Example usage:
int_key = 314
float_key = 3.14
string_key = "hello"
example_64_bit_number = 9876543210987654321  # Example 64-bit number in decimal. A large decimal number

print("Integer to bits:", int_to_bits(int_key))
print("Float to bits:", float_to_bits(float_key))
print("String to bits:", string_to_bits(string_key))
print(f"Left Cyclic shift of '{string_key}':", hash_code_cyclic_shift(string_key, 5))

# Compute the 32-bit hash
hash_code = hash_64_to_32(example_64_bit_number)
print(f"The 32-bit hash of the 64-bit number {example_64_bit_number} is {hash_code}")
