#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n, key1, key2, m, x, y, answer;
vector<vector<int>> family;
vector<int> visited;

// 처음 접근 방식: dfs -> 부모/자식을 상관없이 방문하므로 쓸데없이 촌수를 늘려가는 상황 있었음
// 수정: bfs (k 기준으로 촌수를 정렬해서 visited에 방문횟수 늘려가며 저장)
void bfs(int k){
    
    queue<int> q;
    q.push(k);

    while(!q.empty()){
        
        int now = q.front();
        q.pop();
        
        for(int next: family[now]){
            if (!visited[next]){
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
        
    }
    

    return;
}

int main(){
    
    cin >> n;
    family.resize(n+1);
    visited = vector<int> (n+1, 0);
    
    cin >> key1 >> key2;
    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }
    
    bfs(key1);
    
    if (visited[key2]){
        cout << visited[key2];
    } else {
        cout << -1;
    }


    return 0;
}