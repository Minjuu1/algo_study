#include <iostream>
#include <queue>
using namespace std;


//요세푸스 문제 -> N명이 원을 이루며 앉아있음
//원으로 앉아있고, 제거되고 계속 앞으로 밀어나는 그림 상상
//K번째 사람 제거하기
// 4 5 6 7 1 2 
//k번째 사람을 앞에 계속 놓고, 나머지는 뒤로 옮기면 큐로 구현 가능 

int main(){
    int N, K;
    cin >> N >> K;
    
    queue<int> seat;
    
    //둥글게 앉기
    for (int i = 1; i <= N; i++){
        seat.push(i);
    }
    
    //지워나가기
    vector<int> result;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < K - 1; j++){
            seat.push(seat.front());
            seat.pop();
        }
        result.push_back(seat.front());
        seat.pop();
    }
    
    
    //출력
    cout << '<' << result[0];
    for(int i = 1; i < N; i++){
        cout << ", " << result[i];
    }
    cout << '>';
    
    return 0;
}