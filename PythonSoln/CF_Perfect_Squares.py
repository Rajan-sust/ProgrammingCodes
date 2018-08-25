R = lambda : map(int,input().split())
input()
print(max(set(R())-set(x*x for x in range(1001))))
