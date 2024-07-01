n = int(input())

arr = [int(x) for x in input().split()]
mx = sum(arr)

dp = [False] * (mx + 1)
dp[0] = True

largest = 0

for x in arr:
    largest = min(largest + x, mx + 1)
    for i in range(largest, -1, -1):
        if i - x >= 0 and dp[i - x]:
            dp[i] = True


c = 0

print(sum(dp) - 1)
for i in range(1, mx + 1):
    if dp[i]:
        print(i, end=" ")
