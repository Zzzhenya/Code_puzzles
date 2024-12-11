#!/usr/local/bin/python3 

def compute(d, times):
	i = 0
	d1 = d.copy()
	while (i < times):
		for key,val in d.items():
			d1[key] = d1.get(key, 0) - val
			if key == 0:
				d1[1] = d1.get(1, 0) + val
			elif (key != 0 and not len(str(key))%2):
				temp = str(key)
				size =  len(temp)
				first = int(temp[:size//2])
				second = int (temp[size//2:])
				d1[first] = d1.get(first, 0) + val
				d1[second] = d1.get(second, 0) + val
			else:
				d1[key * 2024] = d1.get(key * 2024, 0) + val
		i += 1
		d = d1.copy()
	# print(d1)
	return (d1)

d = {}
series = [814,1183689,0,1,766231,4091,93836,46]
for item in series:
	d[item] = 1
print(d)
new_d = compute(d, 75)
total = 0
for item in new_d:
	total += new_d[item]

print(total)

dx = {}
print("dict.get(1, 0)\t:", dx.get(1, 0))
print("dict.get(1)\t:",dx.get(1))

