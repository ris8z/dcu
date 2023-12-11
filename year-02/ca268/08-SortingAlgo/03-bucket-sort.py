#!/usr/bin/env python3

"""
Bucket Sort is a sorting algorithm that divides the unsorted array
elements into several groups called buckets. Each bucket is then sorted
by using any of the suitable sorting algorithms or recursively applying
the same bucket algorithm. Finally, the sorted buckets are combined to
form a final sorted array.
"""

"""
In-Place = NO;
STABLE = YES;

Worst time complexity O(N2)
Average time complexity θ(N)
Best time complexity Ω(N)

Worst space complexity O(N)
"""

"""
1)If the elements of the array are floats ranging between 0 and 1, we
primarily make 10 buckets, numbered from 0 to 9, and then insert
elements into these buckets depending upon their most significant
number. A bucket value is calculated as: int(elementV alue ∗ 10).

2)If the elements of the array are integers, we simply calculate the
range:
range = (maxValue − minValue)/noBuckets
and divide the whole range into buckets and then perform bucket
sorting
"""


def bucket_sort(arr):

    total_slots = 10
    buckets = []

    # Create bucket arrays for each of 0-9
    for i in range(total_slots):
        buckets.append([])

    # For each number, get the digit in the tenth place and put it in
    # the respective bucket
    for num in arr:
        bucket_idx = int(total_slots * num)
        buckets[bucket_idx].append(num)

    # Sort each bucket in the list of buckets
    for bucket in buckets:
        bucket.sort()

    # Reconstruct the array by concatenating all sub arrays
    index = 0
    for bucket in buckets:
        for item in bucket:
            arr[index] = item
            index += 1

a = [0.1, 0.34, 0.56654, 0.2, 0.34]
print(a)
bucket_sort(a)
print(a)
