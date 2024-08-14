#include <iostream>

using namespace std;

int M, N; // M <= x <= N
int arr[10002];

void input() {
    cin >> M >> N;
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i=2; i*i<=x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void solution() {
    int sum = 0;
    int minVal = -1;
    for (int i=M; i<=N; ++i) {
        if (is_prime(i)) {
            sum += i;
            if (minVal == -1) minVal = i; // 첫번째 소수를 발견한 경우
        }
    }
    if (minVal == -1) {
        cout << -1 << '\n';
    }
    else {
        cout << sum << '\n' << minVal << '\n';
    }
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