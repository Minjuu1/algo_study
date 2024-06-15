#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    map<string, int> names;
    map<int, string> nums;
    int N, M;
    string name, q;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> name;
        names.insert(make_pair(name, i));
        nums.insert(make_pair(i, name));
    }

    for (int i = 0; i < M; i++){
        cin >> q;
        
        if (q[0] >= '0' && q[0] <= '9'){
            int key = stoi(q) - 1;
            cout << nums[key] << '\n';
        } else {
            cout << names[q] + 1 << '\n';
        }
    }
    
    
    return 0;
}