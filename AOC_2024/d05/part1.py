#!/usr/local/bin/python3

import time
import signal
import copy
st = time.time()


with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

cmax = 0
r = 0 
d = {}

for row in rows:
    temp = [item for item in row]
    cmax = len(temp)
    for c in range(cmax):
        d[(r,c)] = [temp[c], 0, []]
    r += 1


def find_start(d):
    for i in d:
        if d[i][0] == "^":
            return (i,1)

def di_count(arr, di):
    dc = 0
    for i in arr:
        if i == di:
            dc += 1
    return (dc)

def repeated(arr, di):
    if (len(arr) == 0):
        return (False)
    for i in arr:
        if i == di:
            return(True)
    return (False)

def traverse(d, r, c, cmax, di):
    while (r >= 0 and c >= 0 and r < cmax and c < cmax):
        if d[(r,c)][0] != "#":
            if repeated(d[(r,c)][2], di):
                # print(d[(r,c)][2])
                return (d, 1)
            else:
                d[(r,c)][0] = "X"
                d[(r,c)][1] =  1
                d[(r,c)][2].append(di)
        if (di == 1):
            if r-1 < 0:
                break
            elif d[(r-1,c)][0] == "#":
                di = 2
            else:
                r -= 1
        elif (di == 2):
            if c + 1 >= cmax:
                break
            elif d[(r ,c+1)][0] == "#":
                di = 3
            else:
                c += 1
        elif (di == 3):
            if r + 1 >= cmax:
                break
            elif d[(r+1 ,c)][0] == "#":
                di = 4
            else:
                r += 1
        elif (di == 4):
            if c - 1 < 0:
                break
            elif d[(r ,c-1)][0] == "#":
                di = 1
            else:
                c -= 1
    return (d, 0)


loc,di = find_start(d.copy())
cpy = copy.deepcopy(d)
new_d, xi = traverse(cpy, loc[0], loc[1], cmax, di)

count = 0
path = {}
for i in new_d:
    if (new_d[i][0] == "X" and new_d[i][1] ==  1):
        if (not i == (loc)):
            path[(i)] = i
        count += 1
print(count)


def print_grid(grid):
    for i in range(cmax):
        arr = []
        for item in grid:
            if (item[0] == i):
                arr.append(grid[item][0])
        print(arr)

new_count = 0

for i in path:
    cpy = copy.deepcopy(d)
    if i != (loc[0],loc[1]):
        if cpy[i][0] == "." or cpy[i][0] == "^":
            print(i)
            cpy[i] = ["#", 0, []]
            ret, xi = traverse(cpy, loc[0], loc[1], cmax, 1)
            if (xi == 1):
                new_count += 1
        


print(new_count)

et = time.time()
print('ex time: ', et-st, " s")