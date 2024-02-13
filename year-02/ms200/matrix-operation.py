#!/usr/bin/env python3

class Matrix():
    def __init__(self, mat):
        self.mat = mat

    def __str__(self):
        result = []
        for i in range(len(self.mat)):
            string = ""
            for j in range(len(self.mat[0])):
                t = "{:>4} ".format(self.mat[i][j])
                string += t
            result.append(string)
        return "\n".join(result)

    def get_dim(self):
        #returns a tuple (n_rows, n_clos)
        return len(self.mat), len(self.mat[0])

    def T(self):
        #returns the transpose matrix
        result = []
        rows, cols = self.get_dim()
        for i in range(cols):
            row = []
            for j in range(rows):
                n = self.mat[j][i]
                row.append(n)
            result.append(row)
        return Matrix(result)

    def __add__(self, other):
        if self.get_dim() != other.get_dim():
            print("You can not add two matrices with different dimension")
            return None
        result = []
        for i in range(len(self.mat)):
            row = []
            for j in range(len(self.mat[0])):
                n = self.mat[i][j] + other.mat[i][j]
                row.append(n)
            result.append(row)
        return Matrix(result)

    def __sub__(self, other):
        if self.get_dim() != other.get_dim():
            print("You can not sub two matrices with different dimension")
            return None
        result = []
        for i in range(len(self.mat)):
            row = []
            for j in range(len(self.mat[0])):
                n = self.mat[i][j] - other.mat[i][j]
                row.append(n)
            result.append(row)
        return Matrix(result)

    def __mul__(self, other):
        row1, col1 = self.get_dim()
        row2, col2 = other.get_dim()

        if col1 != row2:
            print("The number of cols in the first row must be equal to the number of rows of the second")
            return None
        result = [] # of dim row1 col2
        for i in range(row1):
            row = []
            for j in range(col2):
                tot = 0
                for z in range(col1):
                    tot += self.mat[i][z] * other.mat[z][j]
                row.append(tot)
            result.append(row)

        return Matrix(result)


def build_matrix(nrow, ncol):
    result = []
    for i in range(nrow):
        row = []
        for j in range(ncol):
            t = "Tpye number in position row {} and col {}".format(i + 1, j + 1)
            print(t)
            n = int(input())
            row.append(n)
        result.append(row)
    return result

def main():
    print("-----------------------------------------")
    print("Type dimesion for matrix A: n_rows n_cols")
    nrow, ncol = map(int, input().split())
    A = Matrix(build_matrix(nrow, ncol))
    print("-----------------------------------------")
    print("Type dimesion for matrix B: n_rows n_cols")
    nrow, ncol = map(int, input().split())
    B = Matrix(build_matrix(nrow, ncol))

    print("-----------------------------------------")
    print("A matrix is:")
    print(A)
    print("-----------------------------------------")
    print("B Matrix is:")
    print(B)
    print("-----------------------------------------")

    print("Type your expression: like A * B, A + B, or B + A, A.T() is the transpose of A, to close type end")
    t = input()
    
    while t != "end":
        print("-----------------------------------------")
        print(t, "is:")
        print(eval(t))
        print("-----------------------------------------")
        print("Next expression:")
        t = input()

if __name__ == '__main__':
    main()
