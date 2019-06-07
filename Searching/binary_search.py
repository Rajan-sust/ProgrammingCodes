def binary_search(array,num):
	l = 0
	r = len(array) - 1
	while l <= r:
		mid = l + (r-l)//2
		if array[mid] == num:
			return mid
		elif array[mid] < num:
			l = mid + 1
		else:
			r = mid - 1
	return -1

def main():
	array = [2,3,5,12,34,567,1000,2345]
	print(binary_search(array,3))
	

if __name__ == '__main__':
	main()