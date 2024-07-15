#include <iostream>
#include <queue>

using namespace std;

#define MAX 100000+1

int n, k;
bool vist[MAX];
int dx[] = {-1, 1};
struct point {
    int x;
    int time;
};

void input() {
    cin >> n >> k;
}

void bfs(int a) {
    queue<point> q;
    vist[a] = true;
    q.push({a, 0});

    while(!q.empty()) {
        point cur = q.front();
        q.pop();

        if (cur.x == k) {
            cout << cur.time << '\n';
            return ;
        }
        
        for (int dir=0; dir<2; ++dir) {
            int nx = cur.x + dx[dir];
            if (nx<0||nx>=MAX) continue;
            if (vist[nx]) continue;
            vist[nx] = true;
            q.push({nx, cur.time+1});
        }
        if (cur.x*2<MAX&&!vist[cur.x*2]) {
            vist[cur.x*2] = true;
            q.push({cur.x*2, cur.time+1});
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