from collections import deque
import sys

input = sys.stdin.readline

h, w = map(int, input().split())
grid = [list(input()) for _ in range(h)]

monsters = deque()
mc = 0
dist = [[-1] * w for _ in range(h)]
q = deque()
D = [[-1] * w for _ in range(h)]

for i in range(h):
    for j in range(w):
        if grid[i][j] == "M":
            dist[i][j] = 0
            monsters.append((i, j))
        if grid[i][j] == "A":
            D[i][j] = 0
            q.append((i, j))

while monsters:
    i, j = monsters.popleft()
    for di, dj in ((0, 1), (-1, 0), (0, -1), (1, 0)):
        ii = i + di
        jj = j + dj
        if (
            ii in range(h)
            and jj in range(w)
            and dist[ii][jj] == -1
            and grid[ii][jj] != "#"
        ):
            dist[ii][jj] = dist[i][j] + 1
            monsters.append((ii, jj))

back = {}

while q:
    i, j = q.popleft()
    d = D[i][j]
    if i in (0, h - 1) or j in (0, w - 1):
        print("YES")
        path = [""] * d
        for k in range(d - 1, -1, -1):
            pi, pj = i, j
            i, j = back[(i, j)]
            if i > pi:
                path[k] = "U"
            if i < pi:
                path[k] = "D"
            if j > pj:
                path[k] = "L"
            if j < pj:
                path[k] = "R"
        print(d)
        print("".join(path))
        exit(0)
    for di, dj in ((0, 1), (-1, 0), (0, -1), (1, 0)):
        ii = i + di
        jj = j + dj
        if (
            ii in range(h)
            and jj in range(w)
            and D[ii][jj] == -1
            and grid[ii][jj] != "#"
        ):
            if dist[ii][jj] != -1 and dist[ii][jj] <= d + 1:
                continue
            q.append((ii, jj))
            D[ii][jj] = d + 1
            back[(ii, jj)] = (i, j)
print("NO")
