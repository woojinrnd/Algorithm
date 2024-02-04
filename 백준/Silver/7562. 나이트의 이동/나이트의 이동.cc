#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T; // test case 
int n; // 체스판 길이
int vist[304][304]; // 각 칸까지의 최소 이동 횟수를 저장하는 배열
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1}; // 이동할 수 있는 모든 경우의 수
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct point {
	int x, y;
};

point start, End;
queue<point> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				vist[i][j] = -1; // 초기화: 방문하지 않은 칸은 -1로 설정
			}
		}
		cin >> start.x >> start.y;
		vist[start.x][start.y] = 0; // 시작점은 이동 횟수가 0
		Q.push({start.x, start.y}); // 시작점을 큐에 삽입

		cin >> End.x >> End.y;
		
		while (!Q.empty()) {
			point cur = Q.front();
			Q.pop();
			for (int dir=0; dir<8; ++dir) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if (nx<0 || nx>=n || ny<0 || ny>=n) continue; // 범위를 벗어나면 무시
				if (vist[nx][ny] >= 0) continue; // 이미 방문한 칸이면 무시
				vist[nx][ny] = vist[cur.x][cur.y] + 1; // 이동 횟수 갱신
				Q.push({nx, ny}); // 다음 위치를 큐에 삽입
			}
		} 
		cout << vist[End.x][End.y] << '\n'; // 목적지까지의 최소 이동 횟수 출력
	}
	
	return 0;
}
