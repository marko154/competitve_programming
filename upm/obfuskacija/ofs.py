import sys
from pprint import pprint

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


def words():
    return input().split()


n = int(input())
for i in range(n):
    s = input()

    last = ord("a") - 1
    valid = True
    for ch in s:
        if ord(ch) > last + 1:
            print("NE")
            valid = False
            break
        else:
            last = max(last, ord(ch))
    if valid:
        print("DA")
