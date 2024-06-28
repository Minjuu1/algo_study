#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 팰린드롬
// 홀수인건 하나만 있어야함
// 알파벳별로 개수 체크해서 alpha[26]에 집어넣기
// even/odd에 집어넣다가 odd가 1이상되면 break -> I'm sorry
// odd가 0개거나 1개면 이제 출력 even 사전순으로..

int main(){

    string input;
    cin >> input;

    int alpha[26] = {0, };
    for (int i = 0; i < input.size(); i++){
        alpha[input[i]-'A']++;
    }

    // 홀수개인 알파벳이 2개 이상 있으면 안됨
    int odd_cnt = 0; int odd = 27;
    vector<int> even;
    for(int i = 0; i < 26; i++){
        // 홀수
        if (alpha[i] % 2 != 0){
            odd_cnt++;
            if(odd_cnt > 1){
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            // 첫번째 홀수라면
            odd = i;
            // 1개 이상있다면 짝수부분에서도 출력 필요
            if(alpha[i] > 1){
                even.push_back(i);
            }
            alpha[i]--;
        } else {
            even.push_back(i);
        }
    }

    //출력
    vector<char> answer;
    for (int i : even){
        for (int j = 0; j < alpha[i]/2; j++){
            answer.push_back(i+'A');
        }
    }

    for (int i = 0; i < answer.size(); i++){
        cout << answer[i];
    }
    if (odd_cnt == 1){
        cout << odd +'A';
    }
    for (int i = answer.size()-1; i >= 0; i--){
        cout << answer[i];
    }
    return 0;
}