#include <iostream>
#include <queue>

using namespace std;

int r, c;
char N[1002][1002];
int dist1[1002][1002]; // FIRE
int dist2[1002][1002]; // JIHOON
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
queue<point> F;
queue<point> J;

void input() {
    cin >> r >> c;
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            cin >> N[i][j];
            if (N[i][j] == 'F') {
                dist1[i][j] = 1;
                F.push({i, j});
            }
            else if (N[i][j] == 'J') {
                dist2[i][j] = 1;
                J.push({i, j});
            }
        }
    }
}

void solution() {
    while(!F.empty()) {
        point cur = F.front();
        F.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx<0||nx>=r||ny<0||ny>=c) continue;
            if (N[nx][ny]=='#'||dist1[nx][ny]>0) continue;
            dist1[nx][ny] = dist1[cur.x][cur.y]+1;
            F.push({nx, ny});
        }
    }

    while(!J.empty()) {
        point cur = J.front();
        J.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            // Escape
            if (nx<0||nx>=r||ny<0||ny>=c) {
                cout << dist2[cur.x][cur.y];
                return ;
            }
            if (N[nx][ny]=='#'||dist2[nx][ny]>0) continue;
            if (dist1[nx][ny]>0 && dist1[nx][ny]<=dist2[cur.x][cur.y]+1) continue;
            dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
            J.push({nx, ny});
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

