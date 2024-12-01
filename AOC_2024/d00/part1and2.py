#!/usr/local/bin/python3

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

def dup_count(li, val):
    ret = 0
    idx = 0
    while (idx < size):
        if (li[idx] == val):
            ret += 1
        idx += 1
    return (ret)

first.sort()
second.sort()

diff = 0
i = 0
while (i < size):
    diff += abs(first[i] - second[i])
    i += 1

i = 0
sim_score = 0
while (i < size):
    sim_score += first[i] * dup_count(second, first[i])
    i += 1

print("part 1: ", diff)
print("part 2: ", sim_score)
