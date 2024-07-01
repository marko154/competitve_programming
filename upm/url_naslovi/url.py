import sys
import re
from pprint import pprint
from collections import deque, defaultdict as ddict
import bisect

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


urls = set()

for line in sys.stdin:
    line = line.strip().lower()
    line = re.sub("[^a-z0-9]+", "-", line)
    base = line.strip("-")
    url = base
    i = 2
    while url in urls:
        url = f"{base}-{i}"
        i += 1
    print(url)
    urls.add(url)
