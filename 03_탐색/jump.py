n = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dp = [[0]*N for _ in range(N)]

dp[0][0] = 1
for i in range(N):
    for j in range(N):
        for k in range(1, i+1):
            if board[i-k][j] == k:
                dp[i][j] += dp[i-k][j]
        for k in range(1, j+1):
            if board[i][j-k] == k:
                dp[i][j] += dp[i][j-k]

print(dp[n-1][n-1])