import sys
import re
from pprint import pprint
from collections import deque, defaultdict as ddict, Counter
from itertools import permutations, combinations, product
import bisect
from typing import OrderedDict

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


n = int(input())
programs = []
apps = {}

for i in range(n):
    *name, k = input().split()
    k = int(k)
    name = " ".join(name)
    programs.append((name, k))
    apps[name] = []

m = int(input())

for i in range(m):
    line = input()
    score, program = re.search(r"(\d+) (.+)", line).groups()
    apps[program].append(int(score))

for name, limit in programs:
    ct = Counter(apps[name])
    ans = -1
    for score in sorted(ct.keys(), reverse=True):
        if limit - ct[score] >= 0:
            ans = score
        limit -= ct[score]
    if limit >= 0:
        ans = 0
    print(name, ans)
