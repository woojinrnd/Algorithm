#include <iostream>

using namespace std;

int n;
int N[101];
int res;

void input() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> N[i];
    }
}

// root(x)까지만 계산해서, 나누어 떨어지는 수가 없으면 소수
bool is_prime(int x) {
    if (x < 2) return false;  // 1과 0은 소수가 아님
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void solution() {
    for (int i=0; i<n; ++i) {
        if (is_prime(N[i])) res++;
    }
    cout << res << '\n';
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