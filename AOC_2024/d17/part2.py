#!/usr/local/bin/python3

import time
import copy

st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

# size = 7
size = 71

bytarr = []
for row in rows:
	c,r = row.split(',')
	r = int(r)
	c = int(c)
	bytarr.append((r,c))

def add_byte(bytarr, bites, d):
	curr = 0
	for i in bytarr:
		if (curr < bites):
			d[i] = '#'
			curr += 1
		else:
			break
	return (d)


# def print_d(d):
# 	for i in range(size):
# 		arr = ""
# 		for key,value in d.items():
# 			if (key[0] == i):
# 				arr+=" " + (value)
# 		print(arr)
# 	print("\n")


def dfs(d, v):
	Q = []
	dist = 0
	Q.append([v, dist])
	d[v] = str(dist)
	while (len(Q) > 0):
		val, dist = Q.pop(0)
		if (val[0] == size - 1 and val[1] == size - 1):
			return (True)
		W = [(val[0],val[1] + 1), (val[0],val[1] - 1), (val[0] + 1,val[1]), (val[0] - 1,val[1])]
		for w in W:
			if w[0] < size and w[0] >= 0 and w[1] < size and w[1] >= 0:
				if (d[w] == 'O'):
					Q.append([w, dist + 1])
					d[w] = str(dist + 1)
	return (False)

def reset_d(d, size):
	for r in range(size):
		for c in range(size):
			d[(r,c)] = 'O'
	return (d)

d = {}
d = reset_d(d, size)
loc = 0
d = add_byte(bytarr, 1024 * 2 + 800, d)
i = 1024 * 2 + 800
while (i > 0):
	val = bytarr[i]
	d[val] = '#'
	d1 = copy.deepcopy(d)
	if (dfs(d1, (0,0)) == False):
		print(val[1], val[0])
		break
	else:
		print(loc)
		loc += 1
	i+= 1

et = time.time()
print('ex time: ', et-st, " s")
