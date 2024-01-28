#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Coord {
    int x, y, z;
};

int m, n, h; // 가로 세로 높이 
int N[103][103][103];
int dist[103][103][103];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    // 입력 받기
    cin >> m >> n >> h;
    queue<Coord> Q;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> N[j][k][i];
                // 익은 토마토의 위치를 큐에 추가하고 해당 위치의 거리 초기화
                if (N[j][k][i] == 1) {
                    Q.push({j, k, i});
                    dist[j][k][i] = 0;
                } else if (N[j][k][i] == 0) {
                    dist[j][k][i] = -1;
                }
            }
        }
    }

    // BFS 수행
    while (!Q.empty()) {
        Coord cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 6; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];
            // 범위 체크
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            // 방문하지 않은 곳이면 거리 갱신하고 큐에 추가
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
            Q.push({nx, ny, nz});
        }
    }

    // 최종 답 계산
    int ans = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                // 익지 않은 토마토가 있는 경우 -1 출력 후 종료
                if (dist[j][k][i] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }

    // 정답 출력
    cout << ans;
    return 0;
}
