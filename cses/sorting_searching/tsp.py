n = 4  # there are four nodes in example graph (graph is 1-based)

# dist[i][j] represents shortest distance to go from i to j
# this matrix can be calculated for any given graph using
# all-pair shortest path algorithms
dist = [
    [0, 0, 0, 0, 0],
    [0, 0, 10, 15, 20],
    [0, 10, 0, 25, 25],
    [0, 15, 25, 0, 30],
    [0, 20, 25, 30, 0],
]

memo = {}


def min_hamilton_path(end, mask):
    if bin(mask).count("1") == 3:
        return dist[1][end]
    if (end, mask) in memo:
        return memo[(end, mask)]

    without_end = mask & ~(1 << end)
    ans = float("inf")
    for i in range(2, n + 1):
        if i == end or not mask & (1 << i):
            continue
        ans = min(min_hamilton_path(i, without_end) + dist[i][end], ans)

    memo[(end, mask)] = ans
    return ans


def tsp():
    ans = float("inf")
    for i in range(2, n):
        ans = min(ans, min_hamilton_path(i, 1 << (n + 1) - 1) + dist[i][1])

    return ans


print(tsp())
