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
    word = input()
    out = ""
    for ch in word:
        if ch.lower() in "aeiou":
            out += ch + "p" + ch
        else:
            out += ch
    print(out)
