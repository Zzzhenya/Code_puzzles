import math

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

row_count = 0
for row in rows:
	row_count += 1

d = {}
i = 1
val = 0;
match_arr = []
for row in rows:
    winning = []
    num2 = []
    num = row.split(':')[1]
    winning = num.split('|')[0].split()
    mynum = (num.split('|')[1]).split()

    winning1 = []
    for win in winning:
        winning1.append(int(win))
    mynum1 = []
    for num in mynum:
        mynum1.append(int(num))

    count = 0;
    for win in winning1:
        for num in mynum1:
            if win == num:
                count += 1
    d[i] = [i, count, []]
    match_arr.append(count)
    i += 1
#print(d)
for key in d:
	i = 1
	while i <= row_count + 1:
		d[key][2].append(0)
		i += 1
i = 1
val = 0
'''
for key in d:
	d[key][2][i] = 1
	num = d[key][1]
	j = 1
	while (j <= num & j <= row_count):
		d[key][2][i + j] = d[key][2][i]
		j += 1
	i += 1'''
key = 1
while (key <= row_count):
	d[key][2][key] += 1
	num = d[key][1]
	k = key;
	val = 0
	while (k >= 1):
		val += d[k][2][key]
		k -= 1
	j = 1
	while j <= row_count:
		if (key + j <= num):
			d[key][2][key + j] += val
		j += 1
	key += 1
#print(d)
'''
j = 1
while j <= num:
	if (i + j <= row_count):
		d[key][2][i + j] = d[key][2][i]
	j += 1
i += 1
key = 2
d[key][2][i] += 1
num = d[key][1]
print(num)
j = 1
while j <= num:
	if (i + j <= row_count):
		d[key][2][i + j] = d[key][2][i]
	j += 1


i += 1'''

#print (val)
print(d[1])
print(d[2])
print(d[3])
print(d[4])