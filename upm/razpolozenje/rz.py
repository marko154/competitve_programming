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


n = int(input())

people = {}

for i in range(n):
    name, s = input().split()
    name = name[:-1]
    matches = re.findall(r"(:\(+|:\)+)", s)
    if name not in people:
        people[name] = 0
    for match in matches:
        for ch in match:
            if ch == ")":
                people[name] += 1
            if ch == "(":
                people[name] -= 1
for person in sorted(people.keys()):
    print(person, end=" ")
    h = people[person]
    if h > 0:
        print("happy")
    elif h == 0:
        print("undefined")
    else:
        print("sad")
