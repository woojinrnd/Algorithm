#include <iostream>
#include <queue>

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
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> N[i][j];
			// 익은 토마토(1) -> bfs 시작점
			if (N[i][j] == 1) {
				dist[i][j] = 0;
				q.push({i, j}); 
			}
			// 탐색 필요 구간 
			if (N[i][j] == 0) {
				dist[i][j] = -1;
			}
		}
	}
	// dist 배열 -> 일수 계산 
	while(!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int dir=0; dir<4; ++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx<0||nx>=n||ny<0||ny>=m) continue;
			if (dist[nx][ny]>=0||N[nx][ny]==-1) continue;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			q.push({nx, ny});
		}
	}
	
	// 최종 일수 계산
	// 익지 않은 토마토가 하나라도 있다면 -> -1 출력
	// 다 익었다면 						  ->  0 출력 
	int res = 0;
	int max_day = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			// 예외 처리 -> 안쪽 for문 탈출
			if (dist[i][j] == -1) {
				res = -1; 
				break;
			}
			else {
				if (dist[i][j] > max_day) {
					max_day = dist[i][j];
					res = max_day;
				}
			}
		}
		// 예외 처리 -> 바깥쪽 for문 탈출 
		if (res == -1) break;
	}
	cout << res;	
	
	return 0;
}