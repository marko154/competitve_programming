base = """##...##.######..##....##
##...##.##...##.###..###
##...##.######..##.##.##
##...##.##......##....##
.#####..##......##....##""".splitlines()


v = int(input())


for i in range(v * len(base)):
    for j in range(v * len(base[0])):
        if base[i // v][j // v] == "#":
            print("#", end="")
        else:
            print(".", end="")
    print()
