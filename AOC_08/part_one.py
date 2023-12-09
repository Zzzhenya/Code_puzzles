with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]
lines = []
for row in rows:
	row = row.split(' ')
	row = [int(x) for x in row]
	lines.append(row)
print(len(row))

def get_diff(num, line, count):
	diff = []
	i = 0
	while i < num - 1 :
		diff.append(line[i + 1] - line[i])
		i += 1
	x = any(diff)
	if (not x):
		count += diff[len(diff)-1]
		return(count)
	if (x):
		count += diff[len(diff)-1]
		return(get_diff(num-1, diff, count))

total = 0
for line in lines:
	val = get_diff(len(line), line, 0)
	final_val = line[len(line) - 1] + val
	total += final_val

print("Total", total)
