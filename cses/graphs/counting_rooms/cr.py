import sys

sys.setrecursionlimit(10**8)
h, w = [int(x) for x in input().split()]

grid = []

for i in range(h):
    grid.append([ch for ch in input()])


def dfs(i, j):
    if i not in range(h) or j not in range(w) or grid[i][j] == "#":
        return
    grid[i][j] = "#"
    for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        dfs(i + di, j + dj)


ans = 0
for i in range(h):
    for j in range(w):
        if grid[i][j] == ".":
            dfs(i, j)
            ans += 1
print(ans)
