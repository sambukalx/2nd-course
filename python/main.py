import math 


# 1

def main1(y):
    return (pow(y, 4) + (pow(y, 3) / 26)) / ((32 * pow(y, 2)) + 1)


def main2(y):
    return pow((14 * y) + pow(y, 2) + 44, 7)


def main3(y):
    return pow((pow(y, 2) + pow(y, 3) + 1), 4)


def main4(y):
    return 96 * ((pow(y, 3) / 18) + 39 + (51 * pow(y, 2)))


def main(y):
    return main1(y) - (main2(y) / (main3(y) + main4(y)))


# 2

def main(x):
    if x < 111:
        return (39 * x ** 2) ** 3 - (math.sin(x) ** 5 / 58)
    elif 111 <= x < 148:
        return 84 * x ** 2 - x ** 3
    else:
        return 47 * x ** 3


# 3

def main(m, z, n, b):
    sum1 = 0
    for c in range(1, m + 1):
        sum1 += math.sin(73 + (c ** 3 / 49) + c ** 2) - 19 * z ** 5 - 1

    sum2 = 0
    for c in range(1, m + 1):
        for i in range(1, b + 1):
            for k in range(1, n + 1):
                sum2 += 41 * i - 49 * (k ** 2 + 76 * k) ** 3 - abs(c) ** 5

    return sum1 - sum2


# 4

def main(n):
    if n == 0:
        return 0.05
    elif n == 1:
        return 0.88
    else:
        f_n_minus_2 = main(n - 2)
        f_n_minus_1 = main(n - 1)
        return 0.02 - (f_n_minus_2 ** 2) - ((math.sin(f_n_minus_1) ** 3) / 96)


# 5

def f(z, y, x):
    result = 0
    n = len(z)
    for i in range(1, n + 1):
        result += math.cos(77 * z[n - i]) ** 7 + math.cos(x[(i - 1) % 4] ** 2 + y[n - i] ** 3) ** 7
    return round(result, 4)


z1 = [-0.57, 0.53, 0.25, 0.06]
y1 = [0.04, 0.68, -0.7, 0.38]
x1 = [-0.9, 0.03, -0.28, 0.64]
print(f(z1, y1, x1))  # Output should be 0.0401

z = [0.53, -0.71, -0.53, -0.74]
y = [0.07, 0.72, 0.31, 0.15]
x = [-0.64, -0.21, -0.85, 0.39]
print(f(z, y, x))  # Output: -0.138

z = [-0.2, -0.38, 0.77, 0.5]
y = [-0.92, -0.6, -0.39, 0.16]
x = [0.2, 0.16, -0.21, 0.88]
print(f(z, y, x))  # Output: -1.25

z = [-0.25, -0.15, 0.28, 0.76]
y = [0.21, 0.02, 0.29, 0.28]
x = [-0.66, -0.25, 0.38, 0.51]
print(f(z, y, x))  # Output: -0.151

z = [-0.46, 0.12, -0.5, -0.66]
y = [0.4, -0.16, 0.25, -0.32]
x = [0.81, -0.09, -0.06, 0.37]
print(f(z, y, x))  # Output: 0.563


def main(z, y, x):
    result = 0
    n = len(z)
    for i in range(1, n + 1):
        q = math.cos(77 * z[n - i]) ** 7
        w = math.cos(x[(i - 1) % 4] ** 2 + y[n - i] ** 3) ** 7
        result += q + w
    return round(result, 4)
