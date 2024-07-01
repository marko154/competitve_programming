import sys
import heapq
import re
from pprint import pprint
from collections import deque, defaultdict as ddict
import bisect

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


n = int(input())

coins = []
X = []
L = []

a = 16807
mod = (1 << 31) - 1

for i in range(n):
    c1, x1, liquidation = ints()
    L.append(liquidation)
    X.append(x1)
    heapq.heappush(coins, (c1, i))

ans = 0
m = int(input())


for i in range(m):
    coin, idx = heapq.heappop(coins)
    ans = max(ans, coin)
    ncoin = coin + (X[idx] % L[idx])
    X[idx] = (a * X[idx]) % mod
    heapq.heappush(coins, (ncoin, idx))

print(ans)
