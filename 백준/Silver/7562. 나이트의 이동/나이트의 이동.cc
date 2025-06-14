#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int Tc, n;
int N[300][300];
bool vist[300][300];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
struct point {
    int x, y;
    int time;
};
point start, finish;

void init() {
    start = point({0, 0});
    finish = point({0, 0});
    memset(vist, false, sizeof(vist));
}

void input() {
    cin >> n;
    cin >> start.x >> start.y;
    cin >> finish.x >> finish.y;
}

void bfs(int x, int y) {
    queue<point> q;
    vist[x][y] = true;
    q.push({x, y, 0});

    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int dir=0; dir<8; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (cur.x == finish.x && cur.y == finish.y) {
                cout << cur.time << '\n';
                return ;
            }
            if (nx<0||nx>=n||ny<0||ny>=n) continue;
            if (vist[nx][ny]) continue;
            vist[nx][ny] = true;
            q.push({nx, ny, cur.time+1});
        }
    }
}

void solution() {
    bfs(start.x, start.y);
}

void solve() {
    cin >> Tc;
    for (int i=0; i<Tc; ++i) {
        init();
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