#ref: https://realpython.com/sorting-algorithms-python/#the-bubble-sort-algorithm-in-python
#ref: https://en.wikipedia.org/wiki/Bubble_sort

counter = 0
'''
procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        swapped := false
        for i := 1 to n-1 inclusive do
            { if this pair is out of order }
            if A[i-1] > A[i] then
                { swap them and remember something changed }
                swap(A[i-1], A[i])
                swapped := true
            end if
        end for
    until not swapped
end procedure
'''
import sys

def sorted(arr, comp, size):
	global counter
	for i in range(1, size - 1):
		comp+=1
		counter+=1
		if (arr[i - 1] > arr[i]):
			return (False)
	return (True)

def bubble(arr, comp, size):
	global counter
	# for i in range(size):
	# 	_sorted = True
	# 	for j in range(size - i - 1):
	# 	# for j in range(size - 1):
	# 		comp += 1
	# 		if arr[j] > arr[j+1]:
	# 			arr[j], arr[j + 1] = arr[j + 1], arr[j]
	# 			_sorted = False
	# 	if _sorted:
	# 		break
	# return (arr, comp)
	while sorted(arr, comp, size) == False:
		swapped = False
		for i in range(1, size - 1):
			comp+=1
			counter += 1
			if (arr[i-1] > arr[i]):
				arr[i], arr[i - 1] = arr[i - 1], arr[i]
				swapped = True
		# size = size - 1
	return (arr, comp)

def main():
	global counter
	comp = 0
	arr = []
	for i in sys.argv:
		if i != sys.argv[0]:
			arr.append(int(i))
	# arr = [1, 2, 3 ,4, 7]
	new_arr, comp = bubble(arr, comp, len(arr))
	for x in new_arr:
		print(x)
	print("comp: " + str(comp))
	print("counter: " + str(counter))

if __name__ == "__main__":
	main()