#include <iostream>
using namespace std;

int n, m; // 행렬의 크기를 나타내는 변수 n(행), m(열)
int ans; // 최종 결과(최대 합)를 저장하는 변수
int N[1000][1000]; // 입력 행렬을 저장하는 2차원 배열
// cost[a][b][c] = d: (a, b) 위치에 c 방향(0: 아래, 1: 오른쪽, 2: 왼쪽)으로 들어왔을 때 최대 값은 d
int cost[1000][1000][3];
bool vist[1000][1000]; // 해당 위치를 방문했는지 체크하는 배열

int dx[] = {1, 0, 0}; // x축 이동 방향 (아래, 오른쪽, 왼쪽)
int dy[] = {0, 1, -1}; // y축 이동 방향

// 입력 함수: 행렬의 크기와 요소들을 입력받는 함수
void input() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> N[i][j];
		}
	}
}

// 깊이 우선 탐색(DFS) 함수
int dfs(int x, int y, int dir) {
	// 목적지에 도달했을 경우, 해당 위치의 값을 반환
	if (x == n-1 && y == m-1) return N[x][y];
	// 이미 계산된 값이 있다면 재활용
	if (cost[x][y][dir] != -987654321) return cost[x][y][dir];
	
	vist[x][y] = true; // 현재 위치 방문 처리
	
	int biggest_value = -987654321; // 현재 위치에서 이동할 수 있는 최대값
	for (int i=0; i<3; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 이동한 위치가 유효한 범위 내에 있고, 아직 방문하지 않았다면
		if (nx>=0 && nx<n && ny>=0 && ny<m && !vist[nx][ny]) {
			// 최대값 갱신- 시도
			biggest_value = max(biggest_value, dfs(nx, ny, i));
		}
	}
	vist[x][y] = false; // 방문 처리 해제
	cost[x][y][dir] = N[x][y] + biggest_value; // 현재 위치에서의 최대값 업데이트
	return cost[x][y][dir];
}

// 솔루션 함수: 초기 설정 후 DFS를 시작하는 함수
void solution() {
	// cost 배열을 -1로 초기화 (아직 계산되지 않음을 의미)
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cost[i][j][0] = -987654321;
			cost[i][j][1] = -987654321;
			cost[i][j][2] = -987654321;
		}
	}
	// DFS 시작
	ans = dfs(0, 0, 0);
	cout << ans << '\n'; // 최대 합 출력
}

// 메인 함수: 프로그램의 진입점
void solve() {
	input(); // 입력 함수 호출
	solution(); // 솔루션 함수 호출
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve(); // solve 함수 호출
	
	return 0;
}
