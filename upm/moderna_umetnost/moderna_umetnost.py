import sys
from pprint import pprint

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


def words():
    return input().split()


hues = ".:-=+*$#%@"

w, h, n = ints()

grid = [[0 for _ in range(w)] for _ in range(h)]

hits = 0


def print_grid():
    print("+" + "-" * w + "+")
    for row in grid:
        print("|", end="")
        for hue in row:
            if hue > 0:
                print(hues[min(hue - 1, len(hues) - 1)], end="")
            else:
                print(" ", end="")
        print("|")
    print("+" + "-" * w + "+")


for i in range(n):
    a, b, c, d = ints()
    frx = min(a, c)
    tox = max(a, c)
    fry = min(b, d)
    toy = max(b, d)
    if tox <= 0 or frx > w or toy <= 0 or fry > h:
        continue
    colored = False
    for ii in range(min(b, d), max(b, d) + 1):
        for jj in range(min(a, c), max(a, c) + 1):
            colored = True
            grid[ii - 1][jj - 1] += 1
    if colored:
        hits += 1
print_grid()
print(f"{hits} pravokotnikov na belem")
