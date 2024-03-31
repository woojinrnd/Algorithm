#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int N[100005];
int dp[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	// dp = sigma(1~n)
	for (int i=1; i<=n; ++i) {
		cin >> N[i];
		dp[i] = N[i] + dp[i-1];
	}
	// sigma(1~y) - sigma(1~x)
	for (int i=0; i<m; ++i) {
		int x, y;
		cin >> x >> y;
		cout << dp[y] - dp[x-1] << '\n';
	}

	return 0;
}
