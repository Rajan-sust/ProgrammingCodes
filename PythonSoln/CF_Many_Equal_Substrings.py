n,k = map(int,input().split())
s = input()
mx = 0

for i in range(len(s)-1) :
    if s.endswith(s[0:i+1]):
        mx = i+1
        
print(s+(s[mx:])*(k-1))
