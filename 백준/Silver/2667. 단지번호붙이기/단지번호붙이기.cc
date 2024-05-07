#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
char N[25][25];
int vist[25][25];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
	int x, y;
};

int group_cnt;
vector<int> house_cnt;

void input() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> N[i][j];
		}
	}
}

void solution() {
	// bfs 시작점 (i, j) 
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (N[i][j] == '0' || vist[i][j]) continue;
			
			queue<point> q;
			vist[i][j] = 1;
			q.push({i, j});
			group_cnt++;
			int tmp_cnt = 0;
			while(!q.empty()) {
				point cur = q.front();
				q.pop();
				tmp_cnt++;
				for (int dir=0; dir<4; ++dir) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx<0||nx>=n||ny<0||ny>=n) continue;
					if (N[nx][ny]=='0'||vist[nx][ny]) continue;
					vist[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
			house_cnt.push_back(tmp_cnt);
		}
	}
}

void solve() {
	input();
	solution();
	cout << group_cnt << '\n';
	sort(house_cnt.begin(), house_cnt.end());
	for (int i=0; i<group_cnt; ++i) {
		cout << house_cnt[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}