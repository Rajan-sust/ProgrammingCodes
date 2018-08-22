import heapq as Q

R = lambda : map(int,input().split())
n,k = R()
p,c = R(),R()
sum = 0
ans,heap = [None]*n,[]
for _,coin,idx in sorted(zip(p,c,range(n))) :
    sum += coin
    ans[idx] = sum
    Q.heappush(heap,coin)
    if len(heap) > k :
        sum -= Q.heappop(heap)
print(*ans)
