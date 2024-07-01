import sys
from pprint import pprint
from collections import deque, defaultdict as ddict
import bisect

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


k, n = ints()

events = []

total_cost = 0
total_time = 0
for i in range(n):
    dur, c = ints()
    events.append((dur, c))
    total_cost += c
    total_time += dur

if k > total_time:
    print("Tekma bo polom")
    exit(0)

ans = 0

l, r = 0, 0
timew = 0
value = 0
valid = False

while r <= len(events):
    if timew < k:
        if r == len(events):
            break
        t, c = events[r]
        value += c
        timew += t
        r += 1
    else:
        valid = True
        ans = max(ans, total_cost - value)
        timew -= events[l][0]
        value -= events[l][1]
        l += 1

print(ans)
