import sys
from itertools import product

sys.setrecursionlimit(10**6)


class Parser:
    def __init__(self, expr):
        self.i = 0
        self.expr = expr

    def peek(self):
        if self.i >= len(self.expr):
            return ""
        return self.expr[self.i]

    def take(self):
        self.i += 1
        return self.expr[self.i - 1]

    def parse_union(self):
        left = self.parse_concat()

        while self.peek() == "+":
            self.take()
            left = {"type": "union", "left": left, "right": self.parse_concat()}
        return left

    def parse_concat(self):
        left = self.parse_term()
        # this is a stupid way to check if the operation is supposed to be a concatenation
        # should really be self.peek() == "*", where * is concatenation
        while self.peek().islower() or self.peek() in ("(", "E", "N"):
            left = {"type": "concat", "left": left, "right": self.parse_term()}
        return left

    def parse_term(self):
        if self.peek().islower():
            return {"type": "char", "value": self.take()}
        if self.peek() == "E":
            self.take()
            return {"type": "empty_str", "value": ""}
        if self.peek() == "N":
            return {"type": "empty_set", "value": self.take()}
        if self.peek() == "(":
            self.take()
            union = self.parse_union()
            self.take()
            return union
        raise Exception("Shouldnt be here", self.peek())


def evaluate(node):
    _type = node["type"]
    words = []
    if _type == "union":
        words.extend(evaluate(node["left"]))
        words.extend(evaluate(node["right"]))
    if _type == "concat":
        left = evaluate(node["left"])
        right = evaluate(node["right"])
        for pair in product(left, right):
            words.append("".join(pair))
            if len(words) == 1000:
                break
    if _type in ("char", "empty_str"):
        words.append(node["value"])
    return words[:1000]


regexpr = input().strip()
parser = Parser(regexpr)
ast = parser.parse_union()

for word in evaluate(ast):
    print(f"<{word}>")
