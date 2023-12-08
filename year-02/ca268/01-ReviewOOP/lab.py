#!/usr/bin/env python3

"""
Write a function q1_sum() that takes a list
as input and returns the sum of all even elements.
"""

def q1_sum(array):
    if not array:
        return 0

    if type(array[0]) is list:
        n = q1_sum(array[0])
    else:
        n = array[0]

    if n % 2 != 0:
        n = 0

    return n + q1_sum(array[1:])

def q1_iter(array):

    jobs = []
    jobs.append(array)
    
    result = 0

    while jobs:
        l = jobs.pop()
        while l:
            entity = l.pop()
            if type(entity) is list:
                jobs.append(entity)
            elif type(entity) is int and entity % 2 == 0:
                result += entity

    return result

assert(q1_sum([[1, 0, 2], [5, 5, 7], [9, 4, 3]]) == 6)
assert(q1_iter([[1, 0, 2], [5, 5, 7], [9, 4, 3]]) == 6)

"""
Write a function move_vow() that takes a string as input and returns the
vowels first and consonants second. Vowels are 'aeiouAEIOU'.
"""

def move_vow(string):
    vowels = "aeiouAEIOU"
    v_list = ""
    c_list = ""

    for c in string:
        if c in vowels:
            v_list += c
        else:
            c_list += c

    return v_list + c_list

assert(move_vow("This is DCU!") == "iiUThs s DC!")

"""
 Write a class called Memories with the following method:
 remember(): Recalls the value for the given attribute else
 prints False.
 Note: Variable number of arguments/attributes can be
 passed for each object.
"""
class Memories(object):
    def __init__(self, **args):
        for key, value in args.items():
            setattr(self, key, value)
    def remeber(self, key):
        return getattr(self, key, None)

P1 = Memories(name='Tom', age=32, salary=50000)

assert(P1.remeber('salary') == 50000)
assert(P1.remeber('age') == 32)
assert(P1.remeber('name') == 'Tom')

"""
Q4. Write a class called Test to take care of exam papers with the 
following attributes:
  1) subject_name
  2) correct_answers
  3) pasing_mark

Instantiate a few objects based on Test, such as:

p1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
p2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
p3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')

At the end, write a class called Student with the following attributes and methods:
 1) Attributes:
        name
 2) Methods:
        take_test()

which takes one of the defined test objects above and a list of 
answers from student. 
The method must check whether the student passed the given test or not.
"""
class Test(object):
    def __init__(self, subject_name, correct_answers, pasing_mark):
        self.subject_name = subject_name
        self.correct_answers = correct_answers
        self.pasing_mark = int(pasing_mark[:-1])

p1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
p2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
p3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')

class Student(object):
    def __init__(self, name):
        self.name = name

    def take_test(self, test, student_answers):
        n_questions = len(test.correct_answers)
        n_right_answers = self.count(student_answers, test.correct_answers)
        grade = (n_right_answers / n_questions) * 100

        if grade > test.pasing_mark:
            print("{} passed the Chemistry test with the score {}%".format(self.name, grade))
        else:
            print("{} failed the {} test!".format(self.name, test.subject_name))

    def count(self, stundet, test):
        result = 0
        for gA, rA in zip(stundet, test):
            if gA == rA:
                result += 1
        return result;


stu1 = Student('Tom')
stu1.take_test(p2, ['1C', '2C', '3D', '4A'])
stu2 = Student('John')
stu2.take_test(p1, ['1B', '2C', '3A', '4A', '5B'])

"""
Write a function histogram() that takes a list of numbers and a character as input.
The function should print a new line per argument in list.
The length of the lines corresponds to the numbers in the list passed as an argument.
"""
def histogram(lst, char):
    for n in lst:
        print(char * n)

histogram([6, 2, 15 , 3, 20 , 5], '=' )

"""
 Write a function filter_star() to take the following dictionary and an integer as input.
 The function should return a new dictionary of items which match the specified star rating.
 Return No result found! if no match is found.
"""

def filter_star(d, n):
    dresult = {}

    for key, value in d.items():
        if len(value) == n:
            dresult[key] = value

    if dresult:
        return dresult

    return "No result found!"


print(filter_star({
    'Luxury Chocolates': '*****',
    'Tasty Chocolates': '****',
    'Big Chocolates': '*****',
    'Generic Chocolates': '***'}, 4))

print(filter_star({
    'Luxury Chocolates': '*****',
    'Tasty Chocolates': '****',
    'Big Chocolates': '*****',
    'Generic Chocolates': '***'}, 2))


