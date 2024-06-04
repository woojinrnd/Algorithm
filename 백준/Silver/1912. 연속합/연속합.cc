#include <iostream>

using namespace std;

int n;
long long N[100001];
long long dp[100001];
// dp[a] = b : a번째 값을 선택했을 때, 구할 수 있는 연속합의 최댓값 b
long long ans;

void input() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> N[i];
    }
}

void solution() {
    dp[0] = N[0];
    ans = dp[0];
    for (int i=1; i<n; ++i) {
        dp[i] = max(dp[i-1]+N[i], N[i]);
        ans = max(ans, dp[i]);
    }
}

void solve() {
    input();
    solution();

    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}