#!/usr/local/bin/python3

import time
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

def diff_is_in_range(arr):
    size = 0
    for i in arr:
        size += 1
    i = 0
    while (i < size and i + 1 < size):
        val = abs(arr[i] - arr[i + 1])
        if (val < 1):
            return (False)
        elif (val > 3):
            return (False)
        i += 1
    return (True)

count = 0
for row in rows:
    temp  = row.split()
    arr = []
    for i in temp:
        arr.append(int(i))
    if (diff_is_in_range(arr)) and (arr == sorted(arr) or arr  == sorted(arr, reverse=True)):
        count += 1

print("count: ", count)
et = time.time()
print('ex time: ', et-st, " s")