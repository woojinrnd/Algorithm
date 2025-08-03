#include <iostream>

using namespace std;

int n, m;
char N[502][502];
int pr, pc;
int aliveTime;
int dx[] = {-1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int dir;
char c_dir[4] = { 'U', 'R', 'D', 'L' };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> N[i][j];
		}
	}
	cin >> pr >> pc;
}

// 게임 종료 때까지 time count
// (pr, pc)에서 start하는 경우의 수 4개 (U, R, D, L)
// 4개의 경우의 수 중에서 time이 가장 큰 값을 구하면됨


// 게임 종료 조건
// 1. 블랙홀 ('C')
// 2. map 밖으로 (OOB)


// 행성을 만났을 때 이동방향의 경우의 수
// 행성과 레이저간에 위치 관계를 파악
// x고정 : 보이저y > 행성y인경우 => L (0, -1) 
//		 '/'인경우 : (nowx+1, nowy-1) [1,-1] (-1, 0)
//       '\'인경우 : (nowx-1, nowy-1) [-1,-1] (1, 0)

//         보이저y < 행성y인경우 => R (0, 1)
//		 '/'인경우 : (nowx-1, nowy+1) [-1, 1] (
//       '\'인경우 : (nowx+1, nowy+1) [1, 1]

// y고정 : 보이저x > 행성x인경우 => U
//		 '/'인경우 : (nowx-1, nowy+1) : dir R로 
//       '\'인경우 : (nowx-1, nowy-1) : dir L로

//         보이저x < 행성x인경우 => D
//		 '/'인경우 : (nowx+1, nowy-1) : dir L로
//       '\'인경우 : (nowx+1, nowy+1) : dir R로


void solution() {
	for (int i = 0; i < 4; ++i) {
		int tmp_dir = i;
		int tmp_time = 0;
		int nx = pr-1;
		int ny = pc-1;
		while (true) {
			tmp_time++;
			nx = nx + dx[tmp_dir];
			ny = ny + dy[tmp_dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || N[nx][ny] == 'C') break;
			else if (N[nx][ny] == '\\') {
				if (tmp_dir == 0) tmp_dir = 3;
				else if (tmp_dir == 1) tmp_dir = 2;
				else if (tmp_dir == 2) tmp_dir = 1;
				else tmp_dir = 0;
			}
			else if (N[nx][ny] == '/') {
				if (tmp_dir == 0) tmp_dir = 1;
				else if (tmp_dir == 1) tmp_dir = 0;
				else if (tmp_dir == 2) tmp_dir = 3;
				else tmp_dir = 2;
			}

			if (tmp_time > n * m * 2) {
				dir = i;
				cout << c_dir[dir] << '\n';
				cout << "Voyager" << '\n';
				return;
			}
		}
		if (aliveTime < tmp_time) {
			aliveTime = tmp_time;
			dir = i;
		}
	}
	cout << c_dir[dir] << '\n' << aliveTime << '\n';
}

void solve() {
	input();
	solution();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
