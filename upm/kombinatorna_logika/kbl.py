from pprint import pprint
"""
S(SK)(KS)(SKK)
=SK(SKK)(KS(SKK))
=K(KS(SKK))(SKK(KS(SKK)))
=KS(SKK)
=S
"""

def inject_operator(text):
    out = ""
    for i in range(len(text) ):
        curr = text[i]
        out += curr
        if i == len(text) - 1: 
            continue
        next = text[i + 1]
        if (curr.isalpha() or curr == ")") and (next.isalpha() or next == "("):
            out += "*"
    return out

"""
prod: term (*term)*
term: S | K | (prod)
"""

class Parser:
    def __init__(self, text):
        self.text = text
        self.pos = 0
        self.curr_token = text[0]
    def eat(self, ttype):
        if ttype != self.curr_token:
            return
        if self.pos != len(self.text):
            self.pos += 1
        if self.pos == len(self.text):
            self.curr_token = None
        else:
            self.curr_token = self.text[self.pos]

    def prod(self):
        nodes = [self.term()]
        while self.curr_token == "*":
            self.eat("*")
            right  = self.term()
            nodes.append(right)
        if len(nodes) == 1:
            return nodes[0]
        return { "type": "prod", "children": nodes}
    def term(self):
        token = self.curr_token
        if token is None:
            print(self.text, self.pos)
            raise Exception("shouldnt be here")

        if token.isalpha():
            self.eat(token)
            return { "type": "char", "value": token }
        elif token == "(":
            self.eat("(")
            expr = self.prod()
            self.eat(")")
            return expr
        print(self.text, self.pos)
        raise Exception("shouldnt be here")



text = inject_operator(input())
prev = text
parser = Parser(text)
ast = parser.prod()
pprint(ast)

def serialize(node):
    pass

def expand(node):
    if node["type"] == "char":
        return node, False
    # if the node is a product:
    # first try to match "K" x y or "S" x y z in the children of that node (with a for loop, from left to right)
    
    children = node["children"]

    for i, child in enumerate(children):
        if child["type"] == "char":
            ch = child["value"]
            if ch == "K" and len(children[i+1:]) >= 2:
                x = children[i + 1]
                node["children"] = children[:i] + [x] + children[i + 3:]
                return node, True
            elif ch == "S" and len(children[i+1:]) >= 3:
                x, y, z = children[i + 1:i + 1 + 3]
                node["children"] = children[i:] + [x, z, {"type": "prod", "children": [y, z]}]
                return node, True
        elif child["type"] == "prod":
            child, applied = expand(child)
            if applied:
                children[i] = child
                return node



    # if that doesnt work try on all children until one it works on one of them
    # return modified_node, was_modified_boolean
    return node, False



exit(0)

while True:
    text = expand(text)
    if text == prev:
        break
    prev = text

