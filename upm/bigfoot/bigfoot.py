import sys

sys.setrecursionlimit(10**8)

h, w = map(int, input().split())
grid = []

for i in range(h):
    line = input()
    grid.append(list(line))

def dfs(i, j):
    total = 0
    if grid[i][j] == "#":
        total += 1
    grid[i][j] = "."
    for di, dj in ((0, 1), (-1, 0), (0, -1), (1, 0)):
        ii = i + di
        jj = j + dj
        if ii in range(h) and jj in range(w) and grid[ii][jj] in ("#+"):
            total += dfs(ii, jj)
    return total


ans = 0
for i in range(h):
    for j in range(w):
        if grid[i][j] == "+":
            ans += dfs(i, j)
print(ans)
