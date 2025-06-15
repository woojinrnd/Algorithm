#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int L, R, C;
char N[31][31][31];
int dist[31][31][31];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct point {
    int x, y, z;
};

queue<point> q;

void initialize() {
    memset(N, 0, sizeof(N));
    memset(dist, 0, sizeof(dist));
    q = queue<point>();
}

bool input() {
    cin >> L >> R >> C;
    if (L == 0 && R == 0 && C == 0) return false;
    cin.ignore(); // 줄바꿈 제거

    initialize();

    for (int i = 0; i < L; ++i) {
        int readLines = 0;
        while (readLines < R) {
            string line;
            getline(cin, line);
            if (line.empty()) continue; // 빈 줄은 무시
            for (int j = 0; j < C; ++j) {
                N[i][readLines][j] = line[j];
                if (line[j] == 'S') {
                    dist[i][readLines][j] = 1;
                    q.push({i, readLines, j});
                }
            }
            readLines++;
        }
    }
    return true;
}

void solution() {
    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        if (N[cur.x][cur.y][cur.z] == 'E') {
            cout << "Escaped in " << dist[cur.x][cur.y][cur.z] - 1 << " minute(s)." << '\n';
            return;
        }

        for (int dir = 0; dir < 6; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];

            if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C)
                continue;
            if (N[nx][ny][nz] == '#' || dist[nx][ny][nz] != 0)
                continue;

            dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
            q.push({nx, ny, nz});
        }
    }
    cout << "Trapped!" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        if (!input()) break;
        solution();
    }

    return 0;
}
