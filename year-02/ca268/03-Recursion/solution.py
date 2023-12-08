# Q1
def sum_q1(n):
    if n <= 1:  # base case
        return n
    else:  # general or recursive case
        ans = sum_q1(n - 1)
    return n + ans


print(sum_q1(6))


# Q2
def reverse_integer(n, rev=0):
    if n == 0:
        return rev
    else:
        rev = rev * 10 + n % 10
        return reverse_integer(n // 10, rev)


number = 123
reversed_number = reverse_integer(number)
print(reversed_number)


# Q3
def reverse(string):
    if len(string) == 0:
        return string
    else:
        return reverse(string[1:]) + string[0]


print(reverse('hello'))


# Q4
def reverse(array):
    if len(array) == 0:
        return []

    elif len(array) == 1:
        return array

    return [array[len(array) - 1]] + reverse(array[:len(array) - 1])


array = [1, 2, 3, 4]
print(reverse(array))


# Q5
def multiply(x, y):
    if y == 0:
        return 0
    if x < 0:
        return -(y - multiply(y, x + 1))
    else:
        return y + multiply(y, x - 1)


print(multiply(11, 3))


# Q6
def is_heteromecic(n, x=0):
    if x * (x + 1) < n:
        return is_heteromecic(n, x + 1)
    else:
        return x * (x + 1) == n


print(is_heteromecic(30))


# Q7
def length(s):
    if s: return length(s[:-1]) + 1
    return 0


print(length("hello!"))
