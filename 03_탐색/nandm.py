import sys
input = sys.stdin.readline


def dfs(depth):
	if depth == m:
		print(' '.joint(map(str,arr)))
		return
	for i in range(1, n+1):
		arr[depth] = i
		dfs(depth + 1)
		
n, m = map(int, input().split())
arr = [0 for _ in range(m)]

dfs(0)