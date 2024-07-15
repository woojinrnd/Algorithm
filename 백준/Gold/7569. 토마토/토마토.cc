#include <iostream>
#include <queue>
using namespace std;

int h, n, m; // 높이 세로 가로
int N[100][100][100];
int dist[100][100][100];
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
struct point {
    int x, y, z;
};
int day;
queue<point> q;

void input() {
    cin >> m >> n >> h;
    for (int i=0; i<h; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<m; ++k) {
                cin >> N[i][j][k];
                if (N[i][j][k]==1) {
                    q.push({j, k, i});
                    dist[i][j][k]=0;
                }
                else if (N[i][j][k]==0) {
                    dist[i][j][k] = -1;
                }
            }
        }
    }
}

void solution() {
    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int dir=0; dir<6; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];
            if (nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h) continue;
            if (dist[nz][nx][ny]>=0||N[nz][nx][ny]==-1) continue;
            dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
            q.push({nx, ny, nz});
        }
    }
}

void calc_day() {
    for (int i=0; i<h; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<m; ++k) {
                if (N[i][j][k]==0 && dist[i][j][k]==-1) {
                    day = -1;
                    return ;
                }
                day = max(day, dist[i][j][k]);
            }
        }
    }
}


void solve() {
    input();
    solution();
    calc_day();
    cout << day << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}