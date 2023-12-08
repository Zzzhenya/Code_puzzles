string = "LRRRLRRRLRRLRRLRLRRLRRLRRRLRRLRRRLRRRLLRRRLRRRLRRRLRLRRLRRRLRLRRRLRRRLLRLRLRRLRRLLLRRLRRLRRRLLRRRLLRRRLRLRRRLRRRLLRRLRLLRLRRRLRRLRRLRLRLRLRLRLRRRLRLRRRLLRLRRLRRRLRRRLRLRRLRLLLRLRLRLRLRLRRRLLRRLRLRLLRRRLRRLRRRLRRLRRLRRRLLRRLRLRRLRRRLRRLRLRRLRLLRRLLRLRRRLRRLRLLRRRR"
import re
import math
inst = []
inst = [x for x in string]

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

d = {}
i = 0
for row in rows:
	d[i] = []
	lst = []
	lst.append(row.split(" = ")[0])
	lst.append(row.split(" = ")[1].strip("()").split(", ")[0])
	lst.append(row.split(" = ")[1].strip("()").split(", ")[1])
	d[i] = lst
	i += 1

size = i
i = 0
#print(d)
#print(d[0])
#print(i)
key = 0
steps = 0
curr = 0
nxt1 = nxt2 = nxt3 = nxt4 = nxt5 = 0

k = 0;
while (key < size - 1):
	curr = d[key]
	#if (curr[0][2] == 'A'):
	if (re.search("A$", curr[0])):
		if (k == 0):
			curr1 = curr
		if (k == 1):
			curr2 = curr
		if k == 2:
			curr3 = curr
		if (k == 3):
			curr4 = curr
		if (k == 4):
			curr5 = curr
			break
		k += 1
	key += 1

print(curr1, curr2, curr3, curr4, curr5)
#while(re.search("Z$", nxt1)>0):

x = 0
while (not x):
	for l in inst:
		steps += 1
		if (l == 'L'):
			nxt1 = curr1[1]
		else:
			nxt1 = curr1[2]
		x = (nxt1[2] == "Z")
		key = 0
		while (key < size - 1):
			curr = d[key]
			if (nxt1 == curr[0]):
				curr1 = curr
				break;
			key += 1		
print(steps)
x = 0
while (not x):
	for l in inst:
		steps += 1
		if (l == 'L'):
			nxt2 = curr2[1]
		else:
			nxt2 = curr2[2]
		x = (nxt2[2] == "Z")
		key = 0
		while (key < size - 1):
			curr = d[key]
			if (nxt2 == curr[0]):
				curr2 = curr
				break;
			key += 1		
print(steps)
x = 0
while (not x):
	for l in inst:
		steps += 1
		if (l == 'L'):
			nxt3 = curr3[1]
		else:
			nxt3 = curr3[2]
		x = (nxt3[2] == "Z")
		key = 0
		while (key < size - 1):
			curr = d[key]
			if (nxt3 == curr[0]):
				curr3 = curr
				break;
			key += 1		
print(steps)
x = 0
while (not x):
	for l in inst:
		steps += 1
		if (l == 'L'):
			nxt5 = curr5[1]
		else:
			nxt5 = curr5[2]
		x = (nxt5[2] == "Z")
		key = 0
		while (key < size - 1):
			curr = d[key]
			if (nxt5 == curr[0]):
				curr5 = curr
				break;
			key += 1		
print(steps)

print(math.gcd(11309,30508,42869,56808))
