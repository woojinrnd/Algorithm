#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000001

int F; // Total
int G; // Target
int S; // Now
int U, D; // Up, Down
int dist[MAX]; // dist[현재층] = 도달하는데 걸리는 수

void input() {
    cin >> F >> S >> G >> U >> D;
}

void bfs(int x) {
    queue<int> q;
    dist[x] = 1;
    q.push(x);
    int dx[] = {U, -D};

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=0; i<2; ++i) {
            int nx = cur + dx[i];
            if (nx<1||nx>F||dist[nx]>0) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    if (dist[G] == 0) {
        cout << "use the stairs" << '\n';
    }
    else {
        cout << dist[G]-1 << '\n';
    }
}

void solve() {
    input();
    bfs(S);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}