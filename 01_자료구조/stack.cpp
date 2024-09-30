#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> stack;

    for(int i = 0; i < N; i++){
        string s;
        int n;
        cin >> s;
        if (s == "push"){
            cin >> n;
            stack.push_back(n);
        }
        else if (s == "pop"){
            if (!stack.empty()){    
                cout << stack.back() << '\n';
                stack.pop_back();
            } else {
                cout << -1 << '\n';
            }
        }
        else if (s == "size"){
            cout << stack.size() << '\n';
        }
        else if (s == "empty"){
            if (stack.empty()){
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        else {
            if (!stack.empty() && stack.back()){
                cout << stack.back() << '\n';
            } else {
                cout << "-1" << '\n';
            }
        }

    }


}