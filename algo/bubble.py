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

def bubble(arr, comp, size):
	for i in range(size):
		_sorted = True
		for j in range(size - i - 1):
			# print(arr)
		# for j in range(size - 1):
			comp += 1
			if arr[j] > arr[j+1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
				_sorted = False
		if _sorted:
			break
	return (arr, comp)

def main():
	comp = 0
	arr = []
	for i in sys.argv:
		if i != sys.argv[0]:
			arr.append(int(i))
	
	arr, comp = bubble(arr, comp, len(arr))
	
	print(arr)
	print("comp: " + str(comp))

if __name__ == "__main__":
	main()