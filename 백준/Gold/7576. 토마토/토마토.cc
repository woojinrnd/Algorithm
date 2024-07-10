#include <iostream>
#include <queue>

using namespace std;

int n, m;
int N[1002][1002];
int dist[1002][1002];
int dx[] = {1, 0, -1 ,0};
int dy[] = {0, 1, 0 , -1};
struct point {
    int x, y;
};
int answer = 0;

queue<point> q;

void input() {
    cin >> m >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> N[i][j];
            // 익은 토마토를 기준으로 bfs start
            // 방문 표시
            if (N[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
            // 익지 않은 토마토는 탐색 필요구간
            else if (N[i][j] == 0) {
                dist[i][j] = -1;
            }
            else {
                dist[i][j] = -1;
            }
        }
    }
}

void solution() {
    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (N[nx][ny]==-1 || dist[nx][ny]>=0) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }

    // 최소 일수 구하기
    // 모두 익지 못한다면, -1
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (dist[i][j]==-1 && N[i][j]==0) {
                answer = -1;
                // cout << -1 << '\n';
                return ;
            }
            else {
                if (answer < dist[i][j]) {
                    answer = dist[i][j];
                }
            }
        }
    }
}

void show() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    input();
    solution();
    // show();
    cout << answer << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
