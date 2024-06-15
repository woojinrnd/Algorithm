#include <iostream>
#include <queue>

using namespace std;

int n, m;
char N[1001][1001];
bool vist[1001][1001][2]; // [x][y][wall]
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
    int wall_cnt;
    int cur_cnt;
};

void input() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> N[i][j];
        }
    }
}

int bfs() {
    // BFS Starting Point
    queue<point> Q;
    vist[0][0][0] = 1;
    Q.push({0, 0, 0, 1});
    
    while(!Q.empty()) {
        point cur = Q.front();
        Q.pop();

        // If Arrive
        if (cur.x == n-1 && cur.y == m-1) {
            return cur.cur_cnt;
        }

        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            // 범위안에 있다면
            if (nx>=0&&nx<n&&ny>=0&&ny<m) {
                // 벽을 만났고, 아직 벽을 부수지 않은 상태라면
                if (N[nx][ny]=='1' && cur.wall_cnt==0) {
                    vist[nx][ny][cur.wall_cnt+1] = 1;
                    Q.push({nx, ny, cur.wall_cnt+1, cur.cur_cnt+1});
                }
                // 벽이 아니고, 아직 방문하지 않았다면
                if (N[nx][ny]=='0' && vist[nx][ny][cur.wall_cnt]==0) {
                    vist[nx][ny][cur.wall_cnt] = 1;
                    Q.push({nx, ny, cur.wall_cnt, cur.cur_cnt+1});
                }
            }            
        }
    }
    return -1;
}

void solution() {
    int res = bfs();
    cout << res << '\n';
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}