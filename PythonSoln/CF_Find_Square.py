r,c = map(int,input().split())
grid = [input() for _ in range(r)]
pos = [(x+1,y+1) for x in range(r) for y in range(c) if 'B'==grid[x][y]]
print("%d %d" % pos[len(pos)//2])




