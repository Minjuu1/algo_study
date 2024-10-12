from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())
arr = [list(str(sys.stdin.readline().strip())) for _ in range(N)]
visited = [[False for _ in range(M)] for i in range(N)]
distance = [[1 for _ in range(M)] for i in range(N)]

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs():
    q = deque()
    q.append((0, 0))
    while q:
        x, y  = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if visited[nx][ny] == False and arr[nx][ny] == '1':
                q.append((nx, ny))
                visited[nx][ny] = True
                distance[nx][ny] += distance[x][y]

bfs()
print(distance[N-1][M-1])