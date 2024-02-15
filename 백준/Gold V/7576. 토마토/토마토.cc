#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Coord {
	int x, y;
};

int n, m;
int N[1002][1002];  // 입력으로 받는 토마토 상자의 상태를 저장하는 배열
int dist[1002][1002];  // 각 토마토까지의 최단 거리를 저장하는 배열
int dx[4] = {1, 0, -1, 0};  // x 방향 이동에 대한 배열
int dy[4] = {0, 1, 0, -1};  // y 방향 이동에 대한 배열

int main() {
	ios::sync_with_stdio(0);  // 동기화를 통해 입출력 속도 향상
	cin.tie(0);  // 입출력 버퍼를 비우지 않도록 함
	cin >> m >> n;  // 가로, 세로 크기 입력
	queue<Coord> Q;  // BFS를 위한 큐
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> N[i][j];  // 토마토 상태 입력
			if (N[i][j] == 1)  // 익은 토마토라면 큐에 좌표를 넣음
				Q.push({i, j});
			if (N[i][j] == 0)  // 익지 않은 토마토라면 최단 거리를 나타내는 dist 배열을 -1로 초기화
				dist[i][j] = -1;
		}
	}
	
	while (!Q.empty()) {
		Coord cur = Q.front();  // 현재 위치를 큐에서 꺼냄
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  // 범위를 벗어나면 스킵
			if (dist[nx][ny] >= 0) continue;  // 이미 방문한 곳이면 스킵
			dist[nx][ny] = dist[cur.x][cur.y] + 1;  // 최단 거리 갱신
			Q.push({nx, ny});  // 다음 위치를 큐에 넣음
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dist[i][j] == -1) {  // 익지 않은 토마토가 있는 경우
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);  // 최단 거리 중 가장 큰 값 찾기
		}
	}
	cout << ans;  // 결과 출력
	
	return 0;
}
