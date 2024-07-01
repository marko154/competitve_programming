s = input()

a, b = 0, 0

for i, ch in enumerate(s):
    ea = "1" if i & 1 else "0"
    eb = "0" if i & 1 else "1"
    if ea != ch:
        a += 1
    if eb != ch:
        b += 1

print(min(a, b))
