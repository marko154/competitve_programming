t = int(input())
q = [0] * t

for i in range(t):
    q[i] = int(input())
mx = max(q)
b = [0, 1, 5] + [0] * mx

mod = 10**9 + 7

for i in range(3, mx + 2):
    b[i] = (6 * b[i - 1] - 7 * b[i - 2]) % mod
for n in q:
    an = b[n + 1] - 4 * b[n]
    print((b[n] + an) % mod)
