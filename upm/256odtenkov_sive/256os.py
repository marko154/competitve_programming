w, h = map(int, input().split())


def format(color):
    mask = (1 << 8) - 1
    r = (color >> 16) & mask
    g = (color >> 8) & mask
    b = color & mask

    return round(0.11 * b + 0.59 * g + 0.3 * r)


print(w, h)
for i in range(h):
    colors = map(int, input().split())
    for color in colors:
        print(format(color), end=" ")
    print()
