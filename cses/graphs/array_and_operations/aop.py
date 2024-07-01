from collections import defaultdict


n = int(input())
m = int(input())


def ints():
    return map(int, input().split())


a = list(ints())


def factorize(x):
    factors = []
    div = 2
    while x != 1:
        c = 0
        while x % div == 0:
            x = x // div
            c += 1
        if c > 0:
            factors.append((div, c))
        div += 1
    return factors


print(factorize(12))

odd_factors = defaultdict(int)
even_factors = defaultdict(int)

for _ in range(m):
    i, j = ints()
    if i % 2 == 0:
        i, j = j, i
    # i odd, j even
    for factor, c in factorize(i):
        odd_factors[factor] += c
    for factor, c in factorize(j):
        even_factors[factor] += c
