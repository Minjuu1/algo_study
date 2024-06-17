#include <vector>
#include <iostream>

using namespace std;


// 신기한 소수
// 왼쪽부터 1, 2, 3, .. n자리 모두 소수
// 입력: N (자리수)
// 그래프  -> 0 - 0~9까지 연결 - 다시 0~9까지 연결.. 이걸 N번 반복
// 소수면 통과 / 소수 아니면 continue; 디음단계 진행 X < 가지치기
// ** 소수 조건도 중요: 1은 소수 아님 / 한 자릿수 소수: 2,3,5,7 / 2자리수 이상의 소수는 짝수를 끝자리로 가지지 않음

// ** 재귀함수 탈출 조건 설정하는게 아직 어려움 -> 자릿수로 비교하는 거 맞음!

// 전역 변수
int N;
vector<int> answer;

// 소수 판별 함수
bool isPrime(int n){
    // 원래 제곱근까지만 나눠보면 됨
    // 2로 나누기를 시작해야 함! 0을 습관처럼 집어넣으면 error -> 디버깅으로 찾음
    for (int i = 2; i <= n/2; i++){
        if (n % i == 0){ // i가 약수이므로 소수 아님
            return false;
        }
    }

    return true;
}

// DFS
void DFS(int num, int length){
    if (length == N){
        //자릿수 동일하면 num 그대로 저장
        if (isPrime(num)){
            answer.push_back(num);
        }
        return;
    }

    // graph를 정할 필요 없음 그냥 숫자를 줘도 무방 (홀수로 정해져있기 때문)
    for (int i = 1; i < 10; i++){
        if (i % 2 == 0) continue;
        if (isPrime(num * 10 + i)){
            DFS(num * 10 + i, length+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    // DFS 시작
    DFS(2, 1); //오름차순으로 정리하기 위한 순서
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    //출력
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << '\n';
    }

    return 0;
}