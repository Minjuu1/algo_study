#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    
    int N;
    string car;
    map<string, int> before;
    cin >> N;
    
    for (int i = 0; i < N; i++){
        cin >> car;
        before.insert(make_pair(car, i));
    }
    
    int cnt = 0;
    vector<int> after(N);
    
    for (int i = 0; i < N; i++){
        cin >> car;
        after[i] = before[car];
    }
    
    for (int i = 0; i < N-1; i++){
        for (int j = i+1; j < N; j++){
            if (after[i] > after[j]) { //after 인덱스가 큰 차(j) 중에 before 인덱스가 작은 (빨랐던) 차가 있는지 확인 )
                cnt++;
                break;
            }
        }
    }
    
    cout << cnt;
    return 0;
}