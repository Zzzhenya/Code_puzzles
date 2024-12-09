#!/usr/local/bin/python3

import time
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

line = rows[0]

d = list(line)
d = [int(item) for item in d]
print(d)
i = 1
mem = []
loc = 0
for item in d:
    if (i%2):
        rep = 0
        while (rep < item):
            mem.append(loc)
            rep += 1
        if (item > 0):
            loc += 1
    else:
        rep = 0
        while (rep < item):
            mem.append('.')
            rep += 1
    i += 1

size = len(mem)
end = size - 1
start = 0
while (start != end):
    if mem[start] == '.' and mem[end] != '.':
        temp = mem[end]
        mem[end] = '.'
        mem[start] = temp
    if mem[start] != '.':
        start += 1
    if mem[end] == '.':
        end -= 1

loc = 0
total = 0
for item in mem:
    if item != '.':
        total += item * loc
    loc += 1

print("Part1: ", total)

et = time.time()
print('ex time: ', et-st, " s")