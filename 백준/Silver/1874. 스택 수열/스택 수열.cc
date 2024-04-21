#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    stack<int> s;
    vector<char> operations;  // '+' 또는 '-' 연산을 기록할 벡터
    int nextPush = 1;         // 다음에 push 할 숫자

    for (int i = 0; i < n; ++i) {
        int num = sequence[i];

        // 필요한 숫자까지 push 수행
        while (nextPush <= num) {
            if (nextPush > n) break;
            s.push(nextPush);
            operations.push_back('+');
            nextPush++;
        }

        // 스택의 top과 현재 숫자가 일치하면 pop
        if (!s.empty() && s.top() == num) {
            s.pop();
            operations.push_back('-');
        } else {
            // 일치하지 않으면 더 이상 만들 수 없으므로 "NO" 출력 후 종료
            cout << "NO" << endl;
            return 0;
        }
    }

    // 연산 기록 출력
    for (char op : operations) {
        cout << op << '\n';
    }

    return 0;
}
