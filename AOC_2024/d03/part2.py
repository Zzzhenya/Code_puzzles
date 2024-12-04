#!/usr/local/bin/python3

import time
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

n = 0
arr = []

for row in rows:
    temp = []
    for item in row:
        temp.append(item)
    arr.append(temp)
    n += 1

count = 0

row = 1
while row < n - 1:
    col = 1
    while col < n - 1:
        if arr[row][col] == 'A':
            if arr[row-1][col-1] == 'M' and arr[row-1][col+1] == 'M' and arr[row+1][col+1] == 'S' and arr[row+1][col-1] == 'S':
                count +=1
            elif arr[row-1][col-1] == 'M' and arr[row-1][col+1] == 'S' and arr[row+1][col+1] == 'S' and arr[row+1][col-1] == 'M':
                count +=1
            elif arr[row-1][col-1] == 'S' and arr[row-1][col+1] == 'S' and arr[row+1][col+1] == 'M' and arr[row+1][col-1] == 'M':
                count += 1
            elif arr[row-1][col-1] == 'S' and arr[row-1][col+1] == 'M' and arr[row+1][col+1] == 'M' and arr[row+1][col-1] == 'S':
                count +=1
        col += 1
    row += 1

print("count: ", count)

et = time.time()
print('ex time: ', et-st, " s")