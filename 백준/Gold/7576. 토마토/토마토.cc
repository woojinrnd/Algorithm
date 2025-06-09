#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int N[1002][1002];
int dist[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
queue<point> q;

void input() {
    cin >> m >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> N[i][j];
            if (N[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
            else {
                dist[i][j] = -1;
            }
        }
    }
}

void solution() {
    while (!q.empty()) {
        point cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (N[nx][ny] != 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }

    int max_days = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (N[i][j] == 0 && dist[i][j] == -1) {
                cout << -1;
                return;
            }
            max_days = max(max_days, dist[i][j]);
        }
    }

    cout << max_days;
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