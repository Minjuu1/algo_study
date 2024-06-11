#include <iostream>
#include <stack>
#include <string>

using namespace std;

//스택에 (, [ - push
// ) -> top이 (라면 pop, else: break -> print no
// ] -> top이 [라면 pop, else: break
// stack이 비었다면 yes, 아니면 no

bool isBalanced(string input){
    
    stack<char> s;

    for(int i = 0; i < input.length(); i++){
        char c = input[i];

        switch(c){
            case '[':
                s.push(c);
                break;
            case '(':
                s.push(c);
                break;
                
            case ']':
                if (s.empty() || s.top() != '['){
                    return false;
                }
                s.pop();
                break;
            case ')':
                if (s.empty() || s.top() != '('){
                    return false;
                }
                s.pop();
                break;
        }
        
    }
        
    //비어있다면 true! -> 균형잡힘; 아니라면 false
    return s.empty();
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;


    while (true){
        //공백 포함한 문자열 받기 위한 함수, 줄바꿈 기준으로 나눔
        getline(cin, input);
        
        
        //입력 종료 조건
        if (input == "."){
            break;
        }
        
        if (isBalanced(input)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    
    return 0;
}