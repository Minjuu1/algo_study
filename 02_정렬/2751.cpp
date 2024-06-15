#include <iostream>
#include <vector>

using namespace std;

// new learn: 배열 선언하는 방법!
int* A;
int* sorted;

// 음수, 양수 둘 다 나옴
// 머지 정렬 연습
void merge(int left, int mid, int right){
    int i = left; // 왼쪽 부분 포인터
    int j = mid+1; // 오른쪽 부분 포인터
    int k = left; // 원소 삽입 부분
    
    
    while(i <= mid && j <= right){
        if (A[i] <= A[j]){
            sorted[k] = A[i];
            i++;
        }
        else {
            sorted[k] = A[j];
            j++;
        }
        
        k++;
    }
    
    if (i > mid){
        for (int p = j; p <= right; p++){
            sorted[k] = A[p];
            // k는 수동으로 증가시켜야함
            k++;
        }
    } else {
        for (int p = i; p <= mid; p++){
            sorted[k] = A[p];
            k++;
        }
    }
    
    // 정렬 후 결과를 원래 배열에 넣어야 함 ** (다음 단계를 위해)
    for (int p = left; p <= right; p++){
        A[p] = sorted[p];
    }
}

void mergeSort(int left, int right){
    if (left < right){
        // 분할
        int mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        
        // 병합
        merge(left, mid, right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    A = new int[N];
    sorted = new int[N];
    
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    mergeSort(0, N-1);
    
    for (int i = 0; i < N; i++){
        cout << A[i] << '\n';
    }
    
    return 0;
}