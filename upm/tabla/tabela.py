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


r, c = ints()

align = input()

widths = [0] * (c)
rows = []
for line in sys.stdin:
    line = line.strip()
    cells = line.split(",")
    rows.append(cells)
    for j in range(len(cells)):
        widths[j] = max(widths[j], len(cells[j]))
for row in rows:
    parts = []
    for j, cell in enumerate(row):
        w = widths[j]
        if align[j] == "R":
            parts.append(str(cell).rjust(w))
        else:
            parts.append(str(cell).ljust(w))
    print(" | ".join(parts))
