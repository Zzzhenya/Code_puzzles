#!/usr/local/bin/python3

import time
from collections import deque
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

# size = 7
# bites = 12
size = 71
bites = 1024


d = {}
for r in range(size):
	for c in range(size):
		d[(r,c)] = 'O'

curr = 0
for row in rows:
	if (curr < bites):
		c,r = row.split(',')
		r = int(r)
		c = int(c)
		d[(r,c)] = '#'
		curr += 1
	else:
		break


def print_d(d):
	for i in range(size):
		arr = ""
		for key,value in d.items():
			if (key[0] == i):
				arr+=" " + (value)
		print(arr)
	print("\n")

# print_d(d)


def dfs(d, v):
	Q = []
	dist = 0
	Q.append([v, dist])
	d[v] = str(dist)
	# print_d(d)
	while (len(Q) > 0):
		# dist += 1
		val, dist = Q.pop(0)
		if (val[0] == size - 1 and val[1] == size - 1):
			print(dist)
		W = [(val[0],val[1] + 1), (val[0],val[1] - 1), (val[0] + 1,val[1]), (val[0] - 1,val[1])]
		for w in W:
			if w[0] < size and w[0] >= 0 and w[1] < size and w[1] >= 0:
				if (d[w] == 'O'):
					Q.append([w, dist + 1])
					d[w] = str(dist + 1)
		# dist += 1
	# print_d(d)

dfs(d, (0,0))



et = time.time()
print('ex time: ', et-st, " s")
