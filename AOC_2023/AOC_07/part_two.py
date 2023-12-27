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
steps1 = 0
curr = 0
nxt1 = nxt2 = nxt3 = nxt4 = nxt5 = ""

k = 0;
while (key < size):
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
		if (k == 5):
			curr6 = curr
			break
		k += 1
	key += 1

print(curr1, curr2, curr3, curr4, curr5, curr6)
#while(re.search("Z$", nxt1)>0):

x = 0
check = 0
while (not x):
	for l in inst:
		steps1 += 1
		if (l == 'L'):
			nxt1 = curr1[1]
		else:
			nxt1 = curr1[2]
		x = (nxt1[2] == "Z") 
		key = 0
		check = 0
		while (key < size):
			curr = d[key]
			if (nxt1 == curr[0]):
				curr1 = curr
				check += 1
				break
			key += 1	
	
print(steps1)
steps2 = 0
x = 0
while (not x):
	for l in inst:
		steps2 += 1
		if (l == 'L'):
			nxt2 = curr2[1]
		else:
			nxt2 = curr2[2]
		x = (nxt2[2] == "Z")
		key = 0
		while (key < size):
			curr = d[key]
			if (nxt2 == curr[0]):
				curr2 = curr
				break;
			key += 1		
print(steps2)
steps3 = 0
x = 0
while (not x):
	for l in inst:
		steps3 += 1
		if (l == 'L'):
			nxt3 = curr3[1]
		else:
			nxt3 = curr3[2]
		x = (nxt3[2] == "Z")
		key = 0
		while (key < size):
			curr = d[key]
			if (nxt3 == curr[0]):
				curr3 = curr
				break;
			key += 1		
print(steps3)
steps5 = 0
x = 0
while (not x):
	for l in inst:
		steps5 += 1
		if (l == 'L'):
			nxt5 = curr5[1]
		else:
			nxt5 = curr5[2]
		x = (nxt5[2] == "Z")
		key = 0
		while (key < size):
			curr = d[key]
			if (nxt5 == curr[0]):
				curr5 = curr
				break;
			key += 1		
print(steps5)
steps4 = 0
x = 0
while (not x):
	for l in inst:
		steps4 += 1
		if (l == 'L'):
			nxt4 = curr4[1]
		else:
			nxt4 = curr4[2]
		x = (nxt4[2] == "Z")
		key = 0
		while (key < size):
			curr = d[key]
			if (nxt4 == curr[0]):
				curr4 = curr
				break;
			key += 1		
print(steps4)
steps6 = 0
x = 0
while (not x):
	for l in inst:
		steps6 += 1
		if (l == 'L'):
			nxt6 = curr6[1]
		else:
			nxt6 = curr6[2]
		x = (nxt6[2] == "Z")
		key = 0
		while (key < size):
			curr = d[key]
			if (nxt6 == curr[0]):
				curr6 = curr
				break;
			key += 1		
print(steps6)
print(math.lcm(steps1, steps2, steps3, steps4, steps5, steps6))
