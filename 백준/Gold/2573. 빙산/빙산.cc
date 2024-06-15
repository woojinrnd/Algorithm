#include <iostream>
#include <queue>

using namespace std;

int n, m;
int N[301][301];
int N2[301][301];
bool vist[301][301];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};

void input() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> N[i][j];
        }
    }
}

void bfs(int a, int b) {
    queue<point> q;
    vist[a][b] = 1;
    q.push({a, b});

    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (N[nx][ny]==0||vist[nx][ny]) continue;
            vist[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

// 상하좌우 바다의 수 count
int melt(int x, int y) {
    int cnt = 0;
    for (int dir=0; dir<4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (N[nx][ny]==0) cnt++;
    }
    return cnt;
}

void initialize() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            N2[i][j] = 0;
            vist[i][j] = 0;
        }
    }
}

void solution() {
    int year = 0;
    while(1) {
        int land_cnt = 0;
        initialize();
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (N[i][j]==0||vist[i][j]) continue;
                land_cnt++;
                bfs(i, j);
            }
        }
        if (land_cnt>=2) {
            cout << year << '\n';
            break;
        }
        if (land_cnt==0) {
            cout << 0 << '\n';
            break;
        }

        // Melting and save result N2
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (N[i][j] == 0) continue;
                N2[i][j] = N[i][j] - melt(i, j);
                if (N2[i][j]<0) N2[i][j] = 0;
            }
        }

        //Copy done result
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                N[i][j] = N2[i][j];
            }
        }
        year++;
    }
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