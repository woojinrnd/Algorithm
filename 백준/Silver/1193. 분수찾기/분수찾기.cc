#include <iostream>
#include <string>

using namespace std;

int x;

void input () {
    cin >> x;
}

void solution() {
    // diag = 현재 대각선 번호
    // sum  = 이전 대각선까지의 총 분수 개수
    // x    = 우리가 찾고 싶은 번호
    int diag = 1;
    int sum = 0;

    // X가 속한 대각선 찾기
    while (sum + diag < x) {
        sum += diag;
        diag++;
    }

    int idx = x - sum; // 대각선 안에서의 위치 (1-based)
    int num, den;

    if (diag % 2 == 1) {
        // 홀수 대각선: 아래 → 위
        // 5/1
        // 4/2
        // 3/3
        // 2/4
        // 1/5
        num = diag - idx + 1;
        den = idx;
    } else {
        // 짝수 대각선: 위 → 아래
        // 1/4
        // 2/3
        // 3/2
        // 4/1
        num = idx;
        den = diag - idx + 1;
    }

    cout << num << "/" << den;
}

void solve() {
    input();
    solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}