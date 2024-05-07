#include <iostream>

using namespace std;

int n;
int ans;
int dp[5000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	dp[3] = 1;
	dp[5] = 1;
	for (int i=6; i<=n; ++i) {
		// 3의 배수라면
        if (dp[i-3]) {
			dp[i] = dp[i-3] + 1;
		}
        // 5의 배수라면
		if (dp[i-5]) {
			dp[i] = dp[i-5] + 1;
		}
	}
	if (dp[n]) cout << dp[n];
	else cout << -1;
	
	return 0;
}