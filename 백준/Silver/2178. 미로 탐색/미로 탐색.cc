#include <iostream>
#include <queue>
#include <cstring> // memset을 사용하기 위한 헤더

using namespace std;

// 좌표를 나타내는 구조체
struct Coord {
    int x, y;
};

int main() {
    // 입력 받을 도화지의 세로와 가로 크기
    int n, m;
    cin >> n >> m;

    // 도화지의 각 칸에 색칠 여부를 나타내는 배열
    char board[n][m];
    // 출발점부터의 거리를 저장하는 배열
    int dist[n][m];
    // 이동 방향을 나타내는 배열
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 도화지 정보 입력
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    // 배열 초기화
    memset(dist, -1, sizeof(dist));

    // BFS를 위한 큐와 시작점 설정
    queue<Coord> Q;
    Q.push({0, 0});
    dist[0][0] = 0;

    // BFS 탐색
    while (!Q.empty()) {
        // 현재 위치
        Coord cur = Q.front();
        Q.pop();

        // 4방향 이동 확인
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            // 범위를 벗어나면 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // 이미 방문했거나 색칠되지 않은 부분이면 무시
            if (dist[nx][ny] != -1 || board[nx][ny] != '1')
                continue;

            // 거리 갱신 및 큐에 새로운 위치 삽입
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({nx, ny});
        }
    }

    // 마지막 위치까지의 거리 출력
    cout << dist[n - 1][m - 1] + 1;

    return 0;
}
