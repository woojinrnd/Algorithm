#include <iostream>
#include <queue>

using namespace std;

struct point {
    int x, y;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N[51][51] = {0}; 
        int vist[51][51] = {0};
        int n = 0;
        int m = 0;
        int k = 0;
        int cnt = 0;
        cin >> m >> n >> k;

        // 초기화
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                N[i][j] = 0;
                vist[i][j] = 0;
            }
        }

        while (k--) {
            int y, x;
            cin >> x >> y;
            N[y][x] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (N[i][j] == 0 || vist[i][j]) continue;
                queue<point> Q;
                Q.push({i, j});
                vist[i][j] = 1;
                cnt++;
                while (!Q.empty()) {
                    point cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vist[nx][ny] || N[nx][ny] == 0) continue;
                        vist[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
