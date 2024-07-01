from collections import deque

def ints(): 
    return map(int, input().split())



n = int(input())

tree = {}
parent = {}

for i in range(n):
    l, r = ints()
    tree[i + 1] = (l, r)
    if l != 0:
        parent[l] = i + 1
    if r != 0:
        parent[r] = i + 1

root = None
for node in range(1, n + 1):
    if node not in parent:
        root = node

if root is None:
    exit(0)

color = {}
q = deque([(root, 0)])
prev = None


while q:
    node, depth = q.popleft()
    conf = []
    if node in parent:
        conf.append(color[parent[node]])
    if prev and prev[1] == depth:
        conf.append(color[prev[0]])
    conf.sort()
    c = 1
    while c in conf:
        c += 1
    color[node] = c

    l, r = tree[node]
    if l != 0:
        q.append((l, depth + 1))
    if r != 0:
        q.append((r, depth + 1))

    prev = (node, depth)

for node in range(1,  n + 1):
    print(color[node], end=" ")

