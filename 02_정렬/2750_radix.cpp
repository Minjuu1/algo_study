#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 데이터 크기: 절대값이 1000보다 작거나 같은 정수 -> 음수도 포함!
// radix sort
void radixSort(vector<int>& arr){
    //큐 10개 만들기
    queue<int> q[10];

    // //최대 자릿수 알아내는 while문
    // while (1){
    //     //최댓값보다 커졌을 때 탈출
    //     if (radix >= max_value) break;
    //     radix= radix*10;
    // }
    
    
    for(int i = 1; i < 10001; i= i*10) {// 1의 자릿수부터 10씩 곱하면서 반복
        for(int j = 0; j < arr.size(); j++){
            int k;
            // 현재 자릿수보다 작으면 0
            if (arr[j] < i) {
                k = 0;
            } else {
                k = (arr[j]/i) % 10; // 그냥 나누면 안나옴 자릿수로 나눈 뒤 나머지
            }
            
            // k번째 배열에 값 저장
            q[k].push(arr[j]);
        }
        
        int idx = 0;
        // 순차적으로 값 빼면서 정렬
        for (int j = 0; j < 10; j++){
            while (q[j].empty() == 0){
                arr[idx] = q[j].front();
                q[j].pop();
                idx++;
            }
        }    
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, n, max_value;
    vector<int> pos;
    vector<int> neg;
    
    //입력
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> n;
        if (n >= 0){
            pos.push_back(n);
        } else {
            neg.push_back(n*-1);
        }
        
    }

    //연산 - 기수 정렬 연습
    radixSort(pos);
    radixSort(neg);
    
    //출력
    for (int i = neg.size()-1; i >= 0; i--){
        cout << neg[i] * -1 << '\n';
    }
    for (int i = 0; i < pos.size(); i++){
        cout << pos[i] << '\n';
    }
    
    return 0;
}