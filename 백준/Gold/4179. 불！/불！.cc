#include <iostream>
#include <queue>

using namespace std;

struct Coord {
    int x, y;
};

int n, m;
char N[1002][1002];
int dist1[1002][1002]; // 불의 확산 시간 기록
int dist2[1002][1002]; // 지훈이의 이동 시간 기록
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    queue<Coord> Q1; // 불의 좌표를 담을 큐
    queue<Coord> Q2; // 지훈이의 좌표를 담을 큐

    // 초기화
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist1[i][j] = -1; // 불의 확산 시간 초기값 설정
            dist2[i][j] = -1; // 지훈이의 이동 시간 초기값 설정
        }
    }

    // 입력 받기 및 초기 큐에 좌표 넣기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> N[i][j];
            if (N[i][j] == 'F') {
                Q1.push({i, j});
                dist1[i][j] = 0; // 초기 불의 위치를 0으로 설정
            }
            if (N[i][j] == 'J') {
                Q2.push({i, j});
                dist2[i][j] = 0; // 초기 지훈이의 위치를 0으로 설정
            }
        }
    }

    // 불의 확산
    while (!Q1.empty()) {
        Coord cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist1[nx][ny] >= 0 || N[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
            Q1.push({nx, ny});
        }
    }

    // 지훈이의 이동
    while (!Q2.empty()) {
        Coord cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist2[cur.x][cur.y] + 1; // 탈출 조건
                return 0;
            }
            if (dist2[nx][ny] >= 0 || N[nx][ny] == '#') continue;
            // 불이 확산되는 시간보다 이후에 도착하는 경우는 무시
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.x][cur.y] + 1) continue;
            dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
            Q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE"; // 지훈이가 탈출할 수 없는 경우
    return 0;
}
