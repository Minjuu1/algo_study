import sys
from collections import deque

def bfs(x):
	q = deque()
	q.append(x)
	
	while q:
		pos = q.popleft()
		direct[2] = pos
		
		if(pos == k):
			return visit[pos]
		for i in range(3):
			new_pos = pos + direct[i]
			if (0<=new_pos<=limit*2 and visit[new_pos]==0):
				q.append(new_pos)
				visit[new_pos] = visit[pos] + 1
				
	input = sys.stdin.readline
	n,k = map(int, input().split())
	direct = [-1, 1, 0]
	 
	limit = max(n, k)
	visit = [0 for i in range(2*limit+1)]
	 
	print(bfs(n))