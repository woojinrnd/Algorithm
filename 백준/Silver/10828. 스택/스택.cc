#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);  // C++의 iostream과 C의 stdio를 동기화시킴으로써 입출력 속도 향상
    cin.tie(0);  // cin과 cout의 tie를 풀어서 버퍼를 비워줌으로써 성능 향상

    int T;
    cin >> T;  // 테스트 케이스의 개수 입력

    stack<int> stk;  // 정수를 저장하는 스택 선언

    while (T--) {  // 테스트 케이스 수만큼 반복
        string str;
        cin >> str;  // 명령어 입력

        if (str == "push") {  // push 명령어인 경우
            int t;
            cin >> t;  // 정수 입력
            stk.push(t);  // 스택에 정수 추가
        } else if (str == "pop") {  // pop 명령어인 경우
            if (stk.empty())  // 스택이 비어있으면
                cout << -1 << '\n';  // -1 출력
            else {
                cout << stk.top() << '\n';  // 스택의 맨 위에 있는 정수 출력
                stk.pop();  // 스택에서 정수 제거
            }
        } else if (str == "size") {  // size 명령어인 경우
            cout << stk.size() << '\n';  // 스택에 들어있는 정수의 개수 출력
        } else if (str == "empty") {  // empty 명령어인 경우
            if (stk.empty())  // 스택이 비어있으면
                cout << 1 << '\n';  // 1 출력
            else {
                cout << 0 << '\n';  // 그렇지 않으면 0 출력
            }
        } else {  // top 명령어인 경우
            if (stk.empty())  // 스택이 비어있으면
                cout << -1 << '\n';  // -1 출력
            else {
                cout << stk.top() << '\n';  // 스택의 맨 위에 있는 정수 출력
            }
        }
    }

    return 0;
}
