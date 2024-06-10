#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;

    queue<int> q;

    for (int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;

        if (cmd == "push"){
            int X;
            cin >> X;
            q.push(X);
        }

        if (cmd == "pop"){
            if (q.size()!= 0){
                cout << q.front() << '\n';
                q.pop();
            } else {
                cout << -1 << '\n';
            }
        }

        if (cmd == "size"){
            cout << q.size() << '\n';
        }

        if (cmd == "empty"){
            if(q.size() == 0){
                cout << 1 << '\n';
            } else{
                cout << 0 << '\n';
            }
        }

        if (cmd == "front"){
            if (q.size()!= 0){
                cout << q.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }

        if (cmd == "back"){
            if (q.size()!= 0){
                cout << q.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}