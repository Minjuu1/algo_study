#include <iostream>

using namespace std;

// 개수: 천만
// 최대 크기의 수가 작음 (10000): 자리수 총 다섯 자리수
// 기수 정렬 or 계수정렬 쓸 수 있음
// 계수정렬 제약조건 : 데이터가 양수(자연수), 각 데이터 크기가 작아야함
// 데이터 크기: s  -> s+1 크기의 배열 cnt 생성 -> 이후 수의 값을 인덱스값으로 치환해서 증가시킴
// ex) 100이 나왔으면 cnt[100]에 ++;
// 출력: cnt를 for문 돌면서 출력 (데이터 값이 3이면 3번 출력)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, n;
    //상수 만들기!
    const int SIZE = 10000;
    
    // 배열 초기화 ****
    int cnt[SIZE+1] = {0};
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> n;
        cnt[n]++;
    }
    
    for (int i = 0; i < SIZE+1; i++){
        if (cnt[i]){
            for (int j = 0; j < cnt[i]; j++){
                cout << i << '\n';
            }
        }
    }
    
    
    return 0;
}