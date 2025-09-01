
def bubble(arr, comp):
	size = len(arr)
	for i in range(size):
		# _sorted = True
		for j in range(size - i - 1):
			comp += 1
			if arr[j] > arr[j+1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
				_sorted = False
		# if _sorted:
		# 	break
	return (arr, comp)

def main():
	comp = 0
	arr = [1, 2, 3 ,4, 7]
	new_arr, comp = bubble(arr, comp)
	for x in new_arr:
		print(x)
	print("comp: " + str(comp))

if __name__ == "__main__":
	main()