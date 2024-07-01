import sys
from collections import OrderedDict

day_temps = OrderedDict()

for line in sys.stdin:
    line = line.strip()
    
    date, time, temp = line.split()

    if date not in day_temps:
        day_temps[date] = []
    day_temps[date].append(float(temp))


for date, temps in day_temps.items():
    avg = sum(temps) / len(temps)
    print(f"{date} {min(temps):.1f} {avg:.2f} {max(temps):.1f}")

