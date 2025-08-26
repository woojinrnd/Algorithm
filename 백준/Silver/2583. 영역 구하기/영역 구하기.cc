#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int MAP[101][101];
bool vist[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
struct point {
	int x, y;
};
struct rec {
	int x1, y1, x2, y2;
};
rec Rectangle[101];
vector<int> area;

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			MAP[i][j] = 0;
		}
	}
	for (int i = 0; i < K; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Rectangle[i] = { x1, y1, x2, y2 };
	}
}

// 좌표 (x, y) -> (col, raw)
// x는 그대로
// y는 (N-y2) ~ (N~y1)

void draw() {
	for (int i = 0; i < K; ++i) {
		for (int j = (N - Rectangle[i].y2); j < (N - Rectangle[i].y1); ++j) {
			for (int k = Rectangle[i].x1; k < Rectangle[i].x2; ++k) {
				MAP[j][k] = 1;
			}
		}
	}
}

void solution() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (MAP[i][j] == 1 || vist[i][j]==true) continue;
			queue<point> q;
			vist[i][j] = true;
			q.push({ i, j });
			int each_area = 0;
			while (!q.empty()) {
				point cur = q.front();
				q.pop();
				each_area++;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (MAP[nx][ny] == 1 || vist[nx][ny] == true) continue;
					vist[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
			area.push_back(each_area);
		}
	}
	sort(area.begin(), area.end());
	cout << area.size() << '\n';
	for (int i : area) {
		cout << i << ' ';
	}
}

void solve() {
	input();
	draw();
	solution();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}