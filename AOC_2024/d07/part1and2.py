#!/usr/local/bin/python3

import time
import itertools
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

d = {}
rowmax = 0
dictlen  = 0
for row in rows:
    r = list(row)
    colmax = 0
    for i in r:
        if i.isalnum():
            d[dictlen] = [rowmax,colmax,i]
            dictlen +=1
        colmax += 1
    rowmax += 1

def within_bounds(tp):
    row = tp[0]
    col = tp[1]
    if (row < rowmax and col < colmax and row >= 0 and col >= 0):
        return (True)
    return (False)

def find_next(d, cur, start):
    while (start < dictlen):
        if (d[start][2] == d[cur][2]):
            return (start)
        start += 1
    return (0)

def get_antinodes(d, first, second):
    res = []
    # print("combi: ",d[first], d[second])
    dr = d[second][0] - d[first][0]
    dc = d[second][1] - d[first][1]
    one = (d[first][0] - dr, d[first][1] - dc)
    if (within_bounds(one)):
        res.append(one)
    two = ((d[second][0] + dr, d[second][1] + dc))
    if (within_bounds(two)):
        res.append(two)
    return (res)

def get_new_antinodes(d, first, second):
    res = []
    dr = d[second][0] - d[first][0]
    dc = d[second][1] - d[first][1]
    one = (d[first][0] - dr, d[first][1] - dc)
    while (within_bounds(one)):
        res.append(one)
        one = (one[0] - dr, one[1] - dc) 
    two = ((d[second][0] + dr, d[second][1] + dc))
    while (within_bounds(two)):
        res.append(two)
        two = (two[0] + dr, two[1] + dc)
    res.append((d[first][0], d[first][1]))
    res.append((d[second][0], d[second][1]))
    return (res)

ret = []
new_ret = []
i = 0
while i < dictlen:
    j = i + 1
    while (j < dictlen):
        nxt = find_next(d, i, j)
        if (nxt > 0):
            ret += get_antinodes(d, i, nxt)
            new_ret += get_new_antinodes(d, i, nxt)
            j = nxt + 1
        else:
            j += 1
    i += 1

res = set(ret)
new_res = set(new_ret)

print("Part1", len(res))
print("Part2", len(new_res))

et = time.time()
print('ex time: ', et-st, " s")