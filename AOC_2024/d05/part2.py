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
    # print(temp, len(temp))


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
            d[(r,c)][0] = "X"
            d[(r,c)][1] =  1
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
# print(loc[0], loc[1], "up" if di==1 else "other")
cpy = copy.deepcopy(d)
new_d, xi = traverse(cpy, loc[0], loc[1], cmax, di)

count = 0
path = {}
for i in new_d:
    if (new_d[i][0] == "X" and new_d[i][1] ==  1):
        if count != 0:
            path[(i)] = i
        count += 1
    # print(i, new_d[i])
print(count)

def signal_handler(signum, frame):
    raise Exception("Timed out!")

signal.signal(signal.SIGALRM, signal_handler)


def print_grid(grid):
    for i in range(cmax):
        arr = []
        for item in grid:
            if (item[0] == i):
                arr.append(grid[item][0])
        print(arr)

new_count = 0

for i in path:
    if i != (loc[0],loc[1]):
        if d[i][0] == "." or d[i][0] == "^":
            # print(i)
            cpy = copy.deepcopy(d)
            cpy[i] = ["#", 0, []]
            signal.setitimer(signal.ITIMER_REAL, 0.3, 0.3)
            try:
                ret, xi = traverse(cpy, loc[0], loc[1], cmax, 1)
                signal.setitimer(signal.ITIMER_REAL, 0)
            except Exception:
                print("timeout", new_count)
                new_count += 1
                signal.setitimer(signal.ITIMER_REAL, 0)



print(new_count)

et = time.time()
print('ex time: ', et-st, " s")