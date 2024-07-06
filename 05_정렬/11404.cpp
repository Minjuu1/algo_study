#include <stdio.h>
#include <iostream>
using namespace std;

// 플로이드 와샬 : 모든 노드에서 다른 모든 노드까지의 최단 경로 모두 계산 - 특정 노드 거쳐가는 경우 사용

// 점화식 = a-b최단 거리와 ak+kb거리 비교
int arr[105][105];

int main(){
    //도시, 버스 수
    int n, m;
    //노선
    int a, b, c;

    cin >> n; 
    cin >> m;

    // arr 초기화
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = 987654321;
        }
    }

    for (int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for (int i = 0; i < m; i++){
        cin >> a >> b >>c;
        // 노선이 하나가 아닐 수 있으니 넣기 전 비교해야함 (최소값 갱신)
        if (arr[a][b]>c){
            arr[a][b] = c;
        }
    }

    // DP 
    // i-j와 i-k+k-j 거리 비교
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j =1; j <= n; j++){
                if (arr[i][j]>arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }

        // 출력
        // arr 순회하면서 초가값이면 0, 아니면 값 출력
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (arr[i][j] == 987654321){
                    cout << "0 ";
                } else {
                    cout << arr[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}