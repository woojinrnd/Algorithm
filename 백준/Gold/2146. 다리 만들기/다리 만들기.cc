#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int N[100][100][2];
int dist[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};
int area;

void input() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> N[i][j][0];
        }
    }
}

void initialize() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            dist[i][j] = 0;
        }
    }
}

// 육지 라벨링
void FillArea() {
    // bfs start (i, j)
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (N[i][j][0]==0||dist[i][j]!=0) continue;
            queue<point> q;
            dist[i][j] = 1;
            q.push({i, j});
            area++;
            N[i][j][1] = area;
            while(!q.empty()) {
                point cur = q.front();
                q.pop();
                for (int dir=0; dir<4; ++dir) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx<0||nx>=n||ny<0||ny>=n) continue;
                    if (N[nx][ny][0]==0||dist[nx][ny]!=0) continue;
                    dist[nx][ny] = 1;
                    N[nx][ny][1] = area;
                    q.push({nx, ny});
                }
            }
        }
    }
}

// 섬들 사이의 최단 거리 찾기
// 1. 육지에서 바다와 인접한 요소 찾기
// 2. A육지 B육지 최소 거리 구하기
// 3. 반복 횟수 : 육지 라벨 수
int bfs_to_other_island(int label) {
    queue<point> q;
    int local_dist[100][100];
    memset(local_dist, -1, sizeof(local_dist));

    // 1. 현재 섬의 가장자리만 큐에 넣기
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (N[i][j][1] == label) {
                for (int dir=0; dir<4; ++dir) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx<0||nx>=n||ny<0||ny>=n) continue;
                    if (N[nx][ny][0] == 0) {
                        local_dist[i][j] = 0;
                        q.push({i, j});
                        break;
                    }
                }
            }
        }
    }

    // 2. BFS로 바다 확장
    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=n) continue;
            if (N[nx][ny][1] == label) continue;
            if (local_dist[nx][ny]!=-1) continue;

            if (N[nx][ny][0] == 0) {
                local_dist[nx][ny] = local_dist[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
            else {
                return local_dist[cur.x][cur.y];
            }
        }
    }
    return 1e9;
}

void show() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << N[i][j][1] << ' ';
        }
        cout << '\n';
    }
}

void solution() {
    FillArea();
    int ans = 1e9;
    for (int i=1; i<=area; ++i) {
        ans = min(ans, bfs_to_other_island(i));
    }

    cout << ans << '\n';
}

void solve() {
    input();
    solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}