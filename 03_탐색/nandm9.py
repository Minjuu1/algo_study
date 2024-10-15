import sys
input = sys.stdin.readline


def dfs(depth):
	prev = 0
	if depth == m:
		print(' '.joint(map(str,arr)))
		return
	for i in range(n):
		if nums[i] != prev and visited[i] == False:
			arr.append(nums[i])
			prev = nums[i]
			visited[i] = True
			dfs(depth + 1)
			arr.pop()
			visited[i] = False
		
n, m = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
arr = []
start = 0
visited = [False] * n

dfs(0)