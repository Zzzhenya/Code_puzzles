#!/usr/local/bin/python3
from collections import deque 

def compute(line):
	line1= deque([])
	times = 25
	i = 0
	while (i < times):
		for item in line:
			if (item == 0):
				line1.append(1)
			elif (item != 0 and not len(str(item))%2):
				temp = str(item)
				size =  len(temp)
				loc = size//2
				first = int(temp[:loc])
				second = int (temp[loc:])
				line1.append(first)
				line1.append(second)
			else:
				line1.append(item * 2024)
		line = line1
		line1 = deque([])
		print(i, ": ",len(line))
		i += 1
	return (line)

series = deque([814,1183689,0,1,766231,4091,93836,46])

new_line = compute(series)
print(len(new_line))
