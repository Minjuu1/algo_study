
 //누적합 배열 기준으로 투포인터 알고리즘 사용
    // 0 1 3 6 10 15 tot[big]-tot[small]
    // [0,0] 1 -> tot[1]-tot[0];
    // [3,4] -> tot[5] - tot[3];
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    
    //누적합 만들기
    int tot[1000001];
    tot[0] = 0;
    for (int i = 0; i < sequence.size(); i++){
        tot[i+1] = tot[i] + sequence[i];
    }
    
    
    int big = 1; int small = 0;
    //놓침 -> sequece의 길이는 1000000보다 같거나 작다
    int min_length = 1000001;
    
    //big이 sequece 최대보다 하나만 더 커져도(0이 됨)-> seq_sum이 음수가 됨
    while((small <= big) && big <= sequence.size()){
        
        int seq_sum = tot[big] - tot[small];
        if (seq_sum == k){
            //길이 짧은 게 우선
            int now_length = big - small;
            if (now_length < min_length){
                //저장
                answer[0] = small;
                answer[1] = big - 1;
                
                //최솟값 갱신
                min_length = now_length;
            }
        }
        
        if (seq_sum < k){
            big += 1;
        } else {
            small += 1;
        }
    
    }
    return answer;
}
    
        