import heapq

n, m = map(int, input().split())

dist = [float("inf")] * n
adj = [[] for _ in range(n)]

for i in range(m):
    fr, to, w = map(int, input().split())
    fr -= 1
    to -= 1
    adj[fr].append((to, w))

q = []
dist[0] = 0
heapq.heappush(q, (0, 0))

while q:
    d, node = heapq.heappop(q)
    if d > dist[node]:
        continue
    for out, w in adj[node]:
        D = d + w
        if D < dist[out]:
            dist[out] = D
            heapq.heappush(q, (D, out))

for x in dist:
    print(x, end=" ")
print()
