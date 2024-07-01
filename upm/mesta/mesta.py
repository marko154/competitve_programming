import sys

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


def words():
    return input().split()


t = ints()

for i in range(t):
    n = int(input())
    ans = 0
    for j in range(n - 1):
        k, *dists = ints()

        ans += min(dists)

    print(ans)
