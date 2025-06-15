#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int N[102][102];
int dist[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
int cnt;
int area[100000];

void input() {
    cin >> m >> n >> k;
    while(k--) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        int new_y1 = m - y2;
        int new_y2 = m - y1;
        for (int i=new_y1; i<new_y2; ++i) {
            for (int j=x1; j<x2; ++j) {
                N[i][j] = 1;
            }
        }
    }
}

void solution() {
    // BFS Start : (i, j)
    // 탐색 구간 : N[i][j] = 0 || 방문x
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (N[i][j] == 1 || dist[i][j]>0) continue;
            queue<point> q;
            dist[i][j] = 1;
            q.push({i, j});
            cnt++;
            while(!q.empty()) {
                point cur = q.front();
                q.pop();
                area[cnt]++;
                for(int dir=0; dir<4; ++dir) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx<0||nx>=m||ny<0||ny>=n) continue;
                    if (N[nx][ny]==1||dist[nx][ny]>0)continue;
                    dist[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << '\n';
    sort(area+1, area+cnt+1);
    for (int i=1; i<=cnt; ++i) {
        cout << area[i] << ' ';
    }
}

void show() {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cout << N[i][j] << ' ';
            // cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    input();
    solution();
    // show();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}