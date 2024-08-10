#include <iostream>

using namespace std;

int n;
int fibo[21]; // fibo[a] = b : a번째 피보나치 수는 b입니다.

void input() {
    cin >> n;
}

void solution() {
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i=2; i<=n; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];

    }
    cout << fibo[n] << '\n';
}

void solve() {
    input();
    solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}