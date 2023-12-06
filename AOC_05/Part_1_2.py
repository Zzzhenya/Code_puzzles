t = 46
d = 214

i = 1
count1 = 0
while (i <= t):
	dis = i * (t - i)
	if (dis > d):
		count1 += 1
	i +=1

print (count1)

t = 80
d = 1177

i = 1
count2 = 0
while (i <= t):
	dis = i * (t - i)
	if (dis > d):
		count2 += 1
	i +=1

print (count2)

t = 78
d = 1402

i = 1
count3 = 0
while (i <= t):
	dis = i * (t - i)
	if (dis > d):
		count3 += 1
	i +=1

print (count3)

t = 66
d = 1024

i = 1
count4 = 0
while (i <= t):
	dis = i * (t - i)
	if (dis > d):
		count4 += 1
	i +=1

print (count4)
print (count1 * count2 * count3 * count4)

t = 46807866
d = 214117714021024

i = 1
countf = 0
while (i <= t):
	dis = i * (t - i)
	if (dis > d):
		countf += 1
	i +=1

print (countf)