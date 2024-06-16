#include <iostream>

using namespace std;

int n;
int T[20];
int P[20];
int dp[20]; // dp[a] = b : a번째 일을 했을 때의 최대이익


void input() {
    cin >> n; 
    for (int i=1; i<=n; ++i) {
        cin >> T[i] >> P[i];
    }
}

void solution() {
    for (int i=n; i>=1; --i) {
        // 퇴사 불가능 
        if (i+T[i] > n+1) dp[i] = dp[i+1];
        // 퇴사 가능 -> 일 할래 말래
        else dp[i] = max(dp[i+1], dp[i+T[i]] + P[i]);
    }
    cout << dp[1] << '\n';
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