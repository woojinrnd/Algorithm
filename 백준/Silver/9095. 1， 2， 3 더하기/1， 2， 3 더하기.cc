#include <iostream>

using namespace std;

int dp[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	dp[1] = 1; // 1
	dp[2] = 2; // (1, 1), (2)
	dp[3] = 4; // (1,1,1), (2,2), (3,1) (1,3)
	// dp[4] = 7 = dp[1] + dp[2] + dp[3]
	
	for (int i=4; i<11; ++i) {
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}
	
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	
	return 0;
}