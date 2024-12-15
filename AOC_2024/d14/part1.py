#!/usr/local/bin/python3

import time
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]
check = 0
d = {}
arr = []
r = 0
for row in rows:
	if (check == 0 and len(row) != 0):
		for i in range (len(row)):
			d[(r, i)] = d.get((r, i), row[i])
		r += 1
	elif(check == 0 and len(row) == 0):
		check = 1
		continue
	else:
		for i in range (len(row)):
			arr.append(row[i])

def find_bot(d, c):
	for key,value in d.items():
		if value == c:
			return (key)

loc = find_bot(d,'@')
print(loc)

d[loc] = '.'

def make_moves(d, arr, r, c):
	for move in arr:
		if (move == '>'):
			if (d[(r, c + 1)] == '.'):
				c += 1
			elif (d[(r, c + 1)] == 'O'):
				new = c + 1
				while (d[(r, new)] == 'O'):
					new += 1
				if (d[(r, new)] == '.'):
					d[(r, c + 1)] = '.'
					d[(r, new)] = 'O'
					c += 1
		elif (move == '<'):
			if (d[(r, c - 1)] == '.'):
				c -= 1
			elif (d[(r, c - 1)] == 'O'):
				new = c - 1
				while (d[(r, new)] == 'O'):
					new -= 1
				if (d[(r, new)] == '.'):
					d[(r, c - 1)] = '.'
					d[(r, new)] = 'O'
					c -= 1
		elif (move == 'v'):
			if (d[(r + 1, c)] == '.'):
				r += 1
			elif (d[(r + 1, c)] == 'O'):
				new = r + 1
				while (d[(new, c)] == 'O'):
					new += 1
				if (d[(new, c)] == '.'):
					d[(r + 1, c)] = '.'
					d[(new, c)] = 'O'
					r += 1
		elif (move == '^'):
			if (d[(r - 1, c)] == '.'):
				r -= 1
			elif (d[(r - 1, c)] == 'O'):
				new = r - 1
				while (d[(new, c)] == 'O'):
					new -= 1
				if (d[(new, c)] == '.'):
					d[(r - 1, c)] = '.'
					d[(new, c)] = 'O'
					r -= 1
	return (d)



d = make_moves(d, arr, loc[0], loc[1])



def calculate(d):
	ret = 0
	for key,value in d.items():
		if value == 'O':
			ret += (100 * key[0]) +  key[1]
	return (ret)


print("result: ", calculate(d))

# for i in d:
# 	print(i, ": ", d[i])

# for i in arr:
# 	print(i)

et = time.time()
print('ex time: ', et-st, " s")