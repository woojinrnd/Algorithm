#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 100005

int n, k;
int vist[MAX_SIZE];
int dx[] = {-1, 1};
struct point {
    int x, time;
};

void input() {
    cin >> n >> k;
}

void bfs(int x) {
    // BFS Starting point
    queue<point> q;
    q.push({x, 0});
    vist[x] = 1;

    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        // Find Little, return time
        if (cur.x == k) {
            cout << cur.time << '\n';
            return ;
        }

        // move 2*x, time keeping
        if (cur.x*2 < MAX_SIZE && !vist[cur.x*2]) {
            vist[cur.x * 2] = 1;
            q.push({cur.x*2, cur.time});
        }

        // move -1, +1, time+1
        for (int dir=0; dir<2; ++dir) {
            int nx = cur.x + dx[dir];
            if (nx<0||nx>=MAX_SIZE) continue;
            if (vist[nx]) continue;
            vist[nx] = 1;
            q.push({nx, cur.time+1});
        }
    }
}

void solution() {
    bfs(n);
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