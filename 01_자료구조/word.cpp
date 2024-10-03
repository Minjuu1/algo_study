#include <iostream>
#include <stack>

using namespace std;

int main(){

    int n;
    string sen;
    stack <char> st;
    cin >> n;

    // 버퍼 초기화
    cin.ignore();

    while(n--){
        getline(cin, sen);
        // 끝을 표기해야 함
        sen += ' ';

        for (int i = 0; i < sen.size(); i++){
            if (sen[i] == ' '){
                while (!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else {
                st.push(sen[i]);
            }
        }
        cout << "\n";
    }
}