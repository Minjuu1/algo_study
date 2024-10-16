n, s = map(int, input().split())
nums = list(map(int,input().split()))
cnt = 0
ans = []

def dfs(idx):
    global cnt 

    if sum(ans) == s and len(ans) > 0:
        cnt += 1

    for i in range(idx, n):
        ans.append(nums[i])
        dfs(idx+1)
        ans.pop()


dfs(0)
print(cnt)