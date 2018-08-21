import bisect
array = [1,2]
for i in range(2,500) :
    array.append(array[i-1]+array[i-2])

while True :
    a,b = map(int,input().split())
    if a==0 and b==0 :
        break
    ans = bisect.bisect_right(array,b) - bisect.bisect_left(array,a)
    print(ans)
