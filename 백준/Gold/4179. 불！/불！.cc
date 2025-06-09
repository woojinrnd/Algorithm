#include <iostream>
#include <queue>

using namespace std;

int n, m;
char N[1002][1002];
int dist1[1002][1002]; // fire
int dist2[1002][1002]; // jihoon
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
queue<point> q1; // fire
queue<point> q2; // jihoon
int res;

void input() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> N[i][j];
            if (N[i][j] == 'F') {
                dist1[i][j] = 1;
                q1.push({i, j});
            }
            else if (N[i][j] == 'J') {
                dist2[i][j] = 1;
                q2.push({i, j});
            }
        }
    }
}

void solution() {
    // FIRE BFS
    while(!q1.empty()) {
        point cur = q1.front();
        q1.pop();
        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (N[nx][ny]=='#'||dist1[nx][ny]>0) continue;
            dist1[nx][ny] = dist1[cur.x][cur.y]+1;
            q1.push({nx, ny});
        }
    }

    // JIHOON BFS
    while(!q2.empty()) {
        point cur = q2.front();
        q2.pop();
        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            // 탈출
            if (nx<0||nx>=n||ny<0||ny>=m) {
                res = dist2[cur.x][cur.y];
                cout << res;
                return ;
            }
            if (N[nx][ny]=='#'||dist2[nx][ny]>0) continue;
            if (dist1[nx][ny]>0 && dist1[nx][ny]<=dist2[cur.x][cur.y]+1) continue;
            dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
            q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
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