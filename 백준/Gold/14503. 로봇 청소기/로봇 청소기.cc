#include <iostream>
using namespace std;

int n, m;
int N[53][53];      // 0: 빈 칸, 1: 벽
int vist[53][53];   // 1: 청소됨

// 북 동 남 서
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct point {
    int x, y, dir;
};
point now;

bool work = true;

void input() {
    cin >> n >> m;
    cin >> now.x >> now.y >> now.dir;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> N[i][j];
        }
    }
}

bool checkClean(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (N[nx][ny] == 0 && vist[nx][ny] == 0) return true;
    }
    return false;
}

point backward(int x, int y, int dir) {
    int nx = x + dx[(dir + 2) % 4];
    int ny = y + dy[(dir + 2) % 4];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || N[nx][ny] == 1) {
        work = false;
        return { x, y, dir };
    }
    return { nx, ny, dir };
}

int rotate(int dir) {
    return (dir + 3) % 4;
}

void solution() {
    while (work) {
        // 1. 현재 위치 청소
        if (vist[now.x][now.y] == 0) vist[now.x][now.y] = 1;

        // 2. 주변에 청소되지 않은 칸 있는지 확인
        if (checkClean(now.x, now.y)) {
            // 왼쪽으로 회전 후, 전진 가능한지 확인
            now.dir = rotate(now.dir);
            int nx = now.x + dx[now.dir];
            int ny = now.y + dy[now.dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && N[nx][ny] == 0 && vist[nx][ny] == 0) {
                now.x = nx;
                now.y = ny;
            }
            // 전진 불가면 회전만 하고 다음 루프에서 다시 확인
        }
        else {
            // 3. 주변 4칸 모두 청소되었으면 뒤로 한 칸 이동
            now = backward(now.x, now.y, now.dir);
        }
    }

    // 청소한 칸 수 출력
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (vist[i][j] == 1) cnt++;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solution();

    return 0;
}
