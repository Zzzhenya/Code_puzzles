with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

lst = []
d = {}
i = 0

for row in rows:
	d[i] = []
	str = row.split(' ')[0]
	lst = [x for x in str]
	d[i] = lst
	i += 1

cards = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']

for row in d:
	for card in cards:
		d[row].append(int(d[row].count(card)))
	print(d[row])
	#print(d[row])

for row in d:
	for i in range(5, 17):
		if (d[row][i] == 3):
			print(d[row])
		else if ()