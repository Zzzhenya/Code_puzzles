#!/usr/local/bin/python3

import time
import itertools
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

d = {}
loc = 0

for row in rows:
    d[loc] = [(int(row.split(':')[0])), [int(item) for item in row.split(':')[1].split()]]
    loc += 1

def right_result(summ, nums, opsarr):
    for ops in opsarr:
        ret = nums[0]
        loc = 1
        for op in ops:
            if (op == '*'):
                ret  *= nums[loc]
            elif (op == '+'):
                ret  += nums[loc]
            elif (op == '|'):
                ret = int(str(ret)+ str(nums[loc]))
            loc += 1
        if (ret == summ):
            return (True)
    return (False)

total = 0

for i in d:
    opsarr = list(itertools.product('+*', repeat=len(d[i][1]) - 1))
    if (right_result(d[i][0], d[i][1], opsarr)):
        total += d[i][0]

print("Part1: ", total)
et = time.time()
print('ex time: ', et-st, " s")

st = time.time()

total = 0
for i in d:
    opsarr1 = list(itertools.product('+*|', repeat=len(d[i][1]) - 1))
    if (right_result(d[i][0], d[i][1], opsarr1)):
        total += d[i][0]

print("Part2: ", total)

et = time.time()
print('ex time: ', et-st, " s")