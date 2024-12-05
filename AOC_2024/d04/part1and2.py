#!/usr/local/bin/python3

import time
st = time.time()

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]
i = 0;
rules = {}
manuals = {}
first = True
for row in rows:
    if (len(row) == 0):
        first = False
        i = 0
    if (first):
        res = row.split('|')
        rules[i] = [int(item) for item in res]
        i +=1
    else:
        if len(row) > 0:
            res = row.split(',')
            manuals[i] = [int(item) for item in res]
            i +=1

def arr_has(arr, value):
    for item in arr:
        if (item == value):
            return (True)
    return (False)


def item_left_of(value, arr, item):
    loc = 0
    for it in arr:
        if (it == item):
            break
        loc += 1
    i = 0
    while (i < loc):
        if (arr[i] == value):
            return (False)
        i += 1
    return (True)


def find_item_rules(rules, item):
    item_rules = {}
    i = 0
    for key, value in rules.items():
        if rules[key][0] == item :#or rules[key][1] == item:
            item_rules[i] = rules[key]
            i += 1
    return (item_rules)

def all_in_order(arr, rules):
    for item in arr:
        item_rules = find_item_rules(rules, item)
        for key, value in item_rules.items():
            if (arr_has(arr, value[1])):
                if not item_left_of(value[1], arr, item):
                    return (False)
    return (True)


total = 0

unordered = {}
i = 0

for key, value in manuals.items():
    if all_in_order(manuals[key], rules):
        n = len(value)
        total += value[n//2]
    else:
        unordered[i] = value
        i += 1

print("Part1 total:", total)

def find_loc(val, arr):
    i = 0
    for item in arr:
        if (item == val):
            return (i)
        i+=1

def order_list(arr, rules):
    while (not all_in_order(arr, rules)):
        for item in arr:
            item_rules = find_item_rules(rules, item)
            for key, value in item_rules.items():
                if (arr_has(arr, value[1])):
                    if not item_left_of(value[1], arr, item):
                        loc1 = find_loc(value[1],arr)
                        loc2 = find_loc(item,arr)
                        temp = arr[loc1]
                        arr[loc1] = arr[loc2]
                        arr[loc2] = temp
    return (arr)

total = 0

for key, value in unordered.items():
    ordered_val = order_list(value, rules)
    n = len(ordered_val)
    total += ordered_val[n//2]

print("Part2 total:", total)

et = time.time()
print('ex time: ', et-st, " s")