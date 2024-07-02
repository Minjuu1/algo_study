#include <iostream>
#include <vector>
using namespace std;
// 행성 1부터 n-1까지 돌고, 지구(0, n)에 돌아오는 것이 최적 비용
// 양의 정수 배로도 이동 가능 + 속도 유지 가능
// 입력: 행성 수 + 이동 속도 
// 출력: 지구에서 출발해야하는 속도의 최솟값을 구해야
// 900 800
// 0 300 1 400 2 500 3 400 4 300 5  
// 지구까지 돌아오려면 300 -> 400 -> 500-> 800 -> 900

int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    //거꾸로 입력받기
    for (int i = n-1; i >= 0; i--){
        cin >> v[i];
    }
    int min_v = 0;
    for (int curr: v){
        // 현재 속도가 크면 대체
        if (min_v < curr){
            min_v = curr;
        }
        // 현재 속도가 같거나 작으면, 200 / 300
        else{
            // 최소 속도-1 / 현재 속도 + 1-> 두 속도가 같을 때를 방지하기 위해  
            min_v = ((min_v-1)/curr + 1) * curr;
        }
    }

    cout << min_v;


}