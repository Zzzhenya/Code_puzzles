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
#>>
row = 0
while row < n:
    col = 0
    while col < n - 3:
        word = ""
        for i in range(4):
            word += arr[row][col + i]
        if word == "XMAS":
            count += 1
        col += 1
    row += 1
# print(">> :", count)
#<<
row = 0
while row < n:
    col = n - 1
    while col > 2:
        word = ""
        for i in range(4):
            word += arr[row][col - i]
        if word == "XMAS":
            count += 1
        col -= 1
    row += 1
# print("<< :", count)
#VV
col = 0
while col < n:
    row = 0
    while row < n - 3:
        word = ""
        for i in range(4):
            word += arr[row + i][col]
        if word == "XMAS":
            count += 1
        row += 1
    col += 1
# print("VV :", count)
#^^
col = 0
while col < n:
    row = n - 1
    while row > 2:
        word = ""
        for i in range(4):
            word += arr[row - i][col]
        if word == "XMAS":
            count += 1
        row -= 1
    col += 1
# print("^^ :", count)
#\>
row = 0
while (row < n - 3):
    col = 0
    while (col < n - 3):
        word = ""
        for i in range(4):
            word += arr[row + i][col + i]
        if word == "XMAS":
            count += 1
        col += 1
    row += 1
# print("\\> :", count)
#/>
row = n - 1
while (row > 2):
    col = 0
    while (col < n - 3):
        word = ""
        for i in range(4):
            word += arr[row - i][col + i]
        if word == "XMAS":
            count += 1
        col += 1
    row -= 1
# print("/> :", count)
#\<
row = n - 1
while (row > 2):
    col = n - 1
    while (col > 2):
        word = ""
        for i in range(4):
            word += arr[row - i][col - i]
        if word == "XMAS":
            count += 1
        col -= 1
    row -= 1
# print("\< :", count)
#/<
row = 0
while (row < n - 3):
    col = n - 1
    while (col > 2):
        word = ""
        for i in range(4):
            word += arr[row + i][col - i]
        if word == "XMAS":
            count += 1
        col -= 1
    row += 1
# print("/< :", count)
print("count: ", count)

et = time.time()
print('ex time: ', et-st, " s")