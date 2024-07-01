n, tu = map(int, input().split())


rooms = [[0, 0, 0] for _ in range(tu)]

for i in range(n):
    k, u, *_ = input().split()
    k = int(k)
    u = int(u) - 1

    for j in range(k):
        tip, *_ = input().split()
        idx = {
            "sirov": 0,
            "veganski": 1,
        }.get(tip, 2)
        rooms[u][idx] += 1

for a, b, c in rooms:
    print(a, b, c)
