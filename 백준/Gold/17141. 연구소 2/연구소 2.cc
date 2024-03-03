#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int max_size = 50;
int n, m;
int N[max_size][max_size];
bool vist[max_size][max_size];
bool isused[max_size];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ans = 100;
struct point {
	int x, y;
	point(int xx, int yy) : x(xx), y(yy) {};
};
vector<point> V;		// 바이러스 후보군	 
vector<point> V_sel;	// 선택된 바이러스 조합 

void input() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> N[i][j];
			if (N[i][j] == 2) V.push_back({i, j});
		}
	}
}

// Check the map state
bool check() {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (N[i][j] == 1) continue; 	//벽은 무시
			if (vist[i][j] == false) return false;	// 아직 방문하지 않은 공간 존재 -> 바이러스 덜 감염 
		}
	}
	return true;
}

// Spread Virus
// start point : V_sel
void spread_virus() {
	queue<point> q;
	for (int i=0; i<V_sel.size(); ++i) {
		vist[V_sel[i].x][V_sel[i].y] = true;
		q.push({V_sel[i]});
	}
	int cnt = 0; // 퍼진 시간
	while(!q.empty()) {
		int S = q.size();
		for (int i=0; i<S; ++i) {
			point cur = q.front();
			q.pop();
			for (int dir=0; dir<4; ++dir) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if (nx<0||nx>=n||ny<0||ny>=n) continue;
				if (vist[nx][ny]||N[nx][ny]==1) continue;
				vist[nx][ny] = true;
				q.push({nx, ny});
			}
		}
		if (!q.empty()) cnt++;
	}
	// 다 퍼졌다면 최솟값 갱신 
	if (check()) {
		if (ans > cnt) ans = cnt; 	
	}
}

// Combination
// idx : for 문의 시작점
// cnt : 현재 방문 층 
void comb(int idx, int cnt) {
	// Base Condition
	if (cnt == m) {
		memset(vist, false, sizeof(vist));
		spread_virus();
		return ;
	} 
	// Recursive part
	for (int i=idx; i<V.size(); ++i) {
		if (isused[i] == true) continue;	//pruning
		isused[i] = true;
		V_sel.push_back(V[i]);
		comb(i, cnt+1);
		V_sel.pop_back();
		isused[i] = false; 
	}
}

void sol() {
	input();
	comb(0, 0);
	if (ans == 100) ans = -1;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sol();
	return 0;
}