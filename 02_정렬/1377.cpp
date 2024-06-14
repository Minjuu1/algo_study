#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// n의 크기: 500000 -> O(N^2) 안됨
// O(NlogN)
// 스왑이 한번도 일어나지 않는 루프가 언제인지 알아내는 문제
// 버블정렬: 숫자는 항상 최대 1만 움직일 수 있다
// 아이디어: idx 비교
// sort 함수로 정렬한 뒤의 인덱스와의 차이
// (정렬 전 - 정렬 후 = 왼쪽으로 얼마나 움직였나? ) => swap이 일어난 횟수와도 같음

// void bubble(int A[], int N){
    
//     for (int i = 1; i <= N+1; i++){
//         // 조기종료 잡아내기 위한 flag
//         bool flag = false;
        
//         // 뒤에서부터 픽스 됨 (j <= N-i)
//         for (int j = 1; j <= N-i; j++){
//           // 앞이 더 크면 스왑 -> 오름차순 정렬
//           if (A[j] > A[j+1]){
//             flag = true;
//             swap(A[j], A[j+1]);
//           }
//         }
        
//         //스왑이 한번도 안 일어났다면 정렬 끝난 것 -> 조기 종료
//         if (!flag){
//             cout << i << '\n';
//             break;
//         }
//     }
    
    
// }
int bubble(vector<pair<int, int>> A, int N){
    //정렬 - first 값 기준으로 정렬됨
    sort(A.begin(), A.end());
    
    int MAX = 0;
    //i = 정렬 후 인덱스, A.second = 정렬 전 인덱스
    for(int i = 0; i < N; i++){
        //최대의 차이를 구하는 것
        if (MAX < A[i].second - i ){
            MAX = A[i].second - i;
        }
    }
    
    return (MAX + 1);
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> A(N);
    
    for (int i = 0; i < N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    
    cout << bubble(A, N);
    
    return 0;
}
