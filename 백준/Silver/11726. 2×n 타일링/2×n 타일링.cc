#include <iostream>

using namespace std;

int n;
int dp[1005];

void input () {
	cin >> n;
} 

void solution() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i=3; i<=n; ++i) {
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] = dp[i] % 10007;
	}
	cout << dp[n] << '\n';
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}