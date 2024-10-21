N = int(input())
BOJ_avenue = input().rstrip()

dp = [float('inf')]*N
dp[0] = 0
for i in range(1,N):
    for j in range(i):
        if BOJ_avenue[j]=='B' and BOJ_avenue[i]=='O':
            dp[i] = min(dp[i],dp[j]+ pow(i-j,2))
        elif BOJ_avenue[j]=='O' and BOJ_avenue[i]=="J":
            dp[i] = min(dp[i],dp[j]+ pow(i-j,2))
        elif BOJ_avenue[j]=='J' and BOJ_avenue[i]=='B':
            dp[i] = min(dp[i],dp[j]+ pow(i-j,2))

if dp[N-1] != float('inf'):
    print(dp[N-1])
else:
    print(-1)