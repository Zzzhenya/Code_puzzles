#!/usr/local/bin/python3

import time

st = time.time()
with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

line = rows[0]

d = list(line)
d = [int(item) for item in d]

loc = 0
i = 1
arr = []
for item in d:
    if (i%2):
        temp = [loc, item]
        loc += 1
    else:
        temp = [-1, item]
    arr.append(temp)
    i += 1

def print_arr(arr):
    i = 0
    temp = []
    for item in arr:
        for j in range(item[1]):
                temp.append(item[0])
        i += item[1]
    print(temp)

def total_count(arr):
    i = 0
    total = 0
    for item in arr:
        for j in range(item[1]):
            if (item[0] != -1):
                total += ((i + j) * item[0])
        i += item[1]
    return (total)

loc = 0
rev_it = len(arr) - 1   
while (rev_it >= 0):
    i = 0
    while (i < rev_it):
        if (arr[rev_it][0] != -1 and arr[i][0] == -1 and arr[rev_it][1] <= arr[i][1]):
            temp = [arr[rev_it][0], arr[rev_it][1]]
            arr[i][1] = arr[i][1] - arr[rev_it][1]
            arr.insert(i, temp)
            i += 1
            rev_it += 1
            arr[rev_it][0] = -1
            break
        else:
            i += 1
    print(rev_it)
    rev_it -= 1

print(total_count(arr))


et = time.time()
print('ex time: ', et-st, " s")