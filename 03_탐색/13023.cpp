#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 2001;
const int M_MAX = 2001;

// 인접리스트 형식 그래프
vector<vector<int>> graph;
// 방문 배열
vector<bool> visited;

// 조건 만족 함수
bool is_possible = false;

void dfs(int now, int depth){
    if (depth == 5 || is_possible == true){
        is_possible = true;
        return;
    }
    
    visited[now] = true;
    
    for (int i : graph[now]){
        if (!visited[i]){
            dfs(i, depth+1);
        }
    }
    
    // 만약 없다면
    // 다음 방문에 영향 주지 않도록
    visited[now] = false;
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    graph.resize(N);
    visited = vector<bool> (N, false);
    
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        
        // 양방향이므로 2번
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < N; i++){
        // 모든 노드에 dfs 하면서 4번 이어진게 있는지 체크
        dfs(i, 1);
        
        if (is_possible){
            break;
        }
    }
    
    if (is_possible){
        cout << 1;
    } else {
        cout << 0;
    }
    
    
    return 0;
}