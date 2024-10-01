#include <iostream>
#include <queue>
using namespace std;


//요세푸스 문제 -> N명이 원을 이루며 앉아있음
//K번째 사람 제거하기
// 4 5 6 7 1 2 
// k번째 사람을 앞에 계속 놓고, 나머지는 뒤로 옮기면 

int main(){
    int N, K;
    cin >> N >> K;
    
    //큐 활용
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
    cout << '<';
    for(int i = 0; i < N; i++){
        if(i != N-1){
            cout << result[i] << ", ";
        }else{
            cout << result[i];
        }
    }
    cout << '>';
    
    return 0;
}