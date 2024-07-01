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


lines = """1001,Jabolka,3.49
1002,Banane,0.79
1003,Kruh,2.99
1004,Mleko,2.00
1005,Jajca,1.89
1006,Sir,4.99
1007,Puranje prsi,11.49
1008,Mleto goveje meso,7.00
1009,Krompir,1.29
1010,Cebula,0.99
1011,Cesen,0.29
1025,Korencek,1.59
1036,Kumare,1.99
1049,Paradiznik,2.49
1068,Spinaca,1.59
1075,Brokoli,2.29
1082,Fizol,1.79
1091,Paprika,1.49
1106,Jagode,3.99
1123,Pomarance,3.29
1144,Grozdje,4.99
1177,Borovnice,3.49
1208,Jogurt,1.99
1243,Granola,4.49
1280,Makaroni,2.29
1331,Omaka za testenine,2.99
1396,Riz,1.49
1458,Fizol,0.99
1525,Koruzni kosmici,0.79
1597,Tuna,2.49
1674,Krusne drobtine,1.79
1760,Perutnicke,5.99
1855,Svinjski zrezki,9.49
1959,Zamrznjena pica,5.79
2075,Sladoled,3.49
2110,Kava,4.99
2199,Cokolada,2.49
2237,Pivo,1.99
2291,Vino,8.49
2349,Sok,2.49
2411,Ketchup,1.79
2477,Majoneza,2.49
2539,Gorcica,1.49
2610,Kruhovi cmoki,3.49
2713,Spageti,1.29
2834,Paradiznikova omaka,1.99
2977,Papirnate brisace,3.49
3126,Toaletni papir,4.99
3187,Leca,1.49
3251,Kokosovo olje,5.99
3320,Majhni krofi,2.00
3468,Sveza bazilika,1.99
3534,Juha v vrecki,0.49
3672,Skatlica pralnih kapsul,10.99
3746,Crni poper,3.49
3855,Zacimbe za piscanca,1.49
3975,Papir za peko,2.49
4099,Svinjska kraca,15.00
4177,Goveji repki,13.99
4291,Sladki krompir,1.99
4333,Rdeca pesa,2.99
4422,Kvinoja,4.49
""".splitlines()
prices = {}
for line in lines:
    id, _, price = line.split(",")
    price = int(price.replace(".", ""))
    prices[id] = price
ans = 0
while True:
    line = input()
    if line.startswith("-"):
        break
    id, count = line.split()
    count = int(count)
    ans += prices[id] * count
_type = input().strip()
if _type == "CARD":
    ans = ans / 100
    print(f"{ans:.2f}")
else:
    fives = round(ans / 5)
    ans = (5 * fives) / 100
    print(f"{ans:.2f}")
