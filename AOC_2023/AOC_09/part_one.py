with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

lines = []
col_count= 0
for row in rows:
	line = []
	line = [x for x in row]
	lines.append(line)
	col_count += 1
row_count = len(lines[0])
print (col_count, row_count)

def look_for_s(lines, col_max, row_max):
	row = 0
	while (row < row_max):
		col = 0
		while (col < col_max):
			if lines[row][col] == "S":
				return(row,col)
			col += 1
		row += 1

y0, x0 = (look_for_s(lines, col_count, row_count))

def go_to_next(lines, y0, x0):
	if lines[y0][x0] == "S":
	#next_p = lines[row-1][col]
		y1, x1 = y0 - 1, x0
	#while (lines[y1][x1] != "S"):
		if (lines[y1][x1] == "|" and lines[y1 - 1][x1] == "S"):
			if (y1 + 1 < col_count):
				y0,x0 = y1 + 1, x1
				lines[y0][x0] = "S"
		if (lines[y0][x0] == "|" and lines[y0 + 1][x0] == "S"):
			if (y0 - 1 >= 0):
				y1,x1 = y0 - 1, x0
				lines[y0][x0] = "S"
		return(lines)
		'''
		else if (lines[y0][x0] == "-" and lines[y0][x0 - 1] == "S"):
			if (x0 + 1 < row_count):
				y1,x1 = y0, x0 + 1
				lines[y0][x0] = "S"
		else if (lines[y0][x0] == "-" and lines[y0][x0 + 1] == "S"):
			if (x0 - 1 >= 0):
				y1,x1 = y0, x0 - 1
				lines[y0][x0] = "S"'''



#curr = lines[row][col]
#if lines[y0][x0] == "S":
	#next_p = lines[row-1][col]
	#y1, x1 = y0 - 1, x0
#curr = next_p
#y0, x0 = y1, x1

lines = go_to_next(lines,y0, x0)
print(lines[y0 -1])
print(lines[y0])
print(lines[y0+1])