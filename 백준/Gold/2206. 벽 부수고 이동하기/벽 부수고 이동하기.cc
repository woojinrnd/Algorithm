#include <iostream>
#include <queue>

using namespace std;

int n, m;
char N[1000][1000];
// [0] : 벽을 부수지 않고 목적지 도달
// [1] : 벽을 부수고 목적지 도달 
int dist[1000][1000][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct point {
	int x, y;
	int broken; 
}; 

bool OOB(int x, int y) {
	return (x<0||x>=n||y<0||y>=m);
} 

int bfs() {
	// 초기화 
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			dist[i][j][0] = dist[i][j][1] = -1; // 모든 거리값을 -1로 초기화
		}
	}

	queue<point> q;
	dist[0][0][0] = dist[0][0][1] = 0; // 시작점의 거리값을 0으로 초기화
	q.push({0, 0, 0});

	while(!q.empty()) {
		point cur = q.front();
		// 큐에서 값을 꺼내기 전(새로운 탐색을 시작하기 전)도착하면 거리값을 출력 
		if (cur.x==n-1 && cur.y==m-1) return dist[cur.x][cur.y][cur.broken]+1;
		q.pop();
		for (int dir=0; dir<4; ++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (OOB(nx, ny)) continue;

			if (N[nx][ny]=='0' && dist[nx][ny][cur.broken]==-1) {
				// 벽을 부수지 않았을 때, 이동할 수 있는 경우의 거리값을 갱신하고 큐에 추가
				dist[nx][ny][cur.broken] = dist[cur.x][cur.y][cur.broken] + 1;
				q.push({nx, ny, cur.broken});
			}

			if (!cur.broken && N[nx][ny] == '1' && dist[nx][ny][1]==-1) {
				// 벽을 부수지 않았고, 벽이 있는 칸에 도달한 경우,
				// 벽을 부수고 이동하는 경우의 거리값을 갱신하고 큐에 추가
				dist[nx][ny][1] = dist[cur.x][cur.y][cur.broken] + 1;
				q.push({nx, ny, 1});
			}			
		}
	} 
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> N[i][j];
		}
	}

	cout << bfs(); // 최단 경로 출력 
	return 0;
}
