def drop_max(lst):
    _max = lst[-1]
    while len(lst) >= 1 and lst[-1] == _max:
        lst.pop()
    return lst

def get_runnerup(lst):
    return (lst[-1])

if __name__ == '__main__':
    arr = map(int, input().split())
    lst = list(arr)
    if (len(lst) > 0):
    	lst.sort()
    	lst = drop_max(lst)
    if (len(lst) > 0):
    	print(get_runnerup(lst))
    else:
    	print('no runner-up')
    	