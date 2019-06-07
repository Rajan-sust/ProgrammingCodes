"""
First elememt greater than or equal to x.
Return : Index. If not found, return -1.
"""

def binary_search(array,num):
	l = 0
	r = len(array) - 1
	ans = -1
	while l <= r:
		mid = l + (r-l)//2
		if array[mid] >= num:
			ans = mid
			r = mid - 1
		else:
			l = mid + 1
	return ans

def main():
	array = [2,3,5,12,34,567,1000,2345]
	x = int(input('Enter any number:'))
	print(binary_search(array,x))
	

if __name__ == '__main__':
	main()