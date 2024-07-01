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


input()

patterns = []

for line in sys.stdin:
    line = line.strip()
    if line == "IZPIS SKENERJA:":
        break
    patterns.append(line)

text = "".join([line for line in sys.stdin])
words = re.findall(r"[a-zA-Z0-9]+", text)

for p in patterns:
    parts = re.findall(r"[a-zA-Z0-9]+", p)
    c = 0
    for i in range(len(words) - len(parts) + 1):
        match = True
        for j, part in enumerate(parts):
            if words[i + j] != part:
                match = False
                break
        if match:
            c += 1
    if c > 0:
        if c > 1:
            print(f"{p} {c}x")
        else:
            print(p)
