#include <iostream>
#include <queue>

using namespace std;

char N[101][101];
bool vis[101][101];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct point {
    int x, y;
};

// 좌표가 같은 색상인 영역을 BFS로 탐색하는 함수
void bfs(int i, int j) {
    queue<point> Q;
    Q.push({i, j});
    while (!Q.empty()) {
        point cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] == 1 || N[i][j] != N[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

// 구역 수를 세는 함수 (이름 변경)
int countAreas() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> N[i][j];
        }
    }

    // 초기화
    for (int i = 0; i < n; ++i) {
        fill(vis[i], vis[i] + n, false);
    }

    int not_g = countAreas(); // 적록색약 x

    // 초기화
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (N[i][j] == 'G') {
                N[i][j] = 'R';
            }
        }
    }

    // 초기화
    for (int i = 0; i < n; ++i) {
        fill(vis[i], vis[i] + n, false);
    }

    int is_g = countAreas();

    cout << not_g << " " << is_g;

    return 0;
}
