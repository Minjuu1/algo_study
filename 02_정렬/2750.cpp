#include <iostream>
#include <vector>


using namespace std;

// 데이터 크기: 절대값이 1000보다 작거나 같은 정수 -> 음수도 포함!
// sort - 됨
// merge sort

// 정렬하고 병합하는 Merge
void merge(vector<int>& A, int left, int mid, int right){
    int i = left; // 왼쪽부분 포인터
    int j = mid + 1; // 오른쪽 부분 포인터
    int k = left; // 원소 넣을 위치
    
    vector<int> sorted(A.size());
    
    // 왼쪽 & 오른쪽 하나씩 차례로 비교
    while(i <= mid && j <= right){
        if (A[i] <= A[j]){
            sorted[k] = A[i];
            i++;
        }
        else {
            sorted[k] = A[j];
            j++;
        }
        //정렬 후 벡터 인덱스 옮김
        k++;
    }
    
    // 위의 과정이 끝나면 i = mid+1 or j = right+1이 됨 (while 탈출조건)
    if (i > mid){ // 왼쪽부분이 모두 정렬됨 -> 오른쪽 남은 부분 저장해야함
        for (int p = j; p <= right; p++){
            sorted[k] = A[p];
            k++;
        }
    } else {
        for (int p = i; p <= mid; p++){
            sorted[k] = A[p];
            k++;
        }
    }
    
    // 정렬해서 저장한 벡터(sorted)를 원래 벡터에 넣기
    for (int p = left; p <= right; p++){
        A[p] = sorted[p];
    }
}

// 메인 Merge Sort
void mergeSort(vector<int>& A, int left, int right){
    if (left < right){
        //분할
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        
        //정렬 후 병합
        merge(A, left, mid, right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, n;
    vector<int> A;
    
    //입력
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> n;
        A.push_back(n);
    }
    
    //연산 - 병합정렬 연습!
    // 1. Divide = n개를 n/2개의 배열로 나눔
    // 2. Conquer = 각각의 배열 정렬
    // 3. Combine = 각각 배열을 병합함
    mergeSort(A, 0, N-1);
    
    //출력
    for (int i = 0; i < N; i++){
        cout << A[i] << '\n';
    }
    
    return 0;
}