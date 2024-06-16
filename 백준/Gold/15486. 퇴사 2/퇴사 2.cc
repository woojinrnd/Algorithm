#include <iostream>

using namespace std;

#define MAX_SIZE 1500005

int n;
int T[MAX_SIZE];
int P[MAX_SIZE];
int dp[MAX_SIZE]; // dp[a]=b: a날에 일을 했을 때 최댓값 b

void input() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> T[i] >> P[i];
    }
}

void solution() {
    // n번째 날부터 1일차까지 계산
    for (int i=n; i>=1; --i) {
        // 퇴사 불가능하다면, 이전 data그대로
        // n번째 날에 1일치 일하는 경우는 가능해야하고, 아래 조건문을 통과하면 안됨
        if (i + T[i] > n+1) dp[i] = dp[i+1];
        
        // 퇴사가 가능하다면, max(말래/일할래)
        // 말래 : 이전 data 그대로
        // 일할래 : dp[i+duration time] + cost[i]
        else dp[i] = max(dp[i+1], dp[i+T[i]]+P[i]);
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