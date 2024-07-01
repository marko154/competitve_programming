def add(a, b):
    result = ""
    carry = 0
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)
    a = a[::-1]
    b = b[::-1]
    for i in range(n):
        value = int(a[i]) + int(b[i]) + carry
        out = value % 2
        carry = value // 2
        result = str(out) + result
    if carry:
        result = "1" + result

    return result


def neg(x):
    ones_complement = ""
    for ch in x:
        ones_complement += "0" if ch == "1" else "1"
    return add(ones_complement, "1")


def karatsuba(a, b):
    n = max(len(a), len(b))
    if n == 0:
        return "0"
    if n == 1:
        return str(int(a) * int(b))

    m = (n + 1) // 2
    a = a.zfill(n)
    b = b.zfill(n)

    a1 = a[:-m]
    a0 = a[-m:]
    b1 = b[:-m]
    b0 = b[-m:]

    c0 = karatsuba(a1, b1)
    c1 = karatsuba(a0, b0)
    aa = add(a0, a1)
    bb = add(b0, b1)
    aabb = karatsuba(aa, bb)
    mid = add(add(aabb, neg(c0)), neg(c1))

    first = c0 + "0" * (2 * m)
    second = mid + "0" * m
    third = c1
    print(c1, a0, b0)
    result = add(add(first, second), third)
    return result.lstrip("0") or "0"


a = 8
b = 8

aa = bin(a)[2:]
bb = bin(b)[2:]
print(f"Binary representation of {a}: {aa}")
print(f"Binary representation of {b}: {bb}")
result = karatsuba(aa, bb)
print(f"Binary result: {result}")
print(f"Decimal result: {int(result, 2)}")
print(f"Expected result: {a * b}")
