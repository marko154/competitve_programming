import sys


boni = []
for line in sys.stdin:
    line = line.strip()
    if line.isnumeric():
        if len(boni) == 3:
            boni = boni[1:]
        boni.append(int(line))
    else:
        for i in range(len(boni)):
            if boni[i] > 0:
                boni[i] -= 1
                break
print(sum(boni))
