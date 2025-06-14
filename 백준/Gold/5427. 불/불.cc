#include <iostream>
#include <queue>

using namespace std;

int T;
int w, h;
char N[1002][1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
queue<point> F;
queue<point> J;

void input() {
    cin >> w >> h;
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cin >> N[i][j];

            // FIRE
            if (N[i][j] == '*') {
                dist1[i][j] = 1;
                F.push({i, j});
            }
            // JIHOON
            if (N[i][j] == '@') {
                dist2[i][j] = 1;
                J.push({i, j});
            }
        }
    }
}

void initialize() {
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            dist1[i][j] = dist2[i][j] = 0;
        }
    }
    F = queue<point>();
    J = queue<point>();
}

void solution() {
    //FIRE
    while(!F.empty()) {
        point cur = F.front();
        F.pop();
        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx<0||nx>=h||ny<0||ny>=w) continue;
            if (N[nx][ny]=='#'||dist1[nx][ny]>0) continue;
            dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
            F.push({nx, ny});
        }
    }

    // JIHOON
    while(!J.empty()) {
        point cur = J.front();
        J.pop();
        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx<0||nx>=h||ny<0||ny>=w) {
                cout << dist2[cur.x][cur.y] << '\n';
                return;
            }
            if (N[nx][ny]=='#'||dist2[nx][ny]>0) continue;
            if (dist1[nx][ny]>0&&dist1[nx][ny]<=dist2[cur.x][cur.y]+1) continue;
            dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
            J.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

void solve() {
    cin >> T;
    while(T--) {
        initialize();
        input();
        solution();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}