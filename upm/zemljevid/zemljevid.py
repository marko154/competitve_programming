def ints():
    return map(int, input().split())


n, m = ints()
grid = []
for i in range(n):
    grid.append(list(input()))

voda = [".", "-", "!", "~"]
kopno = ["#", "$", "%", "&", "@"]

ct = [0, 0, 0]

for i in range(n):
    for j in range(m):
        if grid[i][j] in voda:
            ct[0] += 1
        elif grid[i][j] in kopno:
            ct[1] += 1
        else:
            ct[2] += 1

v, k, d = ct
print(f"VODA: {v}")
print(f"KOPNO: {k}")
print(f"DRUGO: {d}")
