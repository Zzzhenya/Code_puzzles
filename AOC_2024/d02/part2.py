#!/usr/local/bin/python3

import time
import re
st = time.time()

with open('input.txt', 'r') as input_data:
	rows = [line.strip() for line in input_data.readlines()]

total = 0
string = ""
for row in rows:
	string += row
temp = string.split("do()")
for i in temp:
	res = re.search("don't\\(\\)", i)
	if res is not None:
		res = i[:res.start()]
	else:
		res = i
	arr = re.findall("mul\\([0-9]+\\,[0-9]+\\)", res)
	for item in arr:
		ret = re.findall("[0-9]+\\,[0-9]+", item)
		for i in ret:
			val = i.split(',')
			total += (int(val[0]) * int(val[1]))
print(total)

et = time.time()
print('ex time: ', et-st, " s")

# sum = 0
# for row in rows:
# 	temp = []
# 	temp = row.split("do()")
# 	for i in temp:
# 		res = re.search("don't\\(\\)", i)
# 		if res is not None:
# 			first = i[:res.start()]
# 			second = i[res.end():]
# 			if "do()" in second:
# 				print(second)
# 			res = first + second
# 		else:
# 			res = i
# 		arr = re.findall("mul\\([0-9]+\\,[0-9]+\\)", res)
#         # print(arr)
# 		for item in arr:
# 			ret = re.findall("[0-9]+\\,[0-9]+", item)
# 			for i in ret:
# 				val = i.split(',')
# 				sum += (int(val[0]) * int(val[1]))
# print(sum)