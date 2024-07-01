import sys
from pprint import pprint
from collections import deque

sys.setrecursionlimit(10**7)


def ints():
    return map(int, input().split())


def intl():
    return list(ints())


# in "pt"
widths = r"""! 4.4453125    : 4.4453125    S 10.671875    l 3.5546875
" 5.6796875    ; 4.4453125    T 9.7734375    m 13.328125
# 8.8984375    < 9.34375      U 11.5546875   n 8.8984375
$ 8.8984375    = 9.34375      V 10.671875    o 8.8984375
% 14.2265625   > 9.34375      W 15.1015625   p 8.8984375
& 10.671875    ? 8.8984375    X 10.671875    q 8.8984375
' 3.0546875    @ 16.2421875   Y 10.671875    r 5.328125
( 5.328125     A 10.671875    Z 9.7734375    s 8
) 5.328125     B 10.671875    [ 4.4453125    t 4.4453125
* 6.2265625    C 11.5546875   \ 4.4453125    u 8.8984375
+ 9.34375      D 11.5546875   ] 4.4453125    v 8
, 4.4453125    E 10.671875    ^ 7.5078125    w 11.5546875
- 5.328125     F 9.7734375    _ 8.8984375    x 8
. 4.4453125    G 12.4453125   ` 5.328125     y 8
/ 4.4453125    H 11.5546875   a 8.8984375    z 8
0 8.8984375    I 4.4453125    b 8.8984375    { 5.34375
1 7.7228125    J 8            c 8            | 4.15625
2 8.8984375    K 10.671875    d 8.8984375    } 5.34375
3 8.8984375    L 8.8984375    e 8.8984375    ~ 9.34375
4 8.8984375    M 13.328125    f 4.15921875
5 8.8984375    N 11.5546875   g 8.8984375
6 8.8984375    O 12.4453125   h 8.8984375
7 8.8984375    P 10.671875    i 3.5546875
8 8.8984375    Q 12.4453125   j 3.5546875
9 8.8984375    R 11.5546875   k 8
""".splitlines()

width = {}

for line in widths:
    parts = line.split()
    for i in range(len(parts) // 2):
        ch, w = parts[2 * i : 2 * i + 2]
        w = float(w)
        width[ch] = w

page_width = 17


# 1pt = ... cm
pt = 0.0352777778

in_lines = []

while True:
    try:
        in_lines.append(input())
        in_lines.append(" ")
    except:
        break


text = "".join(in_lines)
words = text.split()


def word_width(word):
    return sum(width[ch] for ch in word) + len(word) - 1


lines = deque()
i = 0
while True:
    w = word_width(words[i])
    j = 1
    end = False
    while True:
        if i + j == len(words):
            end = True
            break
        new_w = word_width(words[i + j])
        if (w + new_w + j * 4) * pt > page_width:
            break
        j += 1
        w += new_w
    lines.append((w, j, words[i + j - 1]))
    i = i + j
    if end:
        break

print(len(lines))
for i, _line in enumerate(lines):
    ww, count, last = _line
    sw = 0
    if count > 0:
        if count == 1:
            sw = "/"
        else:
            sw = ((page_width / pt) - ww) / (count - 1)
            if i == len(lines) - 1:
                sw = min(6, sw)
    print(last, sw)
