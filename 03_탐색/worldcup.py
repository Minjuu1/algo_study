import sys
from itertools import combinations

def back_tracking(round):
    global ans
    if round==15:
        ans=1
        for i in res:
            if i.count(0)!=3:
                ans=0
                break
        return
    t1,t2=play[round]
    for x,y in ((0,2),(1,1),(2,0)):
        if res[t1][x]>0 and res[t2][y]>0:
            res[t1][x]-=1
            res[t2][y]-=1
            back_tracking(round+1)
            res[t1][x]+=1
            res[t2][y]+=1

result=[]
play=list(combinations(range(6),2))
for _ in range(4):
    tmp=list(map(int,sys.stdin.readline().split()))
    res=[tmp[i:i+3] for i in range(0,16,3)]
    ans=0
    back_tracking(0)
    result.append(ans)

print(*result)