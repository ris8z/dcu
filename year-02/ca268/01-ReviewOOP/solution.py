# Q1
def q1_sum(lst_input):
    output = 0
    for sub_lst in lst_input:
        for num in sub_lst:
            if num % 2 == 0:
                output = output + num
    return output


print(q1_sum([[1, 0, 2], [5, 5, 7], [9, 4, 3]]))


# Q2
def move_vow(str_input):
    vows = ""
    others = ""
    for chars in str_input:
        if chars in "aeiouAEIOU":
            vows += chars
        else:
            others += chars

    return vows + others


print(move_vow("This is DCU!"))


# Q3
class Memories:
    def __init__(self, **kwargs):
        for k, v in kwargs.items():
            setattr(self, k, v)

    def remember(self, attr):
        if hasattr(self, attr):
            print(getattr(self, attr))
        else:
            print("False")


person1 = Memories(name="Tom", age=32, salary=50000)
person1.remember("salary")
person1.remember("email")


# Q4
class Test:
    def __init__(self, subj_name, choices, passing_mark):
        self.subj_name = subj_name
        self.choices = choices
        self.passing_mark = passing_mark


class Student:
    def __init__(self, name):
        self.name = name

    def take_test(self, test, answers):
        mark = 0
        subj = getattr(test, "subj_name")
        correct_answers = getattr(test, "choices")
        passing_mark = getattr(test, "passing_mark")

        for i in range(len(correct_answers)):
            if answers[i] == correct_answers[i]:
                mark = mark + 1

        mark_percentage = (100 * mark) / len(correct_answers)
        if mark_percentage >= int(passing_mark.split("%")[0]):
            print(
                f"{self.name} passed the {subj} test with the score {mark_percentage}%"
            )
        else:
            print(f"{self.name} failed the {subj} test!")


paper1 = Test("Maths", ["1A", "2C", "3D", "4A", "5A"], "60%")
paper2 = Test("Chemistry", ["1C", "2C", "3D", "4A"], "75%")
paper3 = Test("Computing", ["1D", "2C", "3C", "4B", "5D", "6C", "7A"], "75%")

stu1 = Student("Tom")
stu1.take_test(paper2, ["1C", "2C", "3D", "4A"])

stu2 = Student("John")
stu2.take_test(paper1, ["1B", "2C", "3A", "4A", "5B"])


# Q5
def histogram(lst_input, char):
    for i in lst_input:
        print(i * char)


histogram([6, 2, 15, 3, 20, 5], "=")


# Q6
def filter_star(dict_input, rating):
    output = {}
    for k, v in dict_input.items():
        if len(v) == rating:
            output[k] = v

    if len(output) == 0:
        print("No result found!")
    else:
        return output


print(
    filter_star(
        {
            "Luxury Chocolates": "*****",
            "Tasty Chocolates": "****",
            "Big Chocolates": "*****",
            "Generic Chocolates": "***",
        },
        5,
    )
)
