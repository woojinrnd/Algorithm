#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int N[1000][1000];
int dist[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
	int x, y;
};

queue<point> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> N[i][j];
			// 익은 토마토 : 1 -> bfs 시작점 
			if (N[i][j] == 1) {
				dist[i][j] = 0;	
				q.push({i, j});	
			}
			if (N[i][j] == 0) dist[i][j] = -1;
		}
	}
	
	// bfs start
	while(!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int dir=0; dir<4; ++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx<0||nx>=n||ny<0||ny>=m) continue;
			if (N[nx][ny]==-1||dist[nx][ny]>=0) continue;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			q.push({nx, ny});
		}
	}
	
	// check dist array to get result
	int result = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (N[i][j] == -1) continue;
			if (dist[i][j] == -1) {
				cout << -1 << '\n';
				return 0;
			}
			else {
				result = max(dist[i][j], result);
			}
		}
	}
	cout << result;
	return 0;
}