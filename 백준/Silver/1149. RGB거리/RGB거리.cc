#include <iostream>
#include <vector>

using namespace std;

int n, ans;
int N[1003][3];
int dp[1003][3];

void input() {
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> N[i][0] >> N[i][1] >> N[i][2];
	}
	
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	N[0][0] = N[0][1] = N[0][2] = 0;
}

void solution() {
	for (int i=1; i<=n; ++i) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + N[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + N[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + N[i][2];
	}
	ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
	cout << ans;
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	
	return 0;
}
