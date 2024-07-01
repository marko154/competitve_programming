import sys
import math
import re
from pprint import pprint
from collections import deque, defaultdict as ddict
import bisect
sys.setrecursionlimit(10**7)

class Tree:
    def __init__(self ):
        self.sects = {}
        self.pple: list[tuple[str, str]] = []
        self.ssects = []
    def add(self, path: str, n):
        parts = path.split("/")[1:]
        node = self
        for part in parts[:-1]:
            if part not in node.sects:
                node.sects[part] = Tree()
            node = node.sects[part]
        name = parts[-1]
        node.pple.append((path, n))
    def find_first(self):
        path =[1]
        node = self
        while len(node.pple) == 0:
            path.append(1)
            node = node.ssects[0][1]
        return node.pple[0][0], tuple(path)
    def find(self, path):
        node = self
        for part in path[:-1]:
            if part > len(node.ssects):
                return None
            node = node.ssects[part - 1][1]
        if path[-1] > len(node.pple):
            return None
        return node.pple[path[-1] - 1]


def sort_tree(node):
    node.pple.sort(key= lambda v: v[0])
    sections = sorted(node.sects.keys())
    for sec in sections:
        node.ssects.append((sec, node.sects[sec]))
        sort_tree(node.ssects[-1][1])

tree = Tree()

for line in sys.stdin:
    line = line.strip()
    path, n = line.split()
    n = tuple(map(int, n.split(".")))
    tree.add(path, n)

sort_tree(tree)

curr = tree.find_first()
seen = set()
seen.add(curr[1])

while True:
    next = tree.find(curr[1])
    if not next:
        print(curr[0])
        break
    elif next[1] in seen:
        print(next[0])
        break
    curr = next
    seen.add(curr[1])


