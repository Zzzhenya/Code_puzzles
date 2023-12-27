string = "LRRRLRRRLRRLRRLRLRRLRRLRRRLRRLRRRLRRRLLRRRLRRRLRRRLRLRRLRRRLRLRRRLRRRLLRLRLRRLRRLLLRRLRRLRRRLLRRRLLRRRLRLRRRLRRRLLRRLRLLRLRRRLRRLRRLRLRLRLRLRLRRRLRLRRRLLRLRRLRRRLRRRLRLRRLRLLLRLRLRLRLRLRRRLLRRLRLRLLRRRLRRLRRRLRRLRRLRRRLLRRLRLRRLRRRLRRLRLRRLRLLRRLLRLRRRLRRLRLLRRRR"

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

print(d)
size = i
i = 0
#print(d)
#print(d[0])
#print(i)
key = 0
steps = 0
curr = 0
nxt = 0

while (key < size - 1):
	curr = d[key]
	if (curr[0][2] == "AAA"):
		break
	key += 1

while (nxt != "ZZZ"):
	for l in inst:
		steps += 1
		if (l == 'L'):
			nxt = curr[1]
		else:
			nxt = curr[2]
		key = 0
		while (key < size - 1):
			curr = d[key]
			if (nxt == curr[0]):
				#print(steps, curr)
				break
			key += 1
print(steps)
