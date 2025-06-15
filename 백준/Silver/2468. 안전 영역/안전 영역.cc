#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, ans;
int N[100][100];
int c_N[100][100];
int vist[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
	int x, y;
};

int min_depth = 101;
int max_depth = 0;
vector<int> tmp_depth; // depth 후보군 

void input() {
	cin >> n; 
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> N[i][j];
			min_depth = min(N[i][j], min_depth);
			max_depth = max(N[i][j], max_depth);
			
			// 예외 case : 모두 같은 숫자라면, 한 덩어리가 답 
			if (min_depth == max_depth) {
				ans = 1;
			}
		}
	}
	
	// depth 후보군 적립 
	for (int i=min_depth; i<=max_depth; ++i) {
		tmp_depth.push_back(i);
	}
}

// map copy to reuse again 
void copy_map() {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			c_N[i][j] = N[i][j];
		}
	}
}

// clear vist array
void clear_vist() {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			vist[i][j] = 0;
		}
	}	
}

void solution() {
	// depth 후보군에 대하여 하나씩 
	for (int k=0; k<tmp_depth.size(); ++k) {
		// depth가 바뀔때마다 필요한 초기화 과정 
		copy_map();
		clear_vist();
		int tmp_cnt = 0;
		
		// bfs start : (i, j) 
		// condition 
		// 탐색 가능   :   현재 depth 초과 
		// 탐색 불가능 : 현재 depth 이하 
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (c_N[i][j] <= tmp_depth[k] || vist[i][j]) continue;
				queue<point> q;
				vist[i][j] = 1;
				q.push({i, j});
				tmp_cnt++;
				while(!q.empty()) {
					point cur = q.front();
					q.pop();
					for (int dir=0; dir<4; ++dir) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx<0||nx>=n||ny<0||ny>=n) continue;
						if (vist[nx][ny]||c_N[nx][ny]<=tmp_depth[k]) continue;
						vist[nx][ny] = 1;
						q.push({nx, ny});
					}
				}
			}
		}
		ans = max(ans, tmp_cnt);
	}
	cout << ans;
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}