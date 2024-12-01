#!/usr/local/bin/python3

import time
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

first = []
second = []
size = 0
for row in rows:
    duo  = row.split()
    first.append(int(duo[0]))
    second.append(int(duo[1]))
    size += 1

first.sort()
second.sort()

def dup_count(li, val, loc):
    ret = 0
    while (loc < size and li[loc] <= val):
        if (li[loc] == val):
            ret += 1
        loc += 1
    return (ret, loc)

i = 0
diff = 0
sim_score = 0
loc = 0
while (i < size):
    diff += abs(first[i] - second[i])
    ret, loc = dup_count(second, first[i], loc)
    sim_score += first[i] * ret
    i += 1

print("part 1: ", diff)
print("part 2: ", sim_score)
et = time.time()
print('ex time: ', et-st, " s")
