

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

numbers = {
    "blue" : 14, 
    "red" : 13 , 
    "green": 12}
#revnumbers = ["eno", "owt", "eerht", "ruof", "evif", "xis", "neves", "thgie", "enin"]
count = 0

for row in rows:
    count = count + 1;
    #print (row)


d = {}
d2 = {}
lst = []
lst2 = []
tup = {}

i = 0
#while i < count:
#    lst.append(i)
#    i = i + 1

#for i in lst:
#        d[i] = []
#        d2[i] = []
#        tup[i] = []

i = 0

for row in rows:
    lst.append(row.split(':')[0].split(' ')[1])
    lst.append(row.split(':')[1].split(',').split(' '))
    i += 1


print(lst)


'''
#Extracting from start

word = []
i = 0
for row in rows:
    for letter in row:
        if letter.isnumeric():
            d[i].append(letter);
        else:
            word.append(letter);
            s = ''.join(word)
            j = 0;
            for number in numbers:
                if number in s:
                    d[i].append(j+1)
                    word.clear()
                    j = 0
                j += 1
    tup[i].append(d[i][0])
    i += 1;

#Extracting from end

word = []
i = 0

for row in rows:
    j = len(row) - 1;
    while (j >= 0):
        if row[j].isnumeric():
            d2[i].append(row[j]);
        else:
            word.append(row[j]);
            s = ''.join(word)
            k = 0;
            for number in revnumbers:
                if number in s:
                    d2[i].append(k+1)
                    word.clear()
                    k = 0
                k += 1
        j -= 1;
    tup[i].append(d2[i])
    i += 1;


val = 0
for i in tup:
    val += int(tup[i][0]) * 10 + int(tup[i][1][0])
#for i in tup:
#    print(tup[i])
#    print(tup[i][0])
#    print(tup[i][1][0])
print(val)'''