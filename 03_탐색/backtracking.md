# 백트래킹

## 정의
- 트리 구조를 기반으로 DFS 깊이 탐색을 진행하며 조건을 체크한다
- 조건에 맞지 않는 노드는 깊이탐색 진행하지 않고 가지치기를 한다(Pruning)

## 특징
- 해가 아닌 선택지는 없애기 때문에 **시간 복잡도**를 줄일 수 있다
- **DFS**로 구현하는 것이 편리


## 구현
- 중복 방지를 위해 visited list 만들기
- 입력 인수: depth - answer 배열에 들어온 숫자의 개수
- (조건) 찾고자 하는 해와 같다면 탈출
- 

```Python
def DFS(depth, n, m):
	if depth == m:
        return

    for i in range(1, n+1):
        if not visited[i]:
            visited[i] = True
            answer.append(i)
            DFS(depth+1, n, m)
            #깊이 탐색을 진행했다는 의미
            
            visited[i] = False 
            #방문 처리 철회해주어야 함
            answer.pop()
            #원래 자리로 돌아가서 탐색하기 위함

```