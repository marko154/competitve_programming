import sys
from pprint import pprint
from collections import deque, defaultdict as ddict

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


n = int(input())

for i in range(n):
    r, f = ints()
    if r == 0:
        print("NE")
    else:
        a, b = 1, 0
        b = r - 1
        a += r - 1
        if r - 1 > f or (f - b) & 1 or (f - b) > 0 and b == 0:
            print("NE")
        else:
            print("DA")
