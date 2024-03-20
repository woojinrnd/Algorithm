#include <iostream>
#include <queue>

using namespace std;

int n, m;
char N[1003][1003];
int dist1[1003][1003]; // FIRE
int dist2[1003][1003]; // JIHOON
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point{
	int x, y;
};

queue<point> q1; // FIRE
queue<point> q2; // JIHOON

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	// Initialize dist array
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			dist1[i][j] = -1;
			dist2[i][j] = -1;
		}
	}
	
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> N[i][j];
			// BFS start point
			// Fire
			if (N[i][j] == 'F') {
				dist1[i][j] = 0;
				q1.push({i, j});
			}
			// JIHOON
			if (N[i][j] == 'J') {
				dist2[i][j] = 0;
				q2.push({i, j});
			}
		}
	}
	// BFS - Fire
	while(!q1.empty()) {
		point cur = q1.front();
		q1.pop();
		for (int dir=0; dir<4; ++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx<0||nx>=n||ny<0|ny>=m) continue;
			if (N[nx][ny]=='#'||dist1[nx][ny]>=0) continue;
			dist1[nx][ny] = dist1[cur.x][cur.y]+1;
			q1.push({nx, ny});
		} 
	}
	// BFS - Jihoon
	while(!q2.empty()) {
		point cur = q2.front();
		q2.pop();
		for (int dir=0; dir<4; ++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			// 탈출 조건 
			if (nx<0||nx>=n||ny<0||ny>=m) {
				cout << dist2[cur.x][cur.y]+1 << '\n';
				return 0;
			}
			if (N[nx][ny]=='#'|| dist2[nx][ny]>=0) continue; 
			// 불이 지훈이보다 먼저 간 경우
			// 불의 (다음좌표)와 지훈이의 (현재좌표)를 비교
			// 다음 좌표를 큐에 담아 bfs돌릴지 말지를 결정할거니까 
			// dist1[nx][ny] <=  dist2[cur.x][cur.y]+1
			if (dist1[nx][ny]!=-1 && dist1[nx][ny]<=dist2[cur.x][cur.y]+1) continue;
			dist2[nx][ny] = dist2[cur.x][cur.y]+1;
			q2.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}