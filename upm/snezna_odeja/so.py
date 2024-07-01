import sys
import re
from pprint import pprint
from collections import deque, defaultdict as ddict
import bisect

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


w, h = ints()

grid = []


def drop(j):
    for i in range(h):
        if grid[i][j] in "#*" and i - 1 >= 0:
            grid[i - 1][j] = "*"
            break
        if i == h - 1:
            grid[i][j] = "*"


for i in range(h):
    line = list(input())
    grid.append(line)

for i in range(w):
    for j in range(3):
        drop(i)
for line in grid:
    print("".join(line))
