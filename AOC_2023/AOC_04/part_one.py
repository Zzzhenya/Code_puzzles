import math
import pandas as pd

with open('input.txt', 'r') as input_data:
    rows = [line.strip() for line in input_data.readlines()]

def get_dict(word, rows):
    d = {}
    i = 0
    for row in rows:
        if row == word:
            i += 1
            break
        i += 1
    j = 0
    for row in rows:
        if j >= i :
            if row == "":
                break
            d[i] = []
            d[i] = row.split(' ')
            d[i] = [int(i) for i in d[i]]
            i += 1
        j += 1
    return (d)

seedtosoil = get_dict("seed-to-soil map:", rows)

soiltofert = get_dict("soil-to-fertilizer map:", rows)

fertowater = get_dict("fertilizer-to-water map:", rows)

watertolite = get_dict("water-to-light map:", rows)

litetotemp = get_dict("light-to-temperature map:", rows)

temptohum = get_dict("temperature-to-humidity map:", rows)

humtoloc = get_dict("humidity-to-location map:", rows)
print(humtoloc)