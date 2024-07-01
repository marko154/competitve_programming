import re


cur = []

while True:
    try:
        line = input()
    except:
        break

    if not line:
        if tuple(cur) == (5, 7, 5):
            print("hai")
        else:
            print("nyan")
        cur = []
        try:
            line = input()
        except:
            break
    parts = [x for x in re.split(r"[^aeiouAEIOU]", line) if x]
    n = len(parts)
    cur.append(n)
