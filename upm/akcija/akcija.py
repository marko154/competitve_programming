from datetime import date

n = int(input())

months = [
    "januar",
    "februar",
    "marec",
    "april",
    "maj",
    "junij",
    "julij",
    "avgust",
    "september",
    "oktober",
    "november",
    "december",
]
for i in range(n):
    zi, fi, *dt = input().split()
    zi = int(zi) * 100
    fi = int("".join(fi.split(".")))

    day, month, year = dt
    day = int(day[:-1])
    year = int(year)
    monthi = months.index(month) + 1

    do = date(year, monthi, day)
    today = date(2017, 4, 20)
    daysleft = (do - today).days + 1

    if daysleft <= 0:
        print("V SMETI")
    elif zi > daysleft * fi:
        print("AKCIJA")
    else:
        print("OK")
