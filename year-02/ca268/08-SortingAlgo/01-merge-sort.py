#!/usr/bin/env python3


"""
Merge-Sort is a Divide-and-Conquer algo

1)DIVIDE: 
if the input size is smaller than a certian amount
(say, one or two element), slove the problem directly using a
straightforward method and reutrn the solution.
Otherwise, divide the input in two or more disjoint subset.

2)CONQUER:
Recursively solve the subproblems associated with the subsets

3)COMBINE:
Take the solutions to the subproblems and merge them into a
solution to the original problem.
"""

"""
DESCRIPTION:
It divides the input array into two halves, repitetly until all the
array size are one, so we have n arrays already sorted, then we merge them
two a times recursivly.

a a a a a a a a (you have 8 arrayes of len(1)) sorted)
a a a a (you have 4 of len(2) sorted)
a a (you have 2 of len(4)) sorted)
a   (you have 1  of len(8)) sorted) you sorted the whole array
"""


"""
In-Place = NO;
Stable = YES;

PERFORMACE:
Assuming N is the size of array

Worst time complexity   O(NlogN)
Average time complexity θ(NlogN)
Best time complexity    Ω(NlogN)

Worst space complexity  O(N)
"""

def mergesort(array):
    tmp = array.copy()
    low = 0
    high = len(array) - 1
    rec_split(array, tmp, low, high)

def rec_split(a, tmp, low, high):
    if low >= high:
        #it' an array with len 1 so it's sorted by defalut
        #no need to divide further
        return

    mid = (low + high) // 2
    #split on the left part
    rec_split(a, tmp, low, mid)
    #split on the right part
    rec_split(a, tmp, mid + 1, high)

    #merge the left and right part together
    merge(a, tmp, low, mid, high)

def merge(arr, tmp, low, mid, high):
    #you have an array a and a copy of a tmp
    #from low to mid you have a list of number already in sorting order
    #from mid + 1 to high you have another list of number already in sorting order
    i = low
    j = mid + 1
    k = low

    #here we are just mergeing the two virual array form low to mid and from mid + 1 to high
    #we are over writing the copy tmp
    #in this way if i stops the loop we dont need to add any j bc thery are already there
    while i <= mid and j <= high:
        if arr[i] < arr[j]:
            tmp[k] = arr[i]
            i += 1
        else:
            tmp[k] = arr[j]
            j += 1
        k += 1

    #if j stops the loop we need to add i bc it meas than a number in i (so from low to mid)
    #is greater than all the number in j(so from mid + 1 to high)
    while i <= mid:
        tmp[k] = arr[i]
        k += 1
        i += 1
    
    #here we just copy all the value from the new sorted tmp in a
    i = low
    while i <= high:
        arr[i] = tmp[i]
        i += 1


a = [2,32,12,0, -1,3232,453, 9]
print(a)
mergesort(a)
print(a)
