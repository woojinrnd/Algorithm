#include <iostream>
#include <algorithm>

using namespace std;

int n;
int N[1000][1000];
int dp[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	// cost matrix
	for (int i=0; i<n; ++i) {
		for (int j=0; j<3; ++j) {
			cin >> N[i][j];
			dp[0][j] = N[0][j];
		}
	}
	// minimum sum cost matrix
    // row(i) -> row(i+1) : row(i)에서 동일 열을 제외한 최솟값 찾기
    // dp[i][j] = min(dp[i-1][j-1], dp[i-1][j+1])
	for (int i=1; i<n; ++i) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + N[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + N[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + N[i][2];
	}
	cout << *min_element(dp[n-1], dp[n-1]+3);
	
	return 0;
}
