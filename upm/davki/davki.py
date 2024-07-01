import sys


tbruto = 0
tobdbruto = 0
tprispevki = 0
tstudent = 0
osnova = 0
takont = 0


m_student = int(input().split()[1].split("/")[0])
m_vzd = int(input().split()[1].split("/")[0])

def conv(v):
    return float(v.replace(".", "").replace(",","."))

for line in sys.stdin:
    sifra, bdoh, prispevki, ak = line.strip().split()

    bdoh = conv(bdoh)
    tbruto += bdoh
    prispevki = conv(prispevki)

    tprispevki += prispevki
    takont += conv(ak)

    if sifra == "1101":
        osnova += bdoh - prispevki
        tobdbruto += bdoh
    elif sifra == "1211":
        tstudent += 0.9 * bdoh - prispevki
        osnova += 0.9 * bdoh - prispevki
        tobdbruto += bdoh
    elif sifra == "1230":
        osnova += 0.9 * bdoh - prispevki
        tobdbruto += bdoh

# olajsave
splosna = 3500
if tobdbruto < 13316.83:
    splosna = 3500  + (18700.38 - 1.40427 * tobdbruto)
splosna = splosna * ((12 - m_vzd) / 12)

studentska = min(3500, tstudent)
if m_student == 0:
    studentska = 0


osnova -= splosna + studentska
osnova = max(0, osnova)
# print("osnova", osnova, splosna, studentska)

lest = ((8500, 16), (25000, 26), (50000, 33), (72000, 39))
davki = 0

prev = 0
for th, proc in lest:
    temp = th - prev
    prev = th
    chunk = min(osnova, temp)
    osnova -= chunk
    davki += chunk * (proc / 100)
    if osnova == 0:
        break
# print("osn", osnova)
davki += osnova * 0.5

# print("davki, akont", davki, takont)


def fmt(v):
    return f"{round(v, 2):,.2f}".replace(",", "#").replace(".", ",").replace("#", ".")

print(fmt(davki - takont))
neto = tbruto - tprispevki - davki
obr = (tbruto - neto) / tbruto * 100
obr = f"{round(obr, 2):.2f}%".replace(".", ",")
print(fmt(tbruto), fmt(tprispevki), fmt(davki), fmt(neto), obr)


