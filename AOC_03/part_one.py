import math

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

i = 0
val = 0;
for row in rows:
    winning = []
    num2 = []
    num = row.split(':')[1]
    winning = num.split('|')[0].split()
    mynum = (num.split('|')[1]).split()

    print(row)
    winning1 = []
    for win in winning:
        winning1.append(int(win))

    mynum1 = []
    for num in mynum:
        mynum1.append(int(num))

    count = 0;
    a = []
    for win in winning1:
        for num in mynum1:
            if win == num:
                a.append(win)
                count += 1
    if (count > 0):
        val += math.pow(2, count - 1)
    else:
        val += 0
    i += 1
print ("val: ", val)