import math


def fft(a: list[complex], inv: bool):
    n = len(a)
    # n is pow of 2
    if n == 1:
        return a

    aeven = a[0::2]
    aodd = a[1::2]
    ve = fft(aeven, inv)
    vo = fft(aodd, inv)
    v = [0 + 0j] * n
    w = 1 + 0j
    angle = 2 * math.pi / n
    if inv:
        angle *= -1
    for i in range(n // 2):
        v[i] = ve[i] + w * vo[i]
        v[n // 2 + i] = ve[i] - w * vo[i]
        w *= math.cos(angle) + math.sin(angle) * 1j
    return v


values = fft([2, -3, -5, 6], False)
print(values)
print([x / len(values) for x in fft(values, True)])
