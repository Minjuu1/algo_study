#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


typedef pair<int, int> edge; // 노드번호, 가중치(거리)
vector< vector <edge> > graph;
vector <bool> visited;
vector <int> dist;

void bfs(int node){
    
    queue<int> q;
    
    // 일단 시작노드 push + 방문 체크
    q.push(node);
    visited[node] = true;
    
    // 큐 빌 때까지 반복
    while (!q.empty()){
        int curr_node = q.front();
        q.pop();
        
        // 연결된 노드 push 
        for (edge i : graph[curr_node]){
            // 아직 방문 안했다면 push!
            if (visited[i.first] == false){
                q.push(i.first);
                visited[i.first] = true;
                
                //거리 배열 업데이트 (현재까지의 거리 + 연결 노드 거리)
                dist[i.first] = dist[curr_node] + i.second;
            }
        }
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V;
    cin >> V;
    
    graph.resize(V+1);
    
    for (int i = 0; i < V; i++){
        // 어차피 공백이고 각자 다른 변수에 담기므로 cin 가능
        // getline: 줄바꿈 기준으로 하나의 변수로 받는 것
        int S;
        cin >> S;
        while(true){
            int N, D;
            cin >> N;
            if (N == -1){
                break;
            }
            cin >> D;
            // 양방향 그래프지만 입력 조건 상 계속 반복되기 때문에 2번 push 필요 X
            graph[S].push_back(edge(N, D));
        }
    }
    
    dist = vector<int> (V+1, 0);
    visited = vector<bool>(V+1, false);
    
    
    bfs(1); // 거리 배열 정렬 완 (임의의 시작점 노드)
    
    int max_node = 1; //시작점 노드가 최대 거리노드라고 가정 
    
    for (int i = 2; i <= V; i++){
        if (dist[max_node] < dist[i]){
            max_node = i;
        }
    }
    
    // 거리배열, 방문배열 초기화
    fill(dist.begin(), dist.end(), 0);
    fill(visited.begin(), visited.end(), false);
    
    // 최대 거리 노드로 다시 거리배열 계산
    bfs(max_node);
    
    // 지름을 구하기 위해 sort
    sort(dist.begin(), dist.end());
    cout << dist[V];
    
    
    return 0;
}