# DFS (Depth-First Search)

## 정의
- 깊이 우선 탐색
- 한 노드에서 시작하여 인접한 노드 탐색 -> 더이상 방문할 노드가 없을 때까지 탐색 -> 이전 노드로 되돌아와서 다른 경로 탐색

## 특징
- 스택 구조 활용 or 재귀 호출
- 경로 탐색에 유리 -> 목표 노드까지의 경로 찾는 문제
- 검색 시간 느림
- **완전 탐색 문제** or **백트래킹**에 적합

## 구현
- 시작 노드를 스택에 삽입
- 방문하지 않은 노드 있으면 스택에 넣고 방문 처리
- 없으면 최상단 노드 꺼내기

```Python
def DFS(g,v,visited):
	visited[v] = True
	print(v,end =' ')
	for i in g[v]:
		if not visited[i]:
			dfs(g,i,visited)
```

# BFS (Breadth-First Search)

## 정의
- 너비 우선 탐색
- 인접한 노드를 먼저 탐색한 후 -> 다음 child node로 넘어가 깊이를 탐색

## 특징
- 큐 구조 활용
- **최단 경로 탐색**에 유리 (모든 노드를 동일한 깊이로 탐색하므로 목표 노드 도달의 최소 경로를 보장한다)
- 레벨별로 탐색이 필요한 경우에 적합

## 구현
- 시작노드를 큐에 삽입
- 노드를 꺼내 인접 노드 중 방문하지 않은 노드를 큐에 삽입 + 방문처리
- 반복

```Python
from collections import deque

def bfs(g,start,visited):
	queue = deque([start])
	visited[start] = True

	while queue:
		v = queue.popleft()
		print(v,end=' ')
		for i in graph[v]:
			if not visited[i]:
				queue.append(i)
				visitied[i] = True
```