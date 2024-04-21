#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
int MAP[502][502];
int DP[502][502];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void input() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> MAP[i][j];
			DP[i][j] = -1;
		}
	}
}

int DFS(int x, int y) {
	// base condition
	if (x == n-1 && y == m-1) return 1;
	// 메모이제이션 값이 존재한다면 그 값을 반환 
	if (DP[x][y] != -1) return DP[x][y];
	DP[x][y] = 0;
	// 탐색 
	for (int dir=0; dir<4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx>=0 && ny>=0 && nx<n && ny<m) {
			// 다음값 < 현재값 
			if (MAP[nx][ny] < MAP[x][y]) {
				// 재귀적 탐색 
				DP[x][y] = DP[x][y] + DFS(nx, ny);
			}
		}
	}
	return DP[x][y];
}

void solution() {
	ans = DFS(0, 0);
	cout << ans << '\n';
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