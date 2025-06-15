#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int F, S, G, U, D;
int dist[1000001]; // 거리(버튼 누른 횟수)

void input() {
    cin >> F >> S >> G >> U >> D;
    fill(dist, dist + F + 1, -1); // -1: 방문 안 함
}

void bfs(int start) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int dir : {U, -D}) {
            int nx = cur + dir;
            if (nx < 1 || nx > F) continue;
            if (dist[nx] != -1) continue;

            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    if (dist[G] == -1)
        cout << "use the stairs\n";
    else
        cout << dist[G] << '\n';
}

void solve() {
    input();
    bfs(S);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
