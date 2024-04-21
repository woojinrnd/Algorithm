#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);  // C++의 입출력과 C의 입출력을 동기화
    cin.tie(0);  // cin과 cout을 동기화

    while (1) {
        string str;
        getline(cin, str);  // 한 줄을 읽어옴
        if (str == ".") break;  // 입력이 '.'일 경우 종료

        stack<char> buf;  // 괄호를 저장하는 스택
        bool isValid = true;  // 괄호가 유효한지 확인하는 변수

        // 입력 문자열을 한 글자씩 처리
        for (auto c : str) {
            if (c == '(' || c == '[')  // 여는 괄호일 경우 스택에 추가
                buf.push(c);
            else if (c == ')') {
                // 닫는 괄호일 경우 스택이 비어있거나 맨 위의 괄호와 매칭되지 않으면 유효하지 않음
                if (buf.empty() || buf.top() != '(') {
                    isValid = false;
                    break;
                }
                buf.pop();  // 매칭되면 스택에서 제거
            } else if (c == ']') {
                // 닫는 괄호일 경우 스택이 비어있거나 맨 위의 괄호와 매칭되지 않으면 유효하지 않음
                if (buf.empty() || buf.top() != '[') {
                    isValid = false;
                    break;
                }
                buf.pop();  // 매칭되면 스택에서 제거
            }
        }

        // 모든 문자열을 처리한 후에도 스택에 괄호가 남아있으면 유효하지 않음
        if (!buf.empty())
            isValid = false;

        // 결과 출력
        if (isValid)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
