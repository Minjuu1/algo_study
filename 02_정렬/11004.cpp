#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// sort - O(NlogN)
// 퀵정렬 구현용

// pivot 정하는 방법 (제1목표: k번째 수를 찾는 것)
// k랑 같다면 -> 알고리즘 종료
// k가 더 작다면 -> 왼쪽 부분만 정렬
// k가 더 크다면 -> 오른쪽 부분
void swap(vector<int>& A, int S, int E){
    int tmp = A[S];
    A[S] = A[E];
    A[E] = tmp;
}

int partition(vector<int>& nums, int S, int E){
    if (S + 1 == E){
        //quick sort 할 필요 없는 개수 - 그냥 바로 swap
        if (nums[S]> nums[E]){
            swap(nums, S, E);
            // E가 j 역할 함
            return E;
        }                
    }
    
    //중간값 지정
    int M = (S+E)/2;
    //중간값을 맨 처음으로
    swap(nums, S, M);
    
    int pivot = nums[S];
    int left = S + 1;
    int right = E;
    
    while(left <= right){
        while(pivot < nums[right] && right > 0){
            right--;
        }
        while(pivot > nums[left] && left < nums.size() - 1){
            left++;
        }
        if (left <= right){
            swap(nums, left++, right--);
        }
        
        //right가 pivot의 위치를 나타냄
        nums[S] = nums[right];
        nums[right] = pivot;
        return right;
    }
}
void quickSort(vector<int>& nums, int S, int E, int K){
    int pivot = partition(nums, S, E);
    if (pivot == K){
        return;
    }else if (pivot > K){
        //왼쪽만 보면 됨
        quickSort(nums, S, pivot-1, K);
    }else{
        //오른쪽만 보기
        quickSort(nums, pivot+1, E, K);
    }
    
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> nums;
    int N, K, n;
    
    cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> n;
        nums.push_back(n);
    }
    
    quickSort(nums, 0, N-1, K-1);
    
    cout  << nums[K-1];
    return 0;
}