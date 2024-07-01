from functools import cache


def first_digits(a, b):
    while b >= 10:
        a //= 10
        b //= 10
    return range(a, b + 1)


def new_range(i, a, b):
    blen = len(str(b))
    k = 10 ** (blen - 1)
    t = i * k
    A, B = (max(0, a - t), min(b - t, k - 1))
    # has more than 2 leading zeros
    if blen - len(str(B)) >= 2:
        return (0, -1)
    return (A, B)


@cache
def f(prev, a, b, leading):
    if b < 10:
        ans = b - a + 1
        if prev in range(a, b + 1):
            ans -= 1
        return ans
    ans = 0
    for i in first_digits(a, b):
        if i == prev:
            continue
        nprev = -1 if i == 0 and not leading else i
        ans += f(nprev, *new_range(i, a, b), i != 0 or leading)
    return ans


a, b = map(int, input().split())
print(f(-1, a, b, False))
