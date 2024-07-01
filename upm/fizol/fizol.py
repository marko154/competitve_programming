import bisect
from collections import defaultdict

m, n = map(int, input().split())

t = list(map(int, input().split()))
meals = list(map(int, input().split()))
foods = input().split()

total = defaultdict(int)
hit = defaultdict(int)

t.sort()

for i in range(len(foods)):
    time = meals[i]
    fr = time + 180
    to = time + 720
    l = bisect.bisect_left(t, fr)
    r = bisect.bisect_right(t, to)
    hits = r - l
    if hits > 0:
        hit[foods[i]] += 1
    total[foods[i]] += 1



for food, hits in sorted(hit.items(), key=lambda pair: pair[0]):
    if hits * 2 >= total[food]:
        print(food, end=" ")
print()
