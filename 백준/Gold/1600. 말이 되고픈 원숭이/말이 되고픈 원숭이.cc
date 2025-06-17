#include <iostream>
#include <queue>
using namespace std;

int k; // night move cnt
int n, m;
int N[202][202];
int dist[202][202][31]; // [x][y][k_used]
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ddx[] = {1, -1, 2, -2, 2, -2, 1, -1};
int ddy[] = {2, 2, 1, 1, -1, -1, -2, -2};

struct point {
    int x, y;
    int k;
};

void input() {
    cin >> k;
    cin >> m >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            cin >> N[i][j];
}

void solution() {
    queue<point> q;
    dist[0][0][0] = 1;  // 시작 위치: 거리 1로 설정
    q.push({0, 0, 0});

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        // 일반 이동
        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (N[nx][ny]==1||dist[nx][ny][cur.k]!=0) continue;
            dist[nx][ny][cur.k] = dist[cur.x][cur.y][cur.k]+1;
            q.push({nx, ny, cur.k});
        }

        // 말 이동
        if (cur.k < k) {
            for (int dir=0; dir<8; ++dir) {
                int nx = cur.x + ddx[dir];
                int ny = cur.y + ddy[dir];
                if (nx<0||nx>=n||ny<0||ny>=m) continue;
                if (N[nx][ny]==1||dist[nx][ny][cur.k+1]!=0) continue;
                dist[nx][ny][cur.k+1] = dist[cur.x][cur.y][cur.k] + 1;
                q.push({nx, ny, cur.k+1});
            }
        }
    }

    int ans = -1;
    for (int i=0; i<=k; ++i) {
        if (dist[n-1][m-1][i]==0) continue;
        if (ans==-1 || dist[n-1][m-1][i]<ans) {
            ans = dist[n-1][m-1][i];
        }
    }

    if (ans != -1) cout << ans - 1 << '\n';
    else cout << -1 << '\n';
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
