#include <iostream>
#include <queue>

using namespace std;

int n;
char N[103][103];
bool vist[103][103];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
int ans1, ans2;

void input() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> N[i][j];
        }
    }
}

void bfs(int x, int y) {
    queue<point> q;
    vist[x][y] = true;
    q.push({x, y});

    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=n) continue;
            if (N[nx][ny]!=N[cur.x][cur.y]||vist[nx][ny]) continue;
            vist[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int countArea() {
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (!vist[i][j]) {
                vist[i][j] = true;
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

void solution() {
    ans1 = countArea(); // 정상
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            vist[i][j] = false;
            if (N[i][j] == 'G') N[i][j] = 'R';
        }
    }
    ans2 = countArea();

    cout << ans1 << ' ' << ans2 << '\n';
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

