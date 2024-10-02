#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string s;
    int n;

    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> s;
        stack<char> st;

        for (int j = 0; j<s.size(); j++){
            char check = s[j];
            if (check == '('){
                st.push(check);
            }
            else if (check == ')' && !st.empty()){
                if (st.top() == '('){
                    st.pop();
                }
            }
            // No 출력 위해 조건 충족 안하면 stack에 추가 
            else {st.push(check);}
        }

        if (st.empty()){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        
        
    }
    

}