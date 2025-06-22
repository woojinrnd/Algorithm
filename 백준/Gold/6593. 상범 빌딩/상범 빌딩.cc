#include <iostream>
#include <queue>
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
int stop;
queue<point> q;

void input() {
    cin >> L >> R >> C;
    if (L==0 && R==0 && C==0) {
        stop = 1;
        return ;
    }
    for (int i=0; i<L; ++i) {
        for (int j=0; j<R; ++j) {
            for (int k=0; k<C; ++k) {
                cin >> N[i][j][k];
                
                // BFS Start
                if (N[i][j][k]=='S') {
                    dist[i][j][k] = 1;
                    q.push({i, j, k});
                }
            }
        }
    }
}

void solution() {
    while(!q.empty()) {
        point cur = q.front();
        q.pop();
        if (N[cur.x][cur.y][cur.z] == 'E') {
            cout << "Escaped in " << dist[cur.x][cur.y][cur.z] - 1 << " minute(s).\n";
            return ;
        }

        for (int dir=0; dir<6; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];
            if (nx<0||nx>=L||ny<0||ny>=R||nz<0||nz>=C) continue;
            if (N[nx][ny][nz]=='#'||dist[nx][ny][nz]>0) continue;
            dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
            q.push({nx, ny, nz});
        }
    }
    cout << "Trapped!" << '\n';
}

void initialize() {
    q = queue<point>();
    memset(N, 0, sizeof(N));
    memset(dist, 0, sizeof(dist));
}

void solve() {
    while(1) {
        initialize();
        input();
        if (stop == 1) break;
        solution();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}