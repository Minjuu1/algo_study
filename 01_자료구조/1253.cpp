#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// N의 개수: 2000개 ->  n^2보다 작아야함 /  좋은 수 판단 + N개 반복 -> n^2은 안됨(n^3이 됨) -> nlogn
// 정렬(nlogn), 투포인터(n) 알고리즘 
// 힌트: 두 수의 합! 
// 자기 자신을 포함하면 안됨 (예외 처리) ** 어려움 -> 

//알고리즘:
// 1. 정렬 먼저
// 2. 투포인터 양쪽 끝에 -> 탐색 시작
// 투포인터 원칙: left + right > K : right--
// ==K: cnt++
// left<= right까지 못찾으면 좋은 수 아님

int findGoodNum(vector<int> nums){
    int cnt, left, right, curr;
    cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        left = 0;
        right = nums.size()-1;
        // 자료형!
        long K = nums[i];
        while (left < right){
            
            curr = nums[left]+nums[right];
            
            if (curr == K){
                // 예외 처리를 정답처리 하기 직전에!
                if (left != i&& right != i){
                    cnt++;
                    break;
                } else if(left == i) {
                    left++;
                } else if(right == i){
                    right--;
                }
            }
            if (curr < K){
                left++;
            }
            if (curr > K){
                right--;
            }
        }
    }
    
    return cnt;
}
int main(){
    int N, n;
    cin >> N;

    vector<int> nums;
    for (int i = 0; i < N; i++){
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    cout << findGoodNum(nums);


    return 0;
}