#include <iostream>
#include <queue>

using namespace std;

void josephusQueue(int n, int k) {
    std::queue<int> q;

    // 큐에 1부터 n까지의 숫자를 넣음
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    std::cout << "<";
    while (!q.empty()) {
        // k-1번째까지의 숫자는 뒤로 보냄
        for (int i = 0; i < k - 1; ++i) {
            q.push(q.front());
            q.pop();
        }

        // k번째 숫자를 출력하고 큐에서 제거
        std::cout << q.front();
        q.pop();

        // 큐가 비어있지 않으면 ", " 출력
        if (!q.empty()) {
            std::cout << ", ";
        }
    }
    std::cout << ">";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    josephusQueue(n, k);

    return 0;
}
