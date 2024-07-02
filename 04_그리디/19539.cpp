#include <iostream>
#include <vector>

using namespace std;

// 사과나무 1 ~ N: 초기높이 0
// 물뿌리개 1 -> 높이 1 / 2 -> 높이 2 -> 2개 동시 사용
// 하나를 3만큼 키우거나, 2개를 1, 2만큼 키우거나..
// 모든 수가 3의 배수면 ㅇㅋ


int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> cnt;
    for (int i = 0; i < n; i++){
        if (v[i] < 0){
            cnt.push_back(v[i]*-1);
            continue;
        }
        if (i == n-1){
            cnt.push_back(v[i]);
            break;
        }

        int now = v[i];
        int twice = 2 * now;
        
        v[i] -= now;
        v[i+1] -= twice;
    }
     
    int one = 0;
    int two = 0;

    for(int i = 0; i < cnt.size(); i++){
        if (v[i] % 3 == 1){
            one++;
        } else if (v[i] % 3 == 2){
            two++;
        } else {
            continue;
        }
    }
    if (one == two){
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}
