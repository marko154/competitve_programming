from itertools import permutations
import sys
from pprint import pprint
from collections import deque, defaultdict
from functools import lru_cache

sys.setrecursionlimit(1 << 24)

def ints():
    return map(int, input().split())


n, m, q = ints()

dist = [[float("inf")] * n for _ in range(n)]

for i in range(m):
    fr, to, w = ints()
    fr -= 1
    to -= 1
    dist[fr][to] = min(dist[fr][to], w)
    dist[to][fr] = min(dist[to][fr], w)

for via in range(n):
    for fr in range(n):
        for to in range(n):
            dist[fr][to] = min(dist[fr][to], dist[fr][via] + dist[via][to])

for i in range(q):
    fr, to = ints()
    fr -= 1
    to -= 1
    D = dist[fr][to]
    if D == float("inf"):
        D = -1
    print(D)
