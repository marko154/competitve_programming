import sys
import math
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

def minus(a, b):
    a0, a1 = a
    b0, b1 = b
    return (a0 - b0, a1 - b1)
def plus(a, b):
    a0, a1 = a
    b0, b1 = b
    return (a0 + b0, a1 + b1)
def scale(a, s):
    a0, a1 = a
    return (a0 * s, a1 * s)
def dot(a, b):
    a0, a1 = a
    b0, b1 = b
    return a0 * b0 + a1 * b1
def dist(a, b):
    a0, a1 = a
    b0, b1 = b
    return math.sqrt(((b0 - a0)**2 + (b1 - a1)**2))

def proj(line, mid):
    fr, to = line
    base = minus(to, fr)
    baser = minus(mid, fr)

    scaler = dot(base, baser) / dot(base, base)
    if scaler > 1 or scaler < 0:
        return (999999999999, 999999999999)
    p = scale(base, scaler)
    # print(line, mid, plus(fr, p))
    return plus(fr, p)


for i in range(n):
    x1, y1, x2, y2, xr, yr, r = ints()

    mid = (xr, yr) 
    top = ((x1, y2), (x2, y2))
    right = ((x2, y1), (x2, y2))
    bottom = ((x1, y1), (x2, y1))
    left = ((x1, y1), (x1, y2))

    def fmt(point):
        x, y = point
        print(f"{x} {y}")
    tp = proj(top, mid)
    rp = proj(right, mid)
    bp = proj(bottom, mid)
    lp = proj(left, mid)
    if dist(tp, (xr, yr)) <= r:
        fmt(tp)
    elif dist(rp, (xr, yr)) <= r:
        fmt(rp)
    elif dist(bp, (xr, yr)) <= r:
        fmt(bp)
    elif dist(lp, (xr, yr)) <= r:
        fmt(lp)
    else:
        print("Presek je prazen")

