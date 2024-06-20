/******************************************************************************

나무 N개, 필요한 나무: M미터
절단기: H 높이 (H >= 0) - 최대값 구해야 함 (적어도 M미터의 나무를 구할 수 있는..)

만약 h를 점점 늘려가야하나? - 높이가 10억이라 ..

10으로 해보면 h

tree1 - h + tree2 -h ---
10+5+7 = 22 7 넘음..너무 많다! -> h 늘려도 됨
근데 16이면,, 4+1 = 5..
나무를 정렬한 다음에 - H

이분탐색이라는데 어떻게 ?
N이 백만 -> 일단 다 m으로 빼기?
13 8 3 10 - h 후보들 -> 일단 제일 큰거 13.. 큰 것만 쓸 거면 최대값- m을 최소값으로  - 최대값으로는? 제일 큰거?
0 22 20 6 26 - 26... 늘려,,, (최소값인듯) -> 제일 큰,, 건,,
*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
vector<long long> tree;

long long binary(int start, long long end, long long target){
    long long sum = 0;
    long long mid;
    while (start <= end){
       
        sum = 0;
        mid = (start + end) / 2;
       
        // 들고 갈 나무 길이 계산
        for (int i = 0; i < tree.size(); i++){
            if (tree[i] < mid){
                continue;
            }
            sum += tree[i] - mid;
        }
       
        // 나무들이 TARGET보다 모자라면 H 줄이기기
        if(sum < target){
            end = mid - 1;
        }
        // 넘치면 h 늘이기
        if(sum > target){
            start = mid + 1;
        }
        if (sum == target){
            return mid;
        }
       
    }
   
    // 뭐가 정답이 되는지 잘 판단해야함
    // 반례를 스스로 찾아보기기
    return end;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int N;
    long long M;
    // 나무의 수, target 길이인 M
    cin >> N >> M;
   
    long long l, max_l;
    max_l = 0;
   
    for(int i = 0; i < N; i++){
        cin >> l;
        tree.push_back(l);
        if (l > max_l){
            max_l = l;
        }
    }
   
    cout << binary(0, max_l, M);
   
   

    return 0;
}