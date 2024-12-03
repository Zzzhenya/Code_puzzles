#!/usr/local/bin/python3

import time
import re
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

sum = 0
for row in rows:
    arr = re.findall("mul\\([0-9]+\\,[0-9]+\\)", row)
    for item in arr:
        ret = re.findall("[0-9]+\\,[0-9]+", item)
        for i in ret:
            val = i.split(',')
            sum += (int(val[0]) * int(val[1]))

print(sum)
et = time.time()
print('ex time: ', et-st, " s")