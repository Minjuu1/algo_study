# Stack / Queue

## Stack
- LIFO (Last In First Out) 방식
- CD를 쌓아올리듯 먼저 들어간 자료가 밑에 위치하며, 꺼낼 때는 가장 위의 자료가 꺼내짐

### 특징
- 한 방향으로만 저장 가능
- 시간 순서에 따라 저장
    - 가장 마지막에 삽입된 자료가 가장 먼저 삭제됨

- top에서만 데이터 접근 가능 / bottom
- push: top 위에 자료를 삽입하는 연산
- pop: top 위의 자료를 삭제하는 연산
- stack underflow: 비어있는 스택에 접근할 때
- stack overflow: 스택이 넘치는 경우

### C++

```c++
#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    #stack 구조 변경 시
    stack<int, vector<int>> st2;

    st.push(1); #삽입
    st.push(2); #삽입
    st.push(3); #삽입

    st.pop(); #3 삭제
    st.top(); #2 반환

    st.size(); #스택 크기(2) 반환
    st.empty(); #스택 비어있는지 확인
}
```


## Queue
- FIFO (First In First Out) 방식
- 줄을 서서 기다리듯 먼저 선 사람이 먼저 나가게 되는 방식

### 특징
- 양 방향 연산 (한 쪽 끝에서는 삽입, 다른 쪽 끝에서는 삭제)
- front: 삭제 수행되는 곳(가장 첫 원소 자리) / rear: 삽입 수행되는 곳
- enQueue: rear에서 이루어지는 삽입 연산
- deQueue: front에서 이루어지는 삭제 연산

### C++

```c++
#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;

    q.push(2); #삽입
    q.push(3); #삽입
    q.pop(); #2 삭제

    q.push(4); #삽입
    q.push(5); #삽입
    q.front(); #3 반환
    q.back(); #5 반환
    q.size(); #사이즈(3) 반환
    q.empty(); #비어있는지 확인
}
```