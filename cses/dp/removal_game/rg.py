import sys

sys.setrecursionlimit(10**8)
n = int(input())

arr = [int(x) for x in input().split()]

dp = [[[0, 0] for x in range(n)] for _ in range(n)]


for size in range(n):
    p = size % 2
    for start in range(n - size):
        if size == 0:
            dp[size][start][p] = arr[start]
        else:
            end = dp[size - 1][start].copy()
            end[p] += arr[start + size]
            beg = dp[size - 1][start + 1].copy()
            beg[p] += arr[start]
            dp[size][start] = end
            if beg[p] > end[p]:
                dp[size][start] = beg

print(dp[n - 1][0][(n - 1) % 2])


def best_score(l, r, p):
    if l == r:
        ans = [0, 0]
        ans[p] = arr[l]
        return ans
    if dp[p][l][r] != [0, 0]:
        return dp[p][l][r]
    np = (1 + p) % 2
    s1 = best_score(l + 1, r, np).copy()
    s1[p] += arr[l]
    s2 = best_score(l, r - 1, np).copy()
    s2[p] += arr[r]
    ans = s1
    if s1[p] < s2[p]:
        ans = s2
    dp[p][l][r] = ans
    return ans


# print(best_score(0, n - 1, 0)[0])
