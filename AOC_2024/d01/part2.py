#!/usr/local/bin/python3

import time
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

def duo_diff_in_range(a, b):
	val = abs(a - b)
	if (val < 1):
		return (False)
	if (val > 3):
		return (False)
	return (True)

def diff_is_in_range(arr, size):
	i = 0
	while (i < size and i + 1 < size):
		if not duo_diff_in_range(arr[i], arr[i + 1]):
			return (False)
		i += 1
	return (True)


count = 0
for row in rows:
	ret  = row.split()
	arr = []
	for i in ret:
		arr.append(int(i))
	size = 0
	for i in arr:
		size += 1
	if (diff_is_in_range(arr, size)) and (arr == sorted(arr) or arr  == sorted(arr, reverse=True)):
		count += 1
	else:
		idx = 0
		while (idx < size):
			temp = arr.copy()
			temp.pop(idx)
			if (diff_is_in_range(temp, size-1)) and (temp == sorted(temp) or temp  == sorted(temp, reverse=True)):
				count += 1
				break
			idx += 1
    
print("count: ", count)
et = time.time()
print('ex time: ', et-st, " s")