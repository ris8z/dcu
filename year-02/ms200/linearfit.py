#!/usr/bin/env python3

def row_echelon_form(A):
    lead = 0
    numRows, numCols = len(A), len(A[0])
    for r in range(numRows):
        if lead >= numCols:
            break
        i = r
        while A[i][lead] == 0:
            i += 1
            if i == numRows:
                i = r
                lead += 1
                if lead == numCols:
                    return
        A[i], A[r] = A[r], A[i]
        pivot = A[r][lead]
        A[r] = [entry / pivot for entry in A[r]]
        for i in range(numRows):
            if i != r:
                factor = A[i][lead]
                A[i] = [i_j - factor * r_j for i_j, r_j in zip(A[i], A[r])]
        lead += 1

def main():
    x = []
    y = []
    xy = []
    xx = []

    print("How many entries?")
    n = int(input())

    for i in range(n):
        print("Type", i + 1, "th entries x F(x) ")
        nx, ny = map(int, input().split())
        x.append(nx)
        y.append(ny)
        xy.append(nx * ny)
        xx.append(nx * nx)
    print("What is the x that you want to know about? if there is not just put a random value")
    gx = int(input())

    print("--------------------------------")
    print("n:")
    print("--------------------------------")
    print(n)

    print("--------------------------------")
    print("x\ty\txy\tx^2")
    print("--------------------------------")
    for i in range(n):
        t = "{}\t{}\t{}\t{}".format(x[i],y[i],xy[i],xx[i])
        print(t)

    print("--------------------------------")
    print("sum(x)\tsum(y)\tsum(xy)\tsum(x^2)")
    print("--------------------------------")
    t = "{}\t{}\t{}\t{}".format(sum(x),sum(y),sum(xy),sum(xx))
    print(t)



    print("--------------------------------")
    print("You need to solve:")
    print("--------------------------------")
    t = "{}a + {}b = {}".format(n,sum(x),sum(y))
    print(t)
    t = "{}a + {}b = {}".format(sum(x),sum(xx),sum(xy))
    print(t)

    m = [[n,sum(x),sum(y)],[sum(x),sum(xx),sum(xy)]]
    row_echelon_form(m)
    print("--------------------------------")
    print("Reduced Form")
    print("--------------------------------")
    for row in m:
        print(row)

    a = m[0][-1]
    b = m[1][-1]

    print("--------------------------------")
    print("Line equation")
    print("--------------------------------")
    t = "y = {} + ({}x)".format(a, b)
    print(t)

    print("--------------------------------")
    print("The value of y for x =", gx, "should be:")
    print("--------------------------------")
    print(a + (gx * b))


if __name__ == '__main__':
    main()
