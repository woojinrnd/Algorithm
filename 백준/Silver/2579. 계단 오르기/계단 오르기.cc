#include <iostream>

using namespace std;

int n;
int arr[301]; // 계단
int dp[301]; // 해당 계단까지의 max값

void input() {
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> arr[i];
	}
} 

void solution() {
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1]+arr[3], arr[2]+arr[3]);
	
	// 도착계단 전 2step : dp[n-2] + arr[n]
	// 도착계단 전 1step : dp[n-3] + arr[n-1] + arr[n] 
	for (int i=4; i<=n; ++i) {
		dp[i] = max(dp[i-2] + arr[i], dp[i-3]+arr[i-1]+arr[i]);
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