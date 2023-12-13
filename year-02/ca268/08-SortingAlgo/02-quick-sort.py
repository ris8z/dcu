#!/usr/bin/env python3

"""
Descriptio:
Quick Sort is a Divide and Conquer algorithm. 
It picks an element as pivot and partitions the given array around the picked pivot.

(this means that we try to find the sorted position of the pivot in our array,
we can find this by putting all the element smaller the the pivot at its left and all the
element greater at its right, so we have 3 partition
a = all number smaller than the pivot
b = the pivot number
c = all number grater than the pivot

we call rec quick sort on a and c

until we get array of dim 1 that are already sorted)

There are many different versions of Quick Sort that pick pivot in different ways. But we stick
with consider the pivot as the last element of the array
"""

"""
In-Place = YES;
STABLE = NO;

Worst time complexity O(N2) 
(when the array it's aleardy sorted, bc the c partition would be 0 each time)

Average time complexity θ(NlogN)

Best time complexity Ω(nlogn)

Worst space complexity O(N)
"""


def quicksort(array, start, end):
    if end <= start:
        return

    pivot = partition(array, start, end)

    quicksort(array, start, pivot - 1)
    quicksort(array, pivot + 1, end)

def partition(array, start, end):
    pivot = array[end]
    
    i = start - 1
    j = start
    while j <= end - 1:
        if array[j] < pivot:
            i += 1
            tmp = array[i]
            array[i] = array[j]
            array[j] = tmp
        j += 1

    i += 1
    tmp = array[i]
    array[i] = array[end]
    array[end] = tmp

    return i

a = [23, -2, 322, 2, 121, 567, 3, 5, 0, -32]
print(a)
quicksort(a, 0, len(a) - 1)
print(a)




















