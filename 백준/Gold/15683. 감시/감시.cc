#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int N[10][10];
int ans = 10e9;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
vector<point> cctv;

void input() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> N[i][j];
            if (N[i][j] !=0 && N[i][j] != 6) {
                cctv.push_back({i, j});
            }
        }
    }
}

void check(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx<0||nx>=n||ny<0||ny>=m) return ;
        if (N[nx][ny] == 6) return ;
        if (N[nx][ny] != 0) continue;
        N[nx][ny] = -1;
    }
}

void dfs(int idx) {
    // Return condition
    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!N[i][j]) cnt++;
            }
        }
        ans = min(ans, cnt);
        return ;
    }

    int x = cctv[idx].x;
    int y = cctv[idx].y;

    for (int dir=0; dir<4; ++dir) {
        int tmp[10][10];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                tmp[i][j] = N[i][j];
            }
        }

        if (N[x][y] == 1) {
            check(x, y, dir);
        }
        else if (N[x][y] == 2) {
            check(x, y, dir);
            check(x, y, dir+2);
        }
        else if (N[x][y] == 3) {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (N[x][y] == 4) {
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
        }
        else if (N[x][y] == 5) {
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
            check(x, y, dir+3);
        }

        dfs(idx + 1);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                N[i][j] = tmp[i][j];
            }
        }
    }
}

void solution() {
    dfs(0);
    cout << ans << '\n';
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