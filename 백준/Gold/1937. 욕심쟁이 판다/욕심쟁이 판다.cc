#include <iostream>
#include <vector>

using namespace std;

int n, ans;
int N[500][500];
int dp[500][500]; // dp[i][j] : (i,j)에 있을 때 최대로 살 수 있는 일수 
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


void input() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> N[i][j];
		}
	}
}

int move(int x, int y) {
	if (dp[x][y] != 0) return dp[x][y];
	dp[x][y] = 1;
	
	for (int dir=0; dir<4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx>=0&&nx<n&&ny>=0&&ny<n) {
			if (N[x][y] < N[nx][ny]) {
				dp[x][y] = max(dp[x][y], move(nx, ny)+1);
			}
		}
	}
	return dp[x][y]; 
}

void solution() {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			ans = max(ans, move(i, j));
//			cout << dp[i][j] << ' ';
		}
//		cout << '\n';
	}
}

void solve() {
	input();
	solution();
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	
	return 0;
}