
n, m = map(int, input().split())
road = input()
parts = [part for part in road.split("#") if len(part) > 1]

ans = n - sum(len(part) - 1 for part in parts if len(part) > 0)
print(max(0, ans))

